// halo3_cache_debug - ReXGlue Recompiled Project
//
// This file is yours to edit. 'rexglue migrate' will NOT overwrite it.
// Customize your app by overriding virtual hooks from rex::ReXApp.

#pragma once

#include <rex/rex_app.h>

#include <rex/dbg.h>

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
	void OnShutdown() override;
	void OnConfigurePaths(rex::PathConfig& paths) override;
};
