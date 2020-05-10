#pragma once

/*
Project: CuckyGameEngine

File: CGE/OpenGL/Render.h
Purpose: Declare the OpenGL render subsystem base class

Authors: Regan Green (cuckydev)
*/

//Base class
#include "../Render.h"

//CuckyGameEngine namespace
namespace CGE
{
	//Render namespace
	namespace Render
	{
		class Interface_OpenGL : public Interface_Base
		{
			private:
				
			public:
				//Virtual destructor
				virtual ~Interface_OpenGL() {}
				
				//General OpenGL render interface
				bool ClearColor(float r, float g, float b);
				bool ClearDepth();
				
				//Virtual render interface
				virtual bool SetConfig(const Config &config) = 0;
				virtual bool Flip() = 0;
		};
	}
}
