#pragma once

#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"

#include "version.h"
//########################################################//
//hey!                                                    //
//Heres stuff I basically stole from lol                  //
//https://github.com/CinderBlocc/SettingsFileExamples     //
//https://github.com/CrunchyRL/MainMenuBackgroundChanger  //
//https://github.com/Martinii89/BakkesmodPluginTemplate   //
//########################################################//


constexpr auto plugin_version = stringify(VERSION_MAJOR) "." stringify(VERSION_MINOR) "." stringify(VERSION_PATCH) "." stringify(VERSION_BUILD);


class MainMenuFOVChanger: public BakkesMod::Plugin::BakkesModPlugin/*, public BakkesMod::Plugin::PluginWindow*/
{
public: 
	std::shared_ptr<bool> enabled;

	//Boilerplate
	virtual void onLoad();
	virtual void onUnload();
	// Inherited via PluginWindow
	/*

	bool isWindowOpen_ = false;
	bool isMinimized_ = false;
	std::string menuTitle_ = "MainMenuFOVChanger";

	virtual void Render() override;
	virtual std::string GetMenuName() override;
	virtual std::string GetMenuTitle() override;
	virtual void SetImGuiContext(uintptr_t ctx) override;
	virtual bool ShouldBlockInput() override;
	virtual bool IsActiveOverlay() override;
	virtual void OnOpen() override;
	virtual void OnClose() override;
	
	*/
	
private:
	std::shared_ptr<int>  Component5_IntegerSlider;
	
public:
	void Component5();
	void fov_small();
	void fov_large();
	void fov_random();
	void fov_normal();
	
};

