#pragma once

/*
Project: CuckyGameEngine

File: CGE/CuckyGameEngine.h
Purpose: Provide the CuckyGameEngine system to the user

Authors: Regan Green (cuckydev)
*/

//Standard library
#include <string>

//CuckyGameEngine classes
#include "Error.h"

//CuckyGameEngine sub-systems
#include "Core.h"
#include "Render.h"

//CuckyGameEngine namespace
namespace CGE
{
	//Backend enumeration
	enum Backend
	{
		NONE,
		GLFW,
	};
	
	//Configuration structure
	struct Config
	{
		//Backend to be used
		Backend backend;
		
		//Render configuration
		Render::Config render_config;
	};
	
	//CuckyGameEngine instance class (holds all subsystems)
	class Instance
	{
		private:
			//Error
			Error error;
			
			//Used configuration
			Config use_config;
			
			//Sub-system interfaces
			Core::Interface_Base *core = nullptr;
			Render::Interface_Base *render = nullptr;
			
		public:
			//Constructor and destructor
			Instance(const Config &config);
			~Instance();
			
			//Set configuration
			bool SetConfig(const Config &config);
			
			//Get sub-system interface pointers
			inline Core::Interface_Base		*GetCore() const	{ return core; }
			inline Render::Interface_Base	*GetRender() const	{ return render; }
			
			//Get error
			inline const Error &GetError() const { return error; }
	};
}
