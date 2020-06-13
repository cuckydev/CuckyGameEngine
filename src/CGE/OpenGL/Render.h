#pragma once

/*
Project: CuckyGameEngine

File: CGE/OpenGL/Render.h
Purpose: Declare the OpenGL render subsystem base class

Authors: Regan "cuckydev" Green
*/

//Base class
#include <CGE/Render.h>

//CuckyGameEngine namespace
namespace CGE
{
	//Render namespace
	namespace Render
	{
		//OpenGL interface
		class Interface_OpenGL : public Interface_Base
		{
			public:
				//Virtual destructor
				virtual ~Interface_OpenGL() {}
				
				//OpenGL error check
				bool ErrorCheck();
				
				//General OpenGL render interface
				bool ClearColor(float r, float g, float b);
				bool ClearDepth();
				
				//Virtual render interface
				virtual bool SetConfig(const Config &config) = 0;
				virtual bool Flip() = 0;
		};
	}
}
