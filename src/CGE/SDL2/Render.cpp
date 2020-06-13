/*
Project: CuckyGameEngine

File: CGE/SDL2/Render.cpp
Purpose: Define the SDL2 render subsystem class

Authors: Regan "cuckydev" Green
*/

//Library
#include "SDL_timer.h"

//Declaration
#include "Render.h"

//CuckyGameEngine namespace
namespace CGE
{
	//Render namespace
	namespace Render
	{
		//Constructor and destructor
		Interface_SDL2::Interface_SDL2(const Config &config)
		{
			//Use the given configuration
			SetConfig(config);
		}

		Interface_SDL2::~Interface_SDL2()
		{
			//Destroy SDL window and OpenGL context
			if (context != nullptr)
				SDL_GL_DeleteContext(context);
			if (window != nullptr)
				SDL_DestroyWindow(window);
		}

		bool Interface_SDL2::SetConfig(const Config &config)
		{
			if (window == nullptr)
			{
				//Set OpenGL attributes
				SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
				SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
				SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
				SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
				
				//Create window
				if ((window = SDL_CreateWindow(config.title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, config.width, config.height, SDL_WINDOW_OPENGL | (config.fullscreen ? SDL_WINDOW_FULLSCREEN : 0) | (config.resizable ? SDL_WINDOW_RESIZABLE : 0))) == nullptr)
				{
					error.Push(SDL_GetError());
					return true;
				}
				
				//Create OpenGL context
				if (context != nullptr)
					SDL_GL_DeleteContext(context);
				
				if ((context = SDL_GL_CreateContext(window)) == nullptr)
				{
					error.Push(SDL_GetError());
					return true;
				}
			}
			else
			{
				//Update title if changed
				if (config.title != use_config.title)
					SDL_SetWindowTitle(window, config.title.c_str());
				
				//Update size if changed
				if (config.width != use_config.width && config.height != use_config.height)
				{
					//Both width and height changed, so change both sizes
					SDL_SetWindowSize(window, config.width, config.height);
				}
				else if (config.width != use_config.width)
				{
					//Only width changed, so only change width
					int height;
					SDL_GetWindowSize(window, nullptr, &height);
					SDL_SetWindowSize(window, config.width, height);
				}
				else if (config.height != use_config.height)
				{
					//Only height changed, so only change height
					int width;
					SDL_GetWindowSize(window, &width, nullptr);
					SDL_SetWindowSize(window, width, config.width);
				}
				
				//Update resizable if changed
				if (config.resizable != use_config.resizable)
					SDL_SetWindowResizable(window, (SDL_bool)config.resizable);
			}
			
			//Use the given configuration
			use_config = config;
			
			//Get the display mode containing our window
			SDL_DisplayMode mode;
			if (SDL_GetWindowDisplayMode(window, &mode) < 0)
				return true;
			
			//Use our the display mode's refresh rate as our framerate if we wanted VSync
			if (use_config.framerate == 0)
				use_config.framerate = mode.refresh_rate;
			
			//Use manual framerate limiter if it was specified or VSync failed
			if (use_config.framerate != 0)
			{
				//Check if VSync can be used between the refresh rate and wanted framerate
				double refresh_integral;
				double refresh_fractional = std::modf((double)mode.refresh_rate / (double)use_config.framerate, &refresh_integral);
				unsigned long vsync_multiple = (unsigned long)refresh_integral;
				
				if ((vsync_multiple > 0 && refresh_fractional == 0.0) && SDL_GL_SetSwapInterval(vsync_multiple) >= 0)
				{
					//We're using VSync, so don't use the limiter
					use_limiter = false;
				}
				else
				{
					//Use adaptive VSync if available
					if (SDL_GL_SetSwapInterval(-1) < 0)
						SDL_GL_SetSwapInterval(0);
					
					//Get our frame time and timeout time (how long we can be late for a frame before resync)
					frame_time = 1000.0 / (double)use_config.framerate;
					timeout_time = frame_time * 10.0f;
					
					//Initialize limiter time and set taht we're using the limiter
					next_time = (double)SDL_GetTicks() + frame_time;
					use_limiter = true;
				}
			}
			return false;
		}

		bool Interface_SDL2::Flip()
		{
			//If not using VSync, wait for the next frame manually
			if (use_limiter)
			{
				//Get our current time
				double curr_time = (double)SDL_GetTicks();
				
				if (curr_time >= next_time + timeout_time)
				{
					next_time = curr_time;
				}
				else
				{
					if (curr_time < next_time)
						SDL_Delay(next_time - curr_time);
					next_time += frame_time;
				}
			}
			
			//Swap window buffers
			SDL_GL_SwapWindow(window);
			return false;
		}
	}
}
