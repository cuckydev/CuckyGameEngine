/*
Project: CuckyGameEngine

File: CGE/SDL2/Core.cpp
Purpose: Define the SDL2 core subsystem class

Authors: Regan "cuckydev" Green
*/

//Library
#include "SDL.h"

//Declaration
#include "Core.h"

//CuckyGameEngine namespace
namespace CGE
{
	//Core namespace
	namespace Core
	{
		//Constructor and destructor
		Interface_SDL2::Interface_SDL2()
		{
			//Initialize SDL2
			if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) < 0)
			{
				error.Push(SDL_GetError());
				return;
			}
		}

		Interface_SDL2::~Interface_SDL2()
		{
			//Quit SDL2
			SDL_Quit();
		}
	}
}
