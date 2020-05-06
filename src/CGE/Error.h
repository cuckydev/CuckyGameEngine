#pragma once

/*
Project: CuckyGameEngine

File: CGE/Error.h
Purpose: Define the CuckyGameEngine error class

Authors: Regan Green (cuckydev)
*/

//Standard library
#include <iostream>
#include <vector>
#include <string>

//CuckyGameEngine namespace
namespace CGE
{
	//Error class
	class Error
	{
		private:
			//Error list
			std::vector<std::string> error_list;
			
		public:
			//Add error(s) to list
			inline bool Add(const Error &error)	{ error_list.push_back(error.GetString()); return true; }
			inline bool Add(std::string error)	{ error_list.push_back(error); return true; }
			
			//Clear all errors in the error list
			inline void Clear() { error_list.clear(); }
			
			std::string GetString() const
			{
				//Get string that contains all errors in the error list
				std::string errorString;
				
				for (size_t i = 0; i < error_list.size(); i++)
				{
					//Concatenate this error onto the full string, and concatenate a divider if not the last one
					errorString.append(error_list[i]);
					if (i < error_list.size() - 1)
						errorString.append(" | ");
				}
				
				return errorString;
			}
			
			//Get if we've recieved any errors
			inline bool Errored() const { return error_list.size() > 0; }
	};
}
