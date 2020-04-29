/*
Project: CuckyGameEngine

File: CGE/CuckyGameEngine.cpp
Purpose: Define the CuckyGameEngine instance class

Authors: Regan Green (cuckydev)
*/

#include "CuckyGameEngine.h"

//Include GLFW backend if used
#ifdef CGE_COMPILE_GLFW
	#include "GLFW/Core.h"
	#include "GLFW/Render.h"
#endif

//Constructor and destructor
CGE::INSTANCE::INSTANCE(const CONFIG &config)
{
	//Use the given config
	SetConfig(config);
}

CGE::INSTANCE::~INSTANCE()
{
	//Delete all loaded sub-systems
	if (core != nullptr)
		delete core;
	if (render != nullptr)
		delete render;
}

//Set configuration
bool CGE::INSTANCE::SetConfig(const CONFIG &config)
{
	//If backend is changed, recreate all sub-systems
	if (config.backend != useConfig.backend)
	{
		//Destroy previous sub-system instances
		if (core != nullptr)
			delete core;
		if (render != nullptr)
			delete render;
		
		//Create new sub-system instances
		switch (config.backend)
		{
		#ifdef CGE_COMPILE_GLFW
			case BACKEND_GLFW:
				core = new CGE::CORE::INTERFACE_GLFW();
				render = new CGE::RENDER::INTERFACE_GLFW(config.renderConfig);
				break;
		#endif
			default:
				core = nullptr;
				render = nullptr;
				error.AddError("An unsupported backend was selected");
				break;
		}
		
		//Check for sub-system creation errors
		if (core == nullptr)
			error.AddError("Failed to create core sub-system instance");
		else if (render->GetError().Errored())
			error.AddError(core->GetError());
			
		if (render == nullptr)
			error.AddError("Failed to create render sub-system instance");
		else if (render->GetError().Errored())
			error.AddError(render->GetError());
	}
	else
	{
		if (config.renderConfig != useConfig.renderConfig)
		{
			if (render == nullptr)
				error.AddError("Can't change configuration of null render sub-system instance");
			else
				render->SetConfig(config.renderConfig);
		}
	}
	
	//Remember the given config
	useConfig = config;
	return error.Errored();
}
