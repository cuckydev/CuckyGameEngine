#pragma once

/*
Project: CuckyGameEngine

File: CGE/GLFW/Core.h
Purpose: Define the GLFW core subsystem class

Authors: Regan Green (cuckydev)
*/

//Libraries
#include <GL/glew.h>
#include <GLFW/glfw3.h>

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
				INTERFACE_GLFW()
				{
					//Initialize GLFW
					if (!glfwInit())
						error.AddError("Failed to initialize GLFW");
				}
				
				~INTERFACE_GLFW()
				{
					//Terminate GLFW
					glfwTerminate();
				}
		};
	}
}
