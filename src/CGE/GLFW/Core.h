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
	namespace CORE
	{
		class INTERFACE_GLFW : public INTERFACE_BASE
		{
			private:
				
			public:
				//Constructor and destructor
				INTERFACE_GLFW();
				~INTERFACE_GLFW();
		};
	}
}
