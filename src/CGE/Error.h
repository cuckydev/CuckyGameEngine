#pragma once

/*
Project: CuckyGameEngine

File: Error.h
Purpose: Provide error codes and strings

Authors: Regan Green (cuckydev)
*/

#include <string>

//CuckyGameEngine namespace
namespace CGE
{
	//Error namespace
	namespace ERROR
	{
		//Error codes
		enum CODE
		{
			NONE,
			CORE_INIT_FAIL,
		};
		
		//String from code
		std::string GetString(const CODE &code)
		{
			switch (code)
			{
				case NONE:
					return "";
				case CORE_INIT_FAIL:
					return "Failed to initialize core";
				default:
					return "Invalid error code";
			}
		}
	}
}
