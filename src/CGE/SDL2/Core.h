#pragma once

/*
Project: CuckyGameEngine

File: CGE/SDL2/Core.h
Purpose: Declare the SDL2 core subsystem class

Authors: Regan "cuckydev" Green
*/

//Base class
#include <CGE/Core.h>

//CuckyGameEngine namespace
namespace CGE
{
	//Render namespace
	namespace Core
	{
		class Interface_SDL2 : public Interface_Base
		{
			public:
				//Constructor and destructor
				Interface_SDL2();
				~Interface_SDL2();
		};
	}
}
