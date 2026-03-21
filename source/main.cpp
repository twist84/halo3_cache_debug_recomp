// halo3_cache_debug - ReXGlue Recompiled Project
//
// This file is yours to edit. 'rexglue migrate' will NOT overwrite it.

#include "generated/halo3_cache_debug_config.h"
#include "generated/halo3_cache_debug_init.h"

#include "halo3_cache_debug_app.h"

REX_DEFINE_APP(halo3_cache_debug, Halo3CacheDebugApp::Create)

// BLAM!

#include "rex_macros.h"

REXCVAR_DEFINE_STRING(username, "User", "Rex/User", "override the users name");

namespace rex::kernel::xam
{
	extern ppc_u32_result_t XamUserGetName_entry(ppc_u32_t user_index, ppc_pchar_t buffer,
		ppc_u32_t buffer_len);
}

ppc_u32_result_t XUserGetName(ppc_u32_t user_index, ppc_pchar_t buffer,
	ppc_u32_t buffer_len)
{
	ppc_u32_result_t result;

	auto username = REXCVAR_GET(username);
	if (username[0] != 0)
	{
		rex::string::util_copy_truncating(buffer, username, std::min(buffer_len.value(), uint32_t(16)));

		// X_E_SUCCESS
		result = 0U;
	}
	else
	{
		result = rex::kernel::xam::XamUserGetName_entry(user_index, buffer, buffer_len);
	}
	return result;
}
REX_PPC_HOOK(XUserGetName);

#include <rex/ppc/function.h>

void track_code_sections(void)
{
}
PPC_HOOK(sub_823E5CE0, track_code_sections);

void stack_walk_initialize(void)
{
}
REX_PPC_HOOK(stack_walk_initialize);

void profiler_initialize_system(void)
{
}
REX_PPC_HOOK(profiler_initialize_system);

void events_initialize(void)
{
}
REX_PPC_HOOK(events_initialize);

void network_remote_reporting_initialize(void)
{
}
REX_PPC_HOOK(network_remote_reporting_initialize);

// Create a simple stub that does nothing
#define PPC_STUB2(subroutine)             \
  extern "C" PPC_FUNC(subroutine) {       \
    (void)base;                           \
    REXKRNL_WARN("{} STUB", #subroutine); \
  }

// Create a stub that returns a specific value
#define PPC_STUB_RETURN2(subroutine, value)                                               \
  extern "C" PPC_FUNC(subroutine) {                                                       \
    (void)base;                                                                           \
    REXKRNL_WARN("{} STUB - returning {:#x}", #subroutine, static_cast<uint32_t>(value)); \
    ctx.r3.u64 = (value);                                                                 \
  }

PPC_STUB2(sub_83C87810);
PPC_STUB2(sub_83C87840);
//PPC_STUB2(font_initialize);

PPC_STUB_RETURN2(sub_828BF480, true);

//void display_assert(const char* information, const char* file, long line, bool fatal)
//{
//}
//REX_PPC_HOOK(display_assert);

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
