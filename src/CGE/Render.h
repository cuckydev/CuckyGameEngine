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
	namespace Render
	{
		//Render configuration
		struct Config
		{
			std::string title; //Window title
			unsigned long width, height; //Window dimensions
			bool resizable; //If window is resizable
			bool fullscreen; //If window is fullscreen
			unsigned long framerate; //Target framerate (0 means only use VSync)
			
			//Compare operator
			inline bool operator==(const Config &x) const
			{ return (title == x.title) && (width == x.width) && (height == x.height) && (fullscreen == x.fullscreen) && (framerate == x.framerate); }
			inline bool operator!=(const Config &x) const
			{ return (title != x.title) || (width != x.width) || (height != x.height) || (fullscreen != x.fullscreen) || (framerate != x.framerate); }
		};
		
		//Render subsystem interface base class
		class Interface_Base
		{
			protected:
				//Error
				Error error;
				
				//Used configuration
				Config useConfig;
				
			public:
				//Virtual destructor
				virtual ~Interface_Base() {}
				
				//Render interface
				virtual bool SetConfig(const Config &config) = 0;
				virtual bool Flip() = 0;
				
				//Get error
				inline const Error &GetError() const { return error; }
		};
	}
}
