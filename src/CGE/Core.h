#pragma once

/*
Project: CuckyGameEngine

File: Core.h
Purpose: Provide the core subsystem of the engine

Authors: Regan Green (cuckydev)
*/

#include <iostream>

//CuckyGameEngine namespace
namespace CGE
{
	//Core namespace
	namespace CORE
	{
		//Core interface base class
		class INTERFACE
		{
			public:
				//Destructor
				virtual ~INTERFACE() {};
				
				//Core interface
				virtual bool Initialize() = 0;
				virtual bool Quit() = 0;
		};
		
		//Backend classes
		#include "OpenGL/Core.h"
	}
}
