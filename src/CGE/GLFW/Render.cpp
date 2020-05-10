/*
Project: CuckyGameEngine

File: CGE/GLFW/Render.cpp
Purpose: Define the GLFW render subsystem class

Authors: Regan Green (cuckydev)
*/

//Library
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Declaration
#include "Render.h"

//Constructor and destructor
CGE::Render::Interface_GLFW::Interface_GLFW(const Config &config)
{
	//Use the given configuration
	SetConfig(config);
}

CGE::Render::Interface_GLFW::~Interface_GLFW()
{
	//Destroy current window
	if (window != nullptr)
		glfwDestroyWindow(window);
}

bool CGE::Render::Interface_GLFW::SetConfig(const Config &config)
{
	//Get our primary monitor and video mode
	GLFWmonitor *monitor = glfwGetPrimaryMonitor();
	if (monitor == nullptr)
		return error.Push("Failed to get primary monitor");
	
	const GLFWvidmode* mode = glfwGetVideoMode(monitor);
	if (mode == nullptr)
		return error.Push("Failed to get primary monitor's video mode");
	
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
		//Set window hints
		glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //OpenGL 3.2 core
		
		//Create our window
		if ((window = glfwCreateWindow(width, height, config.title.c_str(), monitor, nullptr)) == nullptr)
			return error.Push("Failed to create GLFW window");
			
		//Initialize OpenGL context
		glfwMakeContextCurrent(window);
		
		//Initialize GLEW
		GLenum glewError;
		if ((glewError = glewInit()) != GLEW_OK)
			return error.Push(std::string((const char*)glewGetErrorString(glewError)));
		
		//Final check if OpenGL 3.2 is supported
		if (!GLEW_VERSION_3_2)
			return error.Push("OpenGL 3.2 not supported through GLEW");
	}
	else
	{
		//Update title
		glfwSetWindowTitle(window, config.title.c_str());
		
		//Update dimensions / fullscreen
		if (config.fullscreen != use_config.fullscreen)
			glfwSetWindowMonitor(window, monitor, x, y, width, height, (config.framerate != 0) ? config.framerate : GLFW_DONT_CARE);
		else
			glfwSetWindowSize(window, config.width, config.height);
	}
	
	//Get how to do framerate limiting
	if (config.framerate != 0)
	{
		//Get if our framerate is a multiple of our monitor's refresh rate
		unsigned long vsync_multiple;
		long double refresh_integral;
		long double refresh_fractional = std::modf((long double)mode->refreshRate / config.framerate, &refresh_integral);
		
		if (refresh_integral >= 1.0 && refresh_fractional == 0.0)
			vsync_multiple = (unsigned long)std::floor(refresh_integral);
		else
			vsync_multiple = 0;
			
		//Use VSync if VSync multiple has been found to be non-zero
		glfwSwapInterval(vsync_multiple);
		use_vsync = vsync_multiple != 0;
	}
	else
	{
		//Use VSync, and don't care about the multiple
		glfwSwapInterval(1);
		use_vsync = true;
	}
	
	//Use the given configuration
	use_config = config;
	use_config.width = width;
	use_config.height = height;
	return false;
}

bool CGE::Render::Interface_GLFW::Flip()
{
	//Wait if VSync is not being used
	if (use_vsync == 0)
	{
		//Wait for next frame
		auto now = std::chrono::high_resolution_clock::now();
		auto frameDuration = std::chrono::microseconds(1000000 / use_config.framerate);
		lim_time += frameDuration;
		if (now > lim_time + frameDuration * 10)
			lim_time = now; //Fix timer if out of sync
		else
			std::this_thread::sleep_until(lim_time);
	}
	
	//Swap buffers
	glfwSwapBuffers(window);
	return false;
}
