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
			std::vector<std::string> errorList;
			
		public:
			//Add error(s) to list
			inline bool AddError(const Error &error)	{ errorList.push_back(error.GetString()); return true; }
			inline bool AddError(std::string error)		{ errorList.push_back(error); return true; }
			
			//Clear all errors in the error list
			inline void ClearErrors() { errorList.clear(); }
			
			std::string GetString() const
			{
				//Get string that contains all errors in the error list
				std::string errorString;
				
				for (size_t i = 0; i < errorList.size(); i++)
				{
					//Concatenate this error onto the full string, and concatenate a divider if not the last one
					errorString.append(errorList[i]);
					if (i < errorList.size() - 1)
						errorString.append(" | ");
				}
				
				return errorString;
			}
			
			//Get if we've recieved any errors
			inline bool Errored() const { return errorList.size() > 0; }
	};
}
