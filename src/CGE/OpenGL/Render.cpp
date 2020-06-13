/*
Project: CuckyGameEngine

File: CGE/OpenGL/Render.cpp
Purpose: Define the OpenGL render subsystem base class

Authors: Regan "cuckydev" Green
*/

//Libraries
#include <GL/glew.h>

//Declaration
#include "Render.h"

//CuckyGameEngine namespace
namespace CGE
{
	//Render namespace
	namespace Render
	{
		//OpenGL error check
		bool Interface_OpenGL::ErrorCheck()
		{
			GLenum err;
			while ((err = glGetError()) != GL_NO_ERROR)
			{
				switch (err)
				{
					case GL_INVALID_ENUM:
						error.Push("GL_INVALID_ENUM");
						break;
					case GL_INVALID_VALUE:
						error.Push("GL_INVALID_VALUE");
						break;
					case GL_INVALID_OPERATION:
						error.Push("GL_INVALID_OPERATION");
						break;
					case GL_STACK_OVERFLOW:
						error.Push("GL_STACK_OVERFLOW");
						break;
					case GL_STACK_UNDERFLOW:
						error.Push("GL_STACK_UNDERFLOW");
						break;
					case GL_OUT_OF_MEMORY:
						error.Push("GL_OUT_OF_MEMORY");
						break;
					case GL_TABLE_TOO_LARGE:
						error.Push("GL_TABLE_TOO_LARGE");
						break;
					case GL_INVALID_FRAMEBUFFER_OPERATION:
						error.Push("GL_INVALID_FRAMEBUFFER_OPERATION");
						break;
					default:
						break;
				}
			}
			
			return error;
		}
		
		//General OpenGL render interface
		bool Interface_OpenGL::ClearColor(float r, float g, float b)
		{
			glClearColor(r, g, b, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			return ErrorCheck();
		}

		bool Interface_OpenGL::ClearDepth()
		{
			glClear(GL_DEPTH_BUFFER_BIT);
			return ErrorCheck();
		}
	}
}
