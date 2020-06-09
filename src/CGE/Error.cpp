/*
Project: CuckyGameEngine

File: CGE/Error.cpp
Purpose: Define the CuckyGameEngine error class

Authors: Regan "cuckydev" Green
*/

//Declaration
#include <CGE/Error.h>

//Return string that contains all errors
std::string CGE::Error::ToString() const
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
