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
	enum BACKEND
	{
		BACKEND_NULL,
		BACKEND_OPENGL,
	};
	
	//Configuration structure
	struct CONFIG
	{
		//Backend to be used
		BACKEND backend = BACKEND_NULL;
		
		//Render configuration
		RENDER::CONFIG renderConfig;
	};
	
	//CuckyGameEngine instance class (holds all subsystems)
	class INSTANCE
	{
		private:
			//Error
			ERROR error;
			
			//Current configuration
			CONFIG config;
			
			//Sub-system interfaces
			CORE::INTERFACE_BASE *core = nullptr;
			RENDER::INTERFACE_BASE *render = nullptr;
			
		public:
			//Constructor and destructor
			INSTANCE(const CONFIG &_config);
			~INSTANCE();
			
			//Set configuration
			bool SetConfig(const CONFIG &_config);
			
			//Get sub-system interface pointers
			inline CORE::INTERFACE_BASE		*GetCore() const	{ return core; }
			inline RENDER::INTERFACE_BASE	*GetRender() const	{ return render; }
			
			//Get error
			inline ERROR GetError() const { return error; }
	};
}

//Include OpenGL backend subsystems
#ifdef CGE_COMPILE_OPENGL
	#include "OpenGL/Core.h"
	#include "OpenGL/Render.h"
#endif
