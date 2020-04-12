#pragma once

/*
Project: CuckyGameEngine

File: OpenGL/Core.h
Purpose: Provide the OpenGL core subsystem of the engine

Authors: Regan Green (cuckydev)
*/

#include <iostream>
#include "../Core.h"
#include "../Error.h"

//CuckyGameEngine namespace
namespace CGE
{
	//Core namespace
	namespace CORE
	{
		//Core OpenGL interface
		class INTERFACE_OPENGL : public INTERFACE
		{
			public:
				//Constructor and destructor
				INTERFACE_OPENGL(CGE::ERROR::CODE *error)
				{
					*error = CGE::ERROR::CORE_INIT_FAIL;
					std::cout << "Created OpenGL core subsystem" << std::endl;
				}
				
				~INTERFACE_OPENGL()
				{
					std::cout << "Deleted OpenGL core subsystem" << std::endl;
				}
		};
	}
}
