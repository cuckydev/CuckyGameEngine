#pragma once

/*
Project: CuckyGameEngine

File: CGE/SDL2/Render.h
Purpose: Define the SDL2 render subsystem base class

Authors: Regan "cuckydev" Green
*/

//Libraries
#include "SDL_render.h"
#include <GL/glew.h>

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
		class Interface_SDL2 : public Interface_OpenGL
		{
			private:
				//SDL window and OpenGL context
				SDL_Window *window = nullptr;
				SDL_GLContext context = nullptr;
				
				//Framerate limiter state
				bool use_limiter;
				double next_time, frame_time, timeout_time;
				
			public:
				//Constructor and destructor
				Interface_SDL2(const Config &config);
				~Interface_SDL2();
				
				//Render interface
				bool SetConfig(const Config &config);
				bool Flip();
		};
	}
}
