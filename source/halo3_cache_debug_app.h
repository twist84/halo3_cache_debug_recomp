// halo3_cache_debug - ReXGlue Recompiled Project
//
// This file is yours to edit. 'rexglue migrate' will NOT overwrite it.
// Customize your app by overriding virtual hooks from rex::ReXApp.

#pragma once

#include <rex/rex_app.h>

#include <rex/dbg.h>
#include <rex/filesystem/devices/host_path_device.h>
#include <rex/filesystem/vfs.h>
#include <rex/graphics/flags.h>
#include <rex/input/flags.h>

class Halo3CacheDebugApp : public rex::ReXApp {
 public:
  using rex::ReXApp::ReXApp;

  static std::unique_ptr<rex::ui::WindowedApp> Create(
      rex::ui::WindowedAppContext& ctx) {
    return std::unique_ptr<Halo3CacheDebugApp>(new Halo3CacheDebugApp(ctx, "halo3_cache_debug",
        PPCImageConfig));
  }

protected:
	// Override virtual hooks for customization:
	// void OnPreSetup(rex::RuntimeConfig& config) override {}
	// void OnPostSetup() override {}
	// void OnCreateDialogs(rex::ui::ImGuiDrawer* drawer) override {}
	// void OnShutdown() override {}
	// void OnConfigurePaths(rex::PathConfig& paths) override {}

	void OnPreSetup(rex::RuntimeConfig& config) override;
	void OnLoadXexImage(std::string& xex_image) override;
	void OnPostSetup() override;
	void OnConfigurePaths(rex::PathConfig& paths) override;
};

// BLAM!

void Halo3CacheDebugApp::OnPreSetup(rex::RuntimeConfig& config)
{
	REXCVAR_SET(allow_game_relative_writes, true);
	REXCVAR_SET(gpu_allow_invalid_fetch_constants, true);
	REXCVAR_SET(input_backend, "xinput");
	//REXCVAR_SET(fullscreen, true);
	//REXCVAR_SET(vsync, false);
	//REXCVAR_SET(resolution_scale, 2);
}

void Halo3CacheDebugApp::OnLoadXexImage(std::string& xex_image)
{
	xex_image = "game:\\halo3_cache_debug.xex";
}

void Halo3CacheDebugApp::OnPostSetup()
{
	rex::Runtime* _runtime = rex::ReXApp::ReXApp::runtime();
	rex::filesystem::VirtualFileSystem* fs = _runtime->file_system();

	auto cache_device = std::make_unique<rex::filesystem::HostPathDevice>(
		"\\CACHE", _runtime->game_data_root(), false);
	if (!cache_device->Initialize())
	{
		REXFS_ERROR("Unable to scan cache path");
	}
	else
	{
		if (!fs->RegisterDevice(std::move(cache_device)))
		{
			REXFS_ERROR("Unable to register cache path");
		}
		else
		{
			fs->RegisterSymbolicLink("cache:", "\\CACHE");
		}
	}

	auto xstorage_device = std::make_unique<rex::filesystem::HostPathDevice>(
		"\\XSTORAGE", _runtime->game_data_root() / "xstorage", false);
	if (!xstorage_device->Initialize())
	{
		REXFS_ERROR("Unable to scan xstorage path");
	}
	else
	{
		if (!fs->RegisterDevice(
			std::move(xstorage_device)))
		{
			REXFS_ERROR("Unable to register xstorage path");
		}
		else
		{
			fs->RegisterSymbolicLink("xstorage:",
				"\\XSTORAGE");
		}
	}
}

void Halo3CacheDebugApp::OnConfigurePaths(rex::PathConfig& paths)
{
	if (!rex::debug::IsDebuggerAttached())
	{
		// for user deployments not a developer debugging
		paths.game_data_root = ".";
		paths.user_data_root = ".";
		paths.update_data_root = ".";
	}
}
