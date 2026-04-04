/* ---------- headers */

#include "main/main.h"

#include "cache/restricted_memory_regions.h"
#include "cseries/cseries_windows.h"
#include "multithreading/synchronized_value.h"
#include "multithreading/threads.h"
#include "profiler/profiler.h"

#include "rex_macros.h"

/* ---------- constants */

/* ---------- definitions */

struct _main_globals
{
	bool startup_sequence_performed;
	bool halted_with_errors;
	bool run_xdemos;
	bool exit_game;
	bool save_core;
	bool load_core;
	char core_file_name[64];
	bool reset_map;
	bool reset_map_random_seed;
	bool revert_map;
	bool save_map;
	bool save_map_and_exit;
	bool skip_cinematic;
	bool prepare_to_switch_zone_set;
	volatile bool switch_zone_set;
	bool reverted_by_scripting;
	bool keep_playing_cinematic_outros_on_revert;
	bool ui_saving_files;
	bool byte_846AE4F1;
	bool modify_zone_activation;
	bool cheat_drop_tag;
	rex::be<long> switch_zone_set_index;
	rex::be<long> dword_828D7B20;
	rex::be<long> deactivating_designer_zone_mask;
	rex::be<long> cheat_drop_tag_index;
};
static_assert(sizeof(_main_globals) == 0x64);

/* ---------- prototypes */

static void main_loop_enter(void);
static void main_loop_exit(void);

/* ---------- globals */

REX_DATA_REFERENCE_DECLARE(0x83CE685C, bool, g_render_thread_user_setting);
REX_DATA_REFERENCE_DECLARE(0x846AE480, bool, disable_main_loop_throttle);
REX_DATA_REFERENCE_DECLARE(0x846AE481, bool, debug_no_drawing);
REX_DATA_REFERENCE_DECLARE(0x846AE482, bool, check_system_heap);
REX_DATA_REFERENCE_DECLARE(0x846AE483, bool, debug_trace_main_events);
REX_DATA_REFERENCE_DECLARE(0x846AE484, bool, g_force_upload_even_if_untracked);
REX_DATA_REFERENCE_DECLARE(0x846AE485, bool, g_fake_minidump_creation);
REX_DATA_REFERENCE_DECLARE(0x846AE486, bool, g_suppress_keyboard_for_minidump);
REX_DATA_REFERENCE_DECLARE(0x846AE487, bool, g_startup_watch);
REX_DATA_REFERENCE_DECLARE(0x846AE494, c_interlocked_long, g_render_thread_enabled);
REX_DATA_REFERENCE_DECLARE(0x846AE498, c_interlocked_long, g_single_thread_request_flags);
REX_DATA_REFERENCE_DECLARE(0x846AE49C, c_synchronized_long, ill_never_be_done);

/* ---------- private variables */

static REX_DATA_REFERENCE_DECLARE(0x846AE4A0, _main_globals, main_globals);

/* ---------- ppc */

// exports

REX_PPC_EXTERN_IMPORT(main_loop);
REX_PPC_EXTERN_IMPORT(main_loop_enter);
REX_PPC_EXTERN_IMPORT(main_loop_exit);
REX_PPC_EXTERN_IMPORT(main_loop_body_multi_threaded);
REX_PPC_EXTERN_IMPORT(main_loop_body_single_threaded);
REX_PPC_EXTERN_IMPORT(main_thread_process_pending_messages);
REX_PPC_EXTERN_IMPORT(main_halt_and_catch_fire);
REX_PPC_EXTERN_IMPORT(main_set_single_thread_request_flag);
REX_PPC_EXTERN_IMPORT(enable_render_thread);
REX_PPC_EXTERN_IMPORT(render_thread_enabled);
REX_PPC_EXTERN_IMPORT(trace_dump_process_thread_start);
REX_PPC_EXTERN_IMPORT(trace_dump_process_thread_stop);
REX_PPC_EXTERN_IMPORT(_internal_halt_render_thread_and_lock_resources);
REX_PPC_EXTERN_IMPORT(unlock_resources_and_resume_render_thread);

// hooks

/* ---------- public code */

