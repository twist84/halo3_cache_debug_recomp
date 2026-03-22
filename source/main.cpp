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

int microsoft_crt_report_hook(int report_type, char* message, int* return_value)
{
	(void)(report_type);
	(void)(message);
	(void)(return_value);

	REXCPU_ERROR("microsoft_crt_report_hook(report_type = {}, message = {}, return_value = ?)", report_type, message);

	return 1;
}
REX_PPC_HOOK(microsoft_crt_report_hook);

REX_DATA_REFERENCE_DECLARE(0x83E3BBBC, rex::be_i32, render_bloom_source);

bool cache_files_copy_fonts(void)
{
	{
		render_bloom_source = 0;
	}

	return true;
}
REX_PPC_HOOK(cache_files_copy_fonts);

void track_code_sections(void) { }
PPC_HOOK(sub_823E5CE0, track_code_sections);

void stack_walk_initialize(void) { }
REX_PPC_HOOK(stack_walk_initialize);
