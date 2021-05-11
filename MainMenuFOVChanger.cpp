#include "pch.h"
#include "MainMenuFOVChanger.h"
#include "CvarMacros.h"
//########################################################//
//hey!                                                    //
//Heres stuff I basically stole from lol                  //
//https://github.com/CinderBlocc/SettingsFileExamples     //
//https://github.com/CrunchyRL/MainMenuBackgroundChanger  //
//https://github.com/Martinii89/BakkesmodPluginTemplate   //
//########################################################//
BAKKESMOD_PLUGIN(MainMenuFOVChanger, "Changes the Main Menu FOV", plugin_version, PERMISSION_ALL)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

void MainMenuFOVChanger::onLoad()
{
	_globalCvarManager = cvarManager;
	cvarManager->log("Plugin loaded!");

	//Custom Slider stuff
	Component5_IntegerSlider = std::make_shared<int>(0);
	CVarWrapper Cvar_Component5 = cvarManager->registerCvar(CVAR_COMPONENT_5, "55", "Integer Slider Component for MainMenu FOV", true, true, 1, true, 170);
	Cvar_Component5.bindTo(Component5_IntegerSlider);
	Cvar_Component5.addOnValueChanged(std::bind(&MainMenuFOVChanger::Component5, this));
	cvarManager->registerNotifier("fov_custom", [&](std::vector<std::string> args) {
		cvarManager->executeCommand(CVAR_COMPONENT_5);
		}, "", 0);
	//Small FOV
	cvarManager->registerNotifier("fov_small", [&](std::vector<std::string> params) {fov_small(); }, "Sets the FOV small", PERMISSION_MENU);

	//Large FOV
	cvarManager->registerNotifier("fov_large", [&](std::vector<std::string> params) {fov_large(); }, "Sets the FOV large", PERMISSION_MENU);
	
	//Random FOV
	cvarManager->registerNotifier("fov_random", [&](std::vector<std::string> args) {fov_random(); }, "Sets a random fov", PERMISSION_MENU);

	//Normal FOV
	cvarManager->registerNotifier("fov_normal", [&](std::vector<std::string> args) {fov_normal(); }, "Sets the FOV back to normal", PERMISSION_MENU);
}

void MainMenuFOVChanger::onUnload()
{
	cvarManager->executeCommand("cl_mainmenu_fov 55");
}
void MainMenuFOVChanger::Component5()
{
	cvarManager->executeCommand("cl_mainmenu_fov " + std::to_string(*Component5_IntegerSlider));
}
void MainMenuFOVChanger::fov_small()
{
	cvarManager->executeCommand("cl_mainmenu_fov 1");
}
void MainMenuFOVChanger::fov_large()
{
	cvarManager->executeCommand("cl_mainmenu_fov 170");
}
void MainMenuFOVChanger::fov_random()
{
	cvarManager->executeCommand("cl_mainmenu_fov (1, 170)");
}
void MainMenuFOVChanger::fov_normal()
{
	cvarManager->executeCommand("cl_mainmenu_fov 55");
}
