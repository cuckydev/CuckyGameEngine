/*
Project: CuckyGameEngine

File: CGE/GLFW/Render.cpp
Purpose: Define the GLFW render subsystem base class

Authors: Regan Green (cuckydev)
*/

//Libraries
#include <GL/glew.h>

//Standard library
#include <iostream>
#include <cmath>

//Declaration
#include "Render.h"

//Constructor and destructor
CGE::RENDER::INTERFACE_GLFW::INTERFACE_GLFW(const CGE::RENDER::CONFIG &config)
{
	//Use the given configuration
	SetConfig(config);
}

CGE::RENDER::INTERFACE_GLFW::~INTERFACE_GLFW()
{
	//Destroy current window
	if (window != nullptr)
		glfwDestroyWindow(window);
}

//Render interface
bool CGE::RENDER::INTERFACE_GLFW::SetConfig(const CGE::RENDER::CONFIG &config)
{
	//Get our primary monitor and video mode
	GLFWmonitor *monitor = glfwGetPrimaryMonitor();
	if (monitor == nullptr)
		return error.AddError("Failed to get primary monitor");
	
	const GLFWvidmode* mode = glfwGetVideoMode(monitor);
	if (mode == nullptr)
		return error.AddError("Failed to get primary monitor's video mode");
	
	unsigned long x, y, width, height;
	if (config.fullscreen)
	{
		//I don't think coordinate matters, but use monitor's dimensions
		x = 0;
		y = 0;
		width = mode->width;
		height = mode->height;
	}
	else
	{
		//Be centered and use given dimensions
		x = (mode->width + config.width) / 2;
		y = (mode->width + config.width) / 2;
		width = config.width;
		height = config.height;
		
		//Don't create attach to a monitor
		monitor = nullptr;
	}
	
	//Update window
	if (window == nullptr)
	{
		//Destroy previous window
		if (window != nullptr)
			glfwDestroyWindow(window);
		
		//Set window hints
		glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //OpenGL 3.3 core
		
		//Create our window
		if ((window = glfwCreateWindow(width, height, config.title.c_str(), monitor, nullptr)) == nullptr)
			return error.AddError("Failed to create GLFW window");
			
		//Initialize OpenGL (GLEW)
		glfwMakeContextCurrent(window);
		
		//Initialize GLEW
		GLenum glewError;
		if ((glewError = glewInit()) != GLEW_OK)
			return error.AddError(std::string((const char*)glewGetErrorString(glewError)));
	}
	else if (config.fullscreen != useConfig.fullscreen)
	{
		//Set window to use new dimensions and monitor
		glfwSetWindowMonitor(window, monitor, x, y, width, height, (config.framerate != 0) ? config.framerate : GLFW_DONT_CARE);
	}
	
	//Get how to do framerate limiting
	if (config.framerate != 0)
	{
		//Get if our framerate is a multiple of our monitor's refresh rate
		unsigned long vsyncMultiple;
		long double refreshIntegral;
		long double refreshFractional = std::modf((long double)mode->refreshRate / config.framerate, &refreshIntegral);
		
		if (refreshIntegral >= 1.0 && refreshFractional == 0.0)
			vsyncMultiple = (unsigned long)std::floor(refreshIntegral);
		else
			vsyncMultiple = 0;
			
		//Use VSync if VSync multiple has been found to be non-zero
		glfwSwapInterval(vsyncMultiple);
		useVSync = vsyncMultiple != 0;
	}
	else
	{
		//Use VSync, and don't care about the multiple
		glfwSwapInterval(1);
		useVSync = true;
	}
	
	//Use the given configuration
	useConfig = config;
	useConfig.width = width;
	useConfig.height = height;
	return false;
}

bool CGE::RENDER::INTERFACE_GLFW::Flip()
{
	glfwSwapBuffers(window);
	return false;
}
