#pragma once

/*
Project: CuckyGameEngine

File: Core.h
Purpose: Provide the core module of the engine

Authors: Regan Green (cuckydev)
*/

#include <iostream>

//CuckyGameEngine namespace
namespace CGE
{
	//Core namespace
	namespace CORE
	{
		//Core interface base class
		class INTERFACE
		{
			public:
				//Virtual destructor
				virtual ~INTERFACE() {}
				
				//Various functions
				virtual void TestBackend() = 0;
		};
		
		//Backend classes
		#include "OpenGL/Core.h"
	}
}
