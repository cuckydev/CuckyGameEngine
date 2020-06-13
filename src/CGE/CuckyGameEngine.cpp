/*
Project: CuckyGameEngine

File: CGE/CuckyGameEngine.cpp
Purpose: Define the CuckyGameEngine instance class

Authors: Regan "cuckydev" Green
*/

#include <CGE/CuckyGameEngine.h>

//Include SDL2 backend if used
#ifdef CGE_COMPILE_SDL2
	#include "SDL2/Core.h"
	#include "SDL2/Render.h"
#endif

//CuckyGameEngine namespace
namespace CGE
{
	//Constructor and destructor
	Instance::Instance(const Config &config)
	{
		//Use the given config
		SetConfig(config);
	}

	Instance::~Instance()
	{
		//Delete all loaded sub-systems
		if (core != nullptr)
			delete core;
		if (render != nullptr)
			delete render;
	}

	//Set configuration
	bool Instance::SetConfig(const Config &config)
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
			#ifdef CGE_COMPILE_SDL2
				case Backend::SDL2:
					core = new Core::Interface_SDL2();
					render = new Render::Interface_SDL2(config.render_config);
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
			//Update configuration of each sub-system
			if (config.render_config != use_config.render_config)
			{
				if (render == nullptr)
					error.Push("Can't set configuration of null render sub-system instance");
				else
					render->SetConfig(config.render_config);
			}
		}
		
		//Remember the given config
		use_config = config;
		return error;
	}
}
