/*
Project: CuckyGameEngine

File: CGE/SDL2/Render.cpp
Purpose: Define the SDL2 render subsystem class

Authors: Regan "cuckydev" Green
*/

//Library
#include <GL/glew.h>

//Declaration
#include "Render.h"

//Constructor and destructor
CGE::Render::Interface_SDL2::Interface_SDL2(const Config &config)
{
	//Use the given configuration
	SetConfig(config);
}

CGE::Render::Interface_SDL2::~Interface_SDL2()
{
	//Destroy SDL window and OpenGL context
}

bool CGE::Render::Interface_SDL2::SetConfig(const Config &config)
{
	//Use the given configuration
	use_config = config;
	return false;
}

bool CGE::Render::Interface_SDL2::Flip()
{
	return false;
}
