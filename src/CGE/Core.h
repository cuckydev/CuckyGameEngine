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
	namespace Core
	{
		//Render subsystem interface base class
		class Interface_Base
		{
			protected:
				//Error
				Error error;
				
			public:
				//Virtual destructor
				virtual ~Interface_Base() {}
				
				//Get error
				inline const Error &GetError() const { return error; }
		};
	}
}
