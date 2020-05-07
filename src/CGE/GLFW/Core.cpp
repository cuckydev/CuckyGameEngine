/*
Project: CuckyGameEngine

File: CGE/GLFW/Core.cpp
Purpose: Define the GLFW core subsystem class

Authors: Regan Green (cuckydev)
*/

//Library
#include <GLFW/glfw3.h>

//Declaration
#include "Core.h"

//Constructor and destructor
CGE::Core::Interface_GLFW::Interface_GLFW()
{
	//Initialize GLFW
	if (!glfwInit())
		error.Push("Failed to initialize GLFW");
}

CGE::Core::Interface_GLFW::~Interface_GLFW()
{
	//Terminate GLFW
	glfwTerminate();
}
