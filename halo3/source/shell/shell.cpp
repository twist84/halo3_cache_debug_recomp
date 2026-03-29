/* ---------- headers */

#include "shell/shell.h"

#include "cseries/async.h"
#include "cseries/cseries.h"
#include "cseries/runtime_state.h"
#include "input/input.h"
#include "main/game_preferences.h"
#include "math/real_math.h"
#include "networking/network_utilities.h"
#include "rasterizer/rasterizer.h"
#include "saved_games/game_state.h"
#include "sound/sound_manager.h"
#include "tag_files/tag_files.h"
#include "text/font_loading.h"

#include "rex_macros.h"

/* ---------- constants */

/* ---------- definitions */

/* ---------- prototypes */

/* ---------- globals */

/* ---------- private variables */

/* ---------- ppc */

// exports

REX_PPC_EXTERN_IMPORT(shell_halt_on_pure_virtual_call);
REX_PPC_EXTERN_IMPORT(shell_initialize);
REX_PPC_EXTERN_IMPORT(shell_dispose);

// hooks

//REX_PPC_HOOK(shell_initialize);
//REX_PPC_HOOK(shell_dispose);

/* ---------- public code */

void shell_halt_on_pure_virtual_call(void)
{
    REX_PPC_INVOKE(shell_halt_on_pure_virtual_call);
}

// $TODO move these
// =====================================================

REX_PPC_EXTERN_IMPORT(errors_initialize);
REX_PPC_EXTERN_IMPORT(events_initialize);
REX_PPC_EXTERN_IMPORT(minidump_compression_initialize);

void errors_initialize(void)
{
    REX_PPC_INVOKE(errors_initialize);
}

void events_initialize(void)
{
    REX_PPC_INVOKE(events_initialize);
}

void minidump_compression_initialize(void)
{
    REX_PPC_INVOKE(minidump_compression_initialize);
}

// =====================================================

bool shell_initialize(bool null_device)
{
    // $TODO investigate crash in `sound_initialize` when enabled

#if 1
    return REX_PPC_INVOKE(shell_initialize, null_device);
#else
    bool success;

    //_set_purecall_handler(&shell_halt_on_pure_virtual_call);
    //_CrtSetReportHook2(_CRT_RPTHOOK_INSTALL, microsoft_crt_report_hook);

    cseries_initialize();
    SYSTEM_DEBUG_MEMORY("after cseries_initialize()");

    //PROFILER_BEGIN("shell_initialize", 0);

    errors_initialize();
    SYSTEM_DEBUG_MEMORY("after errors_initialize()");

    events_initialize();
    SYSTEM_DEBUG_MEMORY("after events_initialize()");

    runtime_state_shell_initialize();
    SYSTEM_DEBUG_MEMORY("after runtime_state_shell_initialize()");

    if (shell_platform_initialize())
    {
        SYSTEM_DEBUG_MEMORY("after shell_platform_initialize()");

        real_math_initialize();
        SYSTEM_DEBUG_MEMORY("after real_math_initialize()");

        async_initialize();
        SYSTEM_DEBUG_MEMORY("after async_initialize()");

        network_remote_reporting_initialize();
        SYSTEM_DEBUG_MEMORY("after network_remote_reporting_initialize()");

        global_preferences_initialize();
        SYSTEM_DEBUG_MEMORY("after global_preferences_initialize()");

        font_initialize();
        SYSTEM_DEBUG_MEMORY("after font_initialize()");

        tag_files_open();
        SYSTEM_DEBUG_MEMORY("after tag_files_open()");

        game_state_shell_initialize();
        SYSTEM_DEBUG_MEMORY("after game_state_shell_initialize()");

        c_rasterizer::shell_initialize(false, null_device);
        SYSTEM_DEBUG_MEMORY("after rasterizer_initialize()");

        input_initialize();
        SYSTEM_DEBUG_MEMORY("after input_initialize()");

        sound_initialize();
        SYSTEM_DEBUG_MEMORY("after sound_initialize()");

        minidump_compression_initialize();
        SYSTEM_DEBUG_MEMORY("after minidump_compression_initialize()");

        success = true;

        shell_platform_verify();
    }
    else
    {
        success = false;
    }
    return success;
#endif
}

void shell_dispose(void)
{
#if 1
    REX_PPC_INVOKE(shell_dispose);
#else
    game_state_shell_dispose();
    //minidump_compression_dispose();
    sound_dispose();
    input_dispose();
    real_math_dispose();
    tag_files_close();
    //errors_dispose();
    //events_dispose();
    font_dispose();
    async_dispose();
    network_remote_reporting_dispose();
    shell_platform_dispose();
    runtime_state_shell_dispose();
    c_rasterizer::shell_dispose();
    cseries_dispose();
#endif
}

void shell_platform_verify(void)
{

}

/* ---------- private code */
