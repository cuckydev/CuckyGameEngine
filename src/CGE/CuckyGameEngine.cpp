#include "CuckyGameEngine.h"

//Constructor and destructor
CGE::INSTANCE::INSTANCE(const CONFIG &_config)
{
	//Use the given config
	SetConfig(_config);
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
bool CGE::INSTANCE::SetConfig(const CONFIG &_config)
{
	//If backend is changed, recreate all sub-systems
	if (_config.backend != config.backend)
	{
		//Destroy previous sub-system instances
		if (core != nullptr)
			delete core;
		if (render != nullptr)
			delete render;
		
		//Create new sub-system instances
		switch (_config.backend)
		{
			case BACKEND_NULL:
				core = nullptr;
				render = nullptr;
				break;
			case BACKEND_GLFW:
				core = new CGE::CORE::INTERFACE_GLFW();
				render = new CGE::RENDER::INTERFACE_OPENGL(_config.renderConfig);
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
		
	}
	
	//Remember the given config
	config = _config;
	return error.Errored();
}