void main_loop(void)
{
	main_loop_enter();

	restricted_region_unlock_primary(k_global_render_data_region);
	restricted_region_unlock_primary(k_game_state_render_region);

	long main_loop_index = 0;
	unsigned long previous_loop_time = system_milliseconds();

	unlock_token render_thread_lock_token;
	while (!main_globals.exit_game)
	{
		//PROFILER_SESSION_SCOPE(k_profile_session_main_loop, "[main_loop]", 0, "main_loop", 0);

		unsigned long current_loop_time = system_milliseconds();
		unsigned long loop_time_advance = current_loop_time - previous_loop_time;
		if (disable_main_loop_throttle || loop_time_advance >= 7)
		{
			profiler_notify_pulse(k_profiler_pulse_update_thread);

			previous_loop_time = current_loop_time;

			main_loop_index++;
			trace_dump_process_thread_start(k_thread_main);

			//PROFILER_BEGIN("main_loop", 0);

			main_set_single_thread_request_flag(_single_thread_for_user_request, !g_render_thread_user_setting);

			bool single_threaded_mode_active;
			if (render_thread_enabled())
			{
				single_threaded_mode_active = false;
				main_thread_process_pending_messages();
				main_loop_body_multi_threaded();
			}
			else
			{
				single_threaded_mode_active = true;
				main_thread_process_pending_messages();
				main_loop_body_single_threaded();
			}

			bool single_threaded_desired = g_single_thread_request_flags.peek() != 0;
			if (single_threaded_desired != single_threaded_mode_active)
			{
				if (single_threaded_mode_active)
				{
					unlock_resources_and_resume_render_thread(render_thread_lock_token);
				}
				else
				{
					render_thread_lock_token = _internal_halt_render_thread_and_lock_resources((char const*)0x1820B7324, 1095); // __FILE__, __LINE__
				}

				trace_dump_process_thread_stop(k_thread_main);
			}
		}
		else
		{
			//PROFILER_BEGIN("main_thread_sleep", 0);
			unsigned long sleepy_time = 7 - loop_time_advance;
			sleep(sleepy_time);
		}
	}

	enable_render_thread(false);
	restricted_region_lock_primary(k_game_state_render_region);
	restricted_region_lock_primary(k_global_render_data_region);

	main_loop_exit();
}

void main_loop_body_multi_threaded(void)
{
	REX_PPC_INVOKE(main_loop_body_multi_threaded);
}

void main_loop_body_single_threaded(void)
{
	REX_PPC_INVOKE(main_loop_body_single_threaded);
}

void main_thread_process_pending_messages(void)
{
	REX_PPC_INVOKE(main_thread_process_pending_messages);
}

void main_halt_and_catch_fire(void)
{
	REX_PPC_INVOKE(main_halt_and_catch_fire);
}

void main_set_single_thread_request_flag(e_single_threaded_request_flags flag, bool setting)
{
	REX_PPC_INVOKE(main_set_single_thread_request_flag, flag, setting);
}

bool enable_render_thread(bool enable)
{
	return REX_PPC_INVOKE(enable_render_thread, enable);
}

bool render_thread_enabled(void)
{
	return REX_PPC_INVOKE(render_thread_enabled);
}

void trace_dump_process_thread_start(e_registered_threads thread)
{
	REX_PPC_INVOKE(trace_dump_process_thread_start, thread);
}

void trace_dump_process_thread_stop(e_registered_threads thread)
{
	REX_PPC_INVOKE(trace_dump_process_thread_stop, thread);
}

unlock_token _internal_halt_render_thread_and_lock_resources(char const* file, long line)
{
	return REX_PPC_INVOKE(_internal_halt_render_thread_and_lock_resources, file, line);
}

void unlock_resources_and_resume_render_thread(unlock_token token)
{
	REX_PPC_INVOKE(unlock_resources_and_resume_render_thread, token);
}

/* ---------- private code */

static void main_loop_enter(void)
{
	REX_PPC_INVOKE(main_loop_enter);
}

static void main_loop_exit(void)
{
	REX_PPC_INVOKE(main_loop_exit);
}
