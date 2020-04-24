#pragma once

/*
Project: CuckyGameEngine

File: CGE/Core.h
Purpose: Provide the core subsystem namespace

Authors: Regan Green (cuckydev)
*/

//CuckyGameEngine classes
#include "Error.h"

//CuckyGameEngine namespace
namespace CGE
{
	//Render namespace
	namespace CORE
	{
		//Render subsystem interface base class
		class INTERFACE_BASE
		{
			protected:
				//Error
				ERROR error;
				
			public:
				//Virtual destructor
				virtual ~INTERFACE_BASE() {}
				
				//Get error
				inline ERROR GetError() const { return error; }
		};
	}
}
