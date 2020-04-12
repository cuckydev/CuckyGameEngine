#pragma once

/*
Project: CuckyGameEngine

File: OpenGL/Core.h
Purpose: Provide the OpenGL core module of the engine

Notes: This is (and must be) included in the CGE::CORE scope

Authors: Regan Green (cuckydev)
*/

//Core OpenGL interface
class INTERFACE_OPENGL : public INTERFACE
{
	private:
		//Test
		int testMember = 5;
		
	public:
		//Constructor and destructor
		INTERFACE_OPENGL()
		{
			testMember = 10;
		}
		
		~INTERFACE_OPENGL()
		{
			
		}
		
		//Various functions
		void TestBackend()
		{
			std::cout << testMember << std::endl;
		}
};
