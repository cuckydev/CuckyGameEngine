/*
Project: CuckyGameEngine

File: CGE/OpenGL/Render.cpp
Purpose: Define the OpenGL render subsystem base class

Authors: Regan Green (cuckydev)
*/

//Libraries
#include <GL/glew.h>

//Declaration
#include "Render.h"

//Internal render interface
void CGE::Render::Interface_OpenGL::ClearColor(float r, float g, float b)
{
	glClearColor(r, g, b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void CGE::Render::Interface_OpenGL::ClearDepth()
{
	glClear(GL_DEPTH_BUFFER_BIT);
}
