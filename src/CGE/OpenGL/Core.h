#pragma once

/*
Project: CuckyGameEngine

File: OpenGL/Core.h
Purpose: Provide the OpenGL core subsystem of the engine

Notes: This is (and must be) included in the CGE::CORE scope

Authors: Regan Green (cuckydev)
*/

//Core OpenGL interface
class INTERFACE_OPENGL : public INTERFACE
{
	public:
		//Destructor
		~INTERFACE_OPENGL() {}
		
		//Core interface
		bool Initialize()
		{
			return false;
		}
		
		bool Quit()
		{
			return false;
		}
};
