#pragma once

/*
Project: CuckyGameEngine

File: CGE/Render.h
Purpose: Provide the render subsystem namespace

Authors: Regan Green (cuckydev)
*/

//CuckyGameEngine classes
#include "Error.h"

//CuckyGameEngine namespace
namespace CGE
{
	//Render namespace
	namespace RENDER
	{
		//Render configuration
		struct CONFIG
		{
			std::string title; //Window title
			unsigned long width, height; //Window dimensions
			bool resizable; //If window is resizable
			bool fullscreen; //If window is fullscreen
			unsigned long framerate; //Target framerate (0 means only use VSync)
			
			//Compare operator
			inline bool operator==(const CONFIG &x)
			{
				return (title == x.title) && (width == x.width) && (height == x.height)
					&& (fullscreen == x.fullscreen) && (framerate == x.framerate);
			}
		};
		
		//Render subsystem interface base class
		class INTERFACE_BASE
		{
			protected:
				//Error
				ERROR error;
				
				//Current configuration
				CONFIG config;
				
			public:
				//Virtual destructor
				virtual ~INTERFACE_BASE() {}
				
				//Render interface
				
				//Get error
				inline ERROR GetError() const { return error; }
		};
	}
}
