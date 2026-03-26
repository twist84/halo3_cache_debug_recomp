// halo3_cache_debug - ReXGlue Recompiled Project
//
// This file is yours to edit. 'rexglue migrate' will NOT overwrite it.

#include "generated/halo3_cache_debug_config.h"
#include "generated/halo3_cache_debug_init.h"

#include "halo3_cache_debug_app.h"

REX_DEFINE_APP(halo3_cache_debug, Halo3CacheDebugApp::Create)

#include "rex_macros.h"

// XBDM

//REX_PPC_STUB(CAP_Enter_Function);
//REX_PPC_STUB(CAP_Exit_Function);
REX_PPC_STUB(DmQueryMemoryStatistics);
REX_PPC_STUB(DmCloseLoadedModules);
REX_PPC_STUB_RETURN(DmWalkLoadedModules, 0x82DA0104);
REX_PPC_STUB(DmGetXboxName);
REX_PPC_STUB(DmCloseNotificationSession);
REX_PPC_STUB(DmNotify);
REX_PPC_STUB(DmOpenNotificationSession);
REX_PPC_STUB(DmIsDebuggerPresent);
REX_PPC_STUB(DmCloseCommittedMemory);
REX_PPC_STUB(DmWalkCommittedMemory);
REX_PPC_STUB(DmSendNotificationString);
REX_PPC_STUB(DmRegisterCommandProcessor);
REX_PPC_STUB(DmCloseModuleSections);
REX_PPC_STUB(DmWalkModuleSections);
REX_PPC_STUB(DmCaptureStackBackTrace);
REX_PPC_STUB(DmSuspendThread);
REX_PPC_STUB(DmGetThreadList);
REX_PPC_STUB(DmResumeThread);
REX_PPC_STUB(DmGetThreadContext);
REX_PPC_STUB(DmGetThreadInfoEx);
REX_PPC_STUB(DmWalkLoadedModulesEx);
REX_PPC_STUB(DmGetMemory);
REX_PPC_STUB(DmTraceStartRecording);
REX_PPC_STUB(DmTraceStartRecordingFunction);
REX_PPC_STUB(DmTraceStopRecording);
REX_PPC_STUB(DmTraceSaveBuffer);
REX_PPC_STUB(DmTraceSetBufferSize);
REX_PPC_STUB_RETURN(DmRegisterCommandProcessorEx, 0);

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

// XAM

#include <rex/system/xsocket.h>
#include <winsock.h>

REX_PPC_EXTERN_IMPORT(connect);
REX_PPC_EXTERN_IMPORT(recv);

using namespace rex::system;

int native_connect(SOCKET s, const XSOCKADDR *name, int namelen);
int native_recv(SOCKET s, uint8_t *buf, int len, int flags);

PPC_HOOK(rex_connect, native_connect);
PPC_HOOK(rex_recv, native_recv);

int native_connect(SOCKET s, const XSOCKADDR *name, int namelen)
{
	auto socket = kernel_state()->object_table()->LookupObject<XSocket>(s);
	if (!socket)
	{
		XThread::SetLastError(uint32_t(0x2736)); // X_WSAError::X_WSAENOTSOCK
		return -1;
	}

	N_XSOCKADDR address = name;

	rex::X_STATUS status = socket->Connect(&address, namelen);
	if (XFAILED(status)) // skip over for testing
	{
		//XThread::SetLastError(socket->GetLastWSAError());
		//return -1;
	}

	return 0;
}

int native_recv(SOCKET s, uint8_t *buf, int len, int flags)
{
	auto socket =
	kernel_state()->object_table()->LookupObject<XSocket>(s);
	if (!socket)
	{
		XThread::SetLastError(uint32_t(0x2736)); // X_WSAError::X_WSAENOTSOCK
		return -1;
	}

	int ret = socket->Recv(buf, len, flags);
	if (ret < 0)
	{
		//XThread::SetLastError(socket->GetLastWSAError());
	}
	return ret;
}

// BLAM!

enum e_session_network_message
{
	_network_message_network_interface_guide_opened = 0,
	_network_message_network_interface_guide_closed,
	_network_message_network_interface_connected,
	_network_message_network_interface_connection_lost,
	_network_message_connected_to_live,
	_network_message_lost_connection_to_live,
	_network_message_all_players_signed_out,
};

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
REX_PPC_EXTERN_IMPORT(network_session_interface_handle_message);
REX_PPC_EXTERN_IMPORT(hs_get_function_parameters_string);
REX_PPC_EXTERN_IMPORT(hs_get_function_documentation_string);

bool cache_files_copy_fonts(void);
void network_session_interface_handle_message(e_session_network_message message);
bool online_has_signed_in_user(long controller_index);
bool online_local_xuid_is_silver_or_gold_live(long controller_index);
bool online_local_xuid_is_online_enabled(long controller_index);
unsigned long long online_user_get_xuid(long controller_index);
void hs_doc(void);
static void hs_get_function_parameters_string(short function_index, char* buffer, long buffer_size);
static void hs_get_function_documentation_string(short function_index, char* buffer, long buffer_size);
static void stack_walk_with_context_internal(const struct s_file_reference* file, short levels_to_ignore, _CONTEXT* context_pointer, void* reference_ignore_address, long levels_to_walk, unsigned long* out_stack_walk_buffer, long* out_levels_walked);

REX_PPC_HOOK(cache_files_copy_fonts);
REX_PPC_HOOK(network_session_interface_handle_message);
REX_PPC_HOOK(online_has_signed_in_user);
REX_PPC_HOOK(online_local_xuid_is_silver_or_gold_live);
REX_PPC_HOOK(online_local_xuid_is_online_enabled);
REX_PPC_HOOK(online_user_get_xuid);
REX_PPC_HOOK(hs_doc)
REX_PPC_HOOK(stack_walk_with_context_internal);

long const g_additional_raw_server_index = 0;

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

			strncpy_s(g_additional_raw_servers[g_additional_raw_server_index].ip, raw_host, 16);
			g_additional_raw_servers[g_additional_raw_server_index].port = raw_port;
			strncpy_s(g_additional_raw_servers[g_additional_raw_server_index].services_supported, raw_services_supported, 200);
		}
	}
	//return REX_PPC_INVOKE(cache_files_copy_fonts);
	return true;
}

void network_session_interface_handle_message(e_session_network_message message)
{
	// LSP is locked behind `online_is_connected_to_live`, force it for now
	if (message == _network_message_network_interface_connected)
	{
		message = _network_message_connected_to_live;
	}

	REX_PPC_INVOKE(network_session_interface_handle_message, message);
}

bool online_has_signed_in_user(long controller_index)
{
	return controller_index == 0;
}

bool online_local_xuid_is_silver_or_gold_live(long controller_index)
{
	return controller_index == 0;
}

bool online_local_xuid_is_online_enabled(long controller_index)
{
	return controller_index == 0;
}

unsigned long long online_user_get_xuid(long controller_index)
{
	return controller_index == 0 ? 0x0000000555555555ULL : 0x0ULL;
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

static void stack_walk_with_context_internal(const struct s_file_reference* file, short levels_to_ignore, _CONTEXT* context_pointer, void* reference_ignore_address, long levels_to_walk, unsigned long* out_stack_walk_buffer, long* out_levels_walked)
{
	// skip stack walk for now
}
