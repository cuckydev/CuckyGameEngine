#pragma once

/*
Project: CuckyGameEngine

File: CGE/GLFW/Render.h
Purpose: Declare the GLFW render subsystem base class

Authors: Regan Green (cuckydev)
*/

//Base class
#include "../OpenGL/Render.h"

//CuckyGameEngine namespace
namespace CGE
{
	//Render namespace
	namespace RENDER
	{
		class INTERFACE_GLFW : public INTERFACE_OPENGL
		{
			private:
				
			public:
				//Constructor and destructor
				INTERFACE_GLFW(const CONFIG &_config);
				~INTERFACE_GLFW();
		};
	}
}
