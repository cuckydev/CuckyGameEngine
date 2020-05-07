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
CGE::Instance::Instance(const Config &config)
{
	//Use the given config
	SetConfig(config);
}

CGE::Instance::~Instance()
{
	//Delete all loaded sub-systems
	if (core != nullptr)
		delete core;
	if (render != nullptr)
		delete render;
}

//Set configuration
bool CGE::Instance::SetConfig(const Config &config)
{
	//If backend is changed, recreate all sub-systems
	if (config.backend != use_config.backend)
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
			case Backend::GLFW:
				core = new CGE::Core::Interface_GLFW();
				render = new CGE::Render::Interface_GLFW(config.render_config);
				break;
		#endif
			default:
				core = nullptr;
				render = nullptr;
				error.Push("An unsupported backend was selected");
				break;
		}
		
		//Check for sub-system creation errors
		if (core == nullptr)
			error.Push("Failed to create core sub-system instance");
		else if (core->GetError())
			error.Push(core->GetError());
			
		if (render == nullptr)
			error.Push("Failed to create render sub-system instance");
		else if (render->GetError())
			error.Push(render->GetError());
	}
	else
	{
		if (config.render_config != use_config.render_config)
		{
			if (render == nullptr)
				error.Push("Can't change configuration of null render sub-system instance");
			else
				render->SetConfig(config.render_config);
		}
	}
	
	//Remember the given config
	use_config = config;
	return (bool)error;
}
