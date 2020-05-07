#pragma once

/*
Project: CuckyGameEngine

File: CGE/GLFW/Render.h
Purpose: Define the GLFW render subsystem base class

Authors: Regan Green (cuckydev)
*/

//Libraries
#include <GLFW/glfw3.h>

//Standard library
#include <chrono>
#include <thread>
#include <cmath>

//Base class
#include "../OpenGL/Render.h"

//CuckyGameEngine namespace
namespace CGE
{
	//Render namespace
	namespace Render
	{
		class Interface_GLFW : public Interface_OpenGL
		{
			private:
				//GLFW window
				GLFWwindow *window = nullptr;
				
				//Framerate limiter
				bool use_vsync;
				std::chrono::time_point<std::chrono::high_resolution_clock> lim_time;
				
			public:
				//Constructor and destructor
				Interface_GLFW(const Config &config);
				~Interface_GLFW();
				
				//Render interface
				bool SetConfig(const Config &config);
				bool Flip();
		};
	}
}
