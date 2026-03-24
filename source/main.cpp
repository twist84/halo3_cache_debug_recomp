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
PPC_STUB(rex_DmWalkLoadedModules);
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
PPC_STUB(rex_DmRegisterCommandProcessorEx);

//extern "C" PPC_WEAK_FUNC(rex_DmWalkLoadedModules)
//{
//	(void)base;
//	ctx.r3.u64 = 0x82DA0104;
//}

// REX

PPC_EXTERN_IMPORT(__imp___vsnprintf);
extern "C" PPC_FUNC(sub_82FBCCC0)
{
	__imp___vsnprintf(ctx, base);
}

PPC_EXTERN_IMPORT(__imp__sprintf);
extern "C" PPC_FUNC(sub_82FB82B0)
{
	__imp__sprintf(ctx, base);
}

// BLAM!

struct s_server_connect_info
{
	char ip[16]; // 0x0
	rex::be_u16 port; // 0x10
	char services_supported[200]; // 0x12
};
static_assert(sizeof(s_server_connect_info) == 0xDA);

REX_DATA_REFERENCE_DECLARE(0x83CE0FF4, rex::be_i32, x_link_status_override);
REX_DATA_REFERENCE_DECLARE(0x83E3BBBC, rex::be_i32, render_bloom_source);
REX_DATA_REFERENCE_DECLARE_ARRAY(0x83F61D40, s_server_connect_info, g_additional_raw_servers, 3);

REX_PPC_EXTERN_IMPORT(cache_files_copy_fonts);

int microsoft_crt_report_hook(int report_type, char* message, int* return_value);
bool cache_files_copy_fonts(void);
void track_code_sections(void);
void stack_walk_initialize(void);

REX_PPC_HOOK(microsoft_crt_report_hook);
REX_PPC_HOOK(cache_files_copy_fonts);
PPC_HOOK(sub_823E5CE0, track_code_sections);
REX_PPC_HOOK(stack_walk_initialize);

int microsoft_crt_report_hook(int report_type, char* message, int* return_value)
{
	(void)(report_type);
	(void)(message);
	(void)(return_value);

	REXCPU_ERROR("microsoft_crt_report_hook(report_type = {}, message = {}, return_value = ?)", report_type, message);

	return 1;
}

bool cache_files_copy_fonts(void)
{
	// REX_PPC_INVOKE(cache_files_copy_fonts);
	return true;
}

void track_code_sections(void)
{
}
void stack_walk_initialize(void)
{
	// PATCHES
	// $TODO give these a proper home
	{
		// fix bloom source
		render_bloom_source = 0;

		// override `XNetGetEthernetLinkStatus` to allow `transport_startup` to be called
		x_link_status_override = 1;

		// override last additional raw LSP server
		{
			// $TODO replace `127.0.0.1` with sunrise address
			strncpy_s(g_additional_raw_servers[2].ip, "127.0.0.1", 16);
			g_additional_raw_servers[2].port = 80;
			strncpy_s(g_additional_raw_servers[2].services_supported, "ttl,usr,shr,web,dbg", 200);
		}
	}
	// $IMPLEMENT
}
