#pragma once

/*
Project: CuckyGameEngine

File: CGE/OpenGL/Core.h
Purpose: Declare the OpenGL core subsystem class

Authors: Regan Green (cuckydev)
*/

//Base class
#include "../Core.h"

//CuckyGameEngine namespace
namespace CGE
{
	//Render namespace
	namespace CORE
	{
		class INTERFACE_OPENGL : public INTERFACE_BASE
		{
			private:
				
			public:
				//Constructor and destructor
				INTERFACE_OPENGL();
				~INTERFACE_OPENGL();
		};
	}
}
