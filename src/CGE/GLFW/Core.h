#pragma once

/*
Project: CuckyGameEngine

File: CGE/GLFW/Core.h
Purpose: Declare the GLFW core subsystem class

Authors: Regan Green (cuckydev)
*/

//Base class
#include "../Core.h"

//CuckyGameEngine namespace
namespace CGE
{
	//Render namespace
	namespace Core
	{
		class Interface_GLFW : public Interface_Base
		{
			public:
				//Constructor and destructor
				Interface_GLFW();
				~Interface_GLFW();
		};
	}
}
