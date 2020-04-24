#pragma once

/*
Project: CuckyGameEngine

File: CGE/OpenGL/Render.h
Purpose: Declare the OpenGL render subsystem class

Authors: Regan Green (cuckydev)
*/

//Base class
#include "../Render.h"

//CuckyGameEngine namespace
namespace CGE
{
	//Render namespace
	namespace RENDER
	{
		class INTERFACE_OPENGL : public INTERFACE_BASE
		{
			private:
				
			public:
				//Constructor and destructor
				INTERFACE_OPENGL(const CONFIG &_config);
				~INTERFACE_OPENGL();
		};
	}
}
