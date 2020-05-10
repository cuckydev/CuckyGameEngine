#pragma once

/*
Project: CuckyGameEngine

File: CGE/Render.h
Purpose: Declare the render subsystem namespace

Authors: Regan Green (cuckydev)
*/

//Standard library
#include <vector>

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
			bool operator==(const Config &x) const
			{ return (title == x.title) && (width == x.width) && (height == x.height) && (fullscreen == x.fullscreen) && (framerate == x.framerate); }
			bool operator!=(const Config &x) const
			{ return (title != x.title) || (width != x.width) || (height != x.height) || (fullscreen != x.fullscreen) || (framerate != x.framerate); }
		};
		
		//Prototype interface base
		class Interface_Base;
		
		//Display list commands
		class DLCommand_Base
		{
			public:
				//Virtual destructor
				virtual ~DLCommand_Base() {}
				
				//Execution
				virtual void Execute(Interface_Base *render) const = 0;
		};
		
		class DLCommand_ClearColor : public DLCommand_Base
		{
			private:
				//Colour to clear to
				float r, g, b;
				
			public:
				//Constructor and destructor
				DLCommand_ClearColor(float _r, float _g, float _b);
				~DLCommand_ClearColor();
				
				//Execution
				void Execute(Interface_Base *render) const;
		};
		
		class DLCommand_ClearDepth : public DLCommand_Base
		{
			public:
				//Constructor and destructor
				DLCommand_ClearDepth();
				~DLCommand_ClearDepth();
				
				//Execution
				void Execute(Interface_Base *render) const;
		};
		
		//Display list class
		class DisplayList
		{
			private:
				//Display list commands
				std::vector<DLCommand_Base*> commands;
				
			public:
				//Display list access
				void Push(DLCommand_Base *command)
				{
					//Push command to display list
					commands.push_back(command);
				}
				
				void Clear()
				{
					//Delete all commands and clear display list
					for (DLCommand_Base *i : commands)
						delete i;
					commands.clear();
				}
				
				//Draw execution
				void Execute(Interface_Base *render) const
				{
					//Execute all commands
					for (DLCommand_Base *i : commands)
						i->Execute(render);
				}
		};
		
		//Render subsystem interface base class
		class Interface_Base
		{
			protected:
				//Error
				Error error;
				
				//Used configuration
				Config use_config;
				
			public:
				//Virtual destructor
				virtual ~Interface_Base() {}
				
				//Internal render interface
				virtual void ClearColor(float r, float g, float b) = 0;
				virtual void ClearDepth() = 0;
				
				//Virtual render interface
				virtual bool SetConfig(const Config &config) = 0;
				virtual bool Flip() = 0;
				
				//General render interface
				bool Execute(DisplayList *display_list)
				{
					//Execute display list (this can push errors to our error list)
					display_list->Execute(this);
					return error;
				}
				
				//Get error
				const Error &GetError() const { return error; }
		};
	}
}
