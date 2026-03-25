// halo3_cache_debug - ReXGlue Recompiled Project
//
// This file is yours to edit. 'rexglue migrate' will NOT overwrite it.

#include "generated/halo3_cache_debug_config.h"
#include "generated/halo3_cache_debug_init.h"

#include "halo3_cache_debug_app.h"

REX_DEFINE_APP(halo3_cache_debug, Halo3CacheDebugApp::Create)

#include "rex_macros.h"

// XBDM

//PPC_STUB(rex_CAP_Enter_Function);
//PPC_STUB(rex_CAP_Exit_Function);
PPC_STUB(rex_DmQueryMemoryStatistics);
PPC_STUB(rex_DmCloseLoadedModules);
PPC_STUB_RETURN(rex_DmWalkLoadedModules, 0x82DA0104);
PPC_STUB(rex_DmGetXboxName);
PPC_STUB(rex_DmCloseNotificationSession);
PPC_STUB(rex_DmNotify);
PPC_STUB(rex_DmOpenNotificationSession);
PPC_STUB(rex_DmIsDebuggerPresent);
PPC_STUB(rex_DmCloseCommittedMemory);
PPC_STUB(rex_DmWalkCommittedMemory);
PPC_STUB(rex_DmSendNotificationString);
PPC_STUB(rex_DmRegisterCommandProcessor);
PPC_STUB(rex_DmCloseModuleSections);
PPC_STUB(rex_DmWalkModuleSections);
PPC_STUB(rex_DmCaptureStackBackTrace);
PPC_STUB(rex_DmSuspendThread);
PPC_STUB(rex_DmGetThreadList);
PPC_STUB(rex_DmResumeThread);
PPC_STUB(rex_DmGetThreadContext);
PPC_STUB(rex_DmGetThreadInfoEx);
PPC_STUB(rex_DmWalkLoadedModulesEx);
PPC_STUB(rex_DmGetMemory);
PPC_STUB(rex_DmTraceStartRecording);
PPC_STUB(rex_DmTraceStartRecordingFunction);
PPC_STUB(rex_DmTraceStopRecording);
PPC_STUB(rex_DmTraceSaveBuffer);
PPC_STUB(rex_DmTraceSetBufferSize);
PPC_STUB_RETURN(rex_DmRegisterCommandProcessorEx, 0);

// REX

#define PRINT_IMPORT_HELPER(name, print_name) \
	PPC_EXTERN_IMPORT(__imp__##print_name); \
	extern "C" PPC_FUNC(name) \
	{ \
		__imp__##print_name(ctx, base); \
	}

PRINT_IMPORT_HELPER(sub_82FBCCC0, _vsnprintf);
PRINT_IMPORT_HELPER(sub_82FB82B0, sprintf);

#undef PRINT_HOOK_HELPER

// BLAM!

struct s_server_connect_info
{
	char ip[16]; // 0x0
	rex::be_u16 port; // 0x10
	char services_supported[200]; // 0x12
};
static_assert(sizeof(s_server_connect_info) == 0xDA);

REXCVAR_DEFINE_INT32(x_link_status_override, -1, "Blam/Network", "")
	.lifecycle(rex::cvar::Lifecycle::kRequiresRestart);

REXCVAR_DEFINE_STRING(raw_host, "127.0.0.1", "Blam/Network", "")
	.lifecycle(rex::cvar::Lifecycle::kRequiresRestart);

REXCVAR_DEFINE_INT32(raw_port, 80, "Blam/Network", "")
	.range(1, UINT16_MAX)
	.lifecycle(rex::cvar::Lifecycle::kRequiresRestart);

REXCVAR_DEFINE_STRING(raw_services_supported, "ttl,usr,shr,web,dbg", "Blam/Network", "")
	.lifecycle(rex::cvar::Lifecycle::kRequiresRestart);

REX_DATA_REFERENCE_DECLARE(0x8216B12C, rex::be_i32 const, hs_function_table_count);

REX_DATA_REFERENCE_DECLARE(0x83CE0FF4, rex::be_i32, x_link_status_override);
REX_DATA_REFERENCE_DECLARE(0x83E3BBBC, rex::be_i32, render_bloom_source);
REX_DATA_REFERENCE_DECLARE_ARRAY(0x83F61D40, s_server_connect_info, g_additional_raw_servers, 3);

REX_PPC_EXTERN_IMPORT(cache_files_copy_fonts);
REX_PPC_EXTERN_IMPORT(hs_get_function_parameters_string);
REX_PPC_EXTERN_IMPORT(hs_get_function_documentation_string);

bool cache_files_copy_fonts(void);
void hs_doc(void);
static void hs_get_function_parameters_string(short function_index, char* buffer, long buffer_size);
static void hs_get_function_documentation_string(short function_index, char* buffer, long buffer_size);

REX_PPC_HOOK(cache_files_copy_fonts);
REX_PPC_HOOK(hs_doc)

bool cache_files_copy_fonts(void)
{
	// PATCHES
	// $TODO give these a proper home
	{
		// fix bloom source
		render_bloom_source = 0;

		// override `XNetGetEthernetLinkStatus` to allow `transport_startup` to be called
		x_link_status_override = REXCVAR_GET(x_link_status_override);

		// override last additional raw server
		{
			auto raw_host = REXCVAR_GET(raw_host).c_str();
			auto raw_port = static_cast<uint16_t>(REXCVAR_GET(raw_port));
			auto raw_services_supported = REXCVAR_GET(raw_services_supported).c_str();

			strncpy_s(g_additional_raw_servers[2].ip, raw_host, 16);
			g_additional_raw_servers[2].port = raw_port;
			strncpy_s(g_additional_raw_servers[2].services_supported, raw_services_supported, 200);
		}
	}
	//return REX_PPC_INVOKE(cache_files_copy_fonts);
	return true;
}

// rexglue doesn't handle ResolvePath("hs_doc.txt") correctly
// we fix it by implementing `hs_doc` directly
void hs_doc(void)
{
#define PRINTBUFFER_SIZE 2048

	REX_PPC_MEMBASE_PTR(base);
	REX_PPC_HEAP_ALLOC(char, printbuffer, PRINTBUFFER_SIZE);

	auto file_path = runtime->game_data_root() / "hs_doc.txt";

	FILE* file = nullptr;
	fopen_s(&file, file_path.string().c_str(), "w");
	if (file != nullptr)
	{
		for (long function_index = 0; function_index < hs_function_table_count; function_index++)
		{
			hs_get_function_parameters_string(static_cast<short>(function_index), printbuffer, PRINTBUFFER_SIZE);
			fprintf(file, "%s\r\n", printbuffer);
			hs_get_function_documentation_string(static_cast<short>(function_index), printbuffer, PRINTBUFFER_SIZE);
			fprintf(file, "%s\r\n\r\n", printbuffer);
		}
		fclose(file);
	}

	REX_PPC_HEAP_FREE(printbuffer);

#undef PRINTBUFFER_SIZE
}

static void hs_get_function_parameters_string(short function_index, char* buffer, long buffer_size)
{
	REX_PPC_INVOKE(hs_get_function_parameters_string, function_index, buffer, buffer_size);
}

static void hs_get_function_documentation_string(short function_index, char* buffer, long buffer_size)
{
	REX_PPC_INVOKE(hs_get_function_documentation_string, function_index, buffer, buffer_size);
}
