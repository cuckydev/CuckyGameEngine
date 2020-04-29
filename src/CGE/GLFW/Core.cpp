/*
Project: CuckyGameEngine

File: CGE/GLFW/Core.cpp
Purpose: Define the GLFW core subsystem class

Authors: Regan Green (cuckydev)
*/

//Libraries
#include <GLFW/glfw3.h>

//Declaration
#include "Core.h"

//Constructor and destructor
CGE::CORE::INTERFACE_GLFW::INTERFACE_GLFW()
{
	//Initialize GLFW
	if (!glfwInit())
		error.AddError("Failed to initialize GLFW");
}

CGE::CORE::INTERFACE_GLFW::~INTERFACE_GLFW()
{
	//Terminate GLFW
	glfwTerminate();
}
