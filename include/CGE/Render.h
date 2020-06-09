#pragma once

/*
Project: CuckyGameEngine

File: CGE/Render.h
Purpose: Declare the render subsystem namespace

Authors: Regan "cuckydev" Green
*/

//Standard library
#include <cstdint>
#include <vector>

//CuckyGameEngine classes
#include "Error.h"
#include "Math.h"

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
			{ return (title == x.title) && (width == x.width) && (height == x.height) && (resizable == x.resizable) && (fullscreen == x.fullscreen) && (framerate == x.framerate); }
			bool operator!=(const Config &x) const
			{ return (title != x.title) || (width != x.width) || (height != x.height) || (resizable != x.resizable) || (fullscreen != x.fullscreen) || (framerate != x.framerate); }
		};
		
		//Mesh base class
		class Mesh
		{
			protected:
				//Error
				CGE::Error error;
				
			public:
				//Virtual destructor
				virtual ~Mesh() {}
				
				//Mesh interface
				virtual bool SetData(	const std::vector<uint16_t> &indices,
										const std::vector<CGE::Math::Vector<3, float>> &position,
										const std::vector<CGE::Math::Vector<3, float>> &normal,
										const std::vector<CGE::Math::Vector<2, float>> &uv,
										const std::vector<CGE::Math::Vector<4, float>> &colour) = 0;
				
				//Internal mesh interface
				virtual bool Draw() const = 0;
				
				//Get error
				const CGE::Error &GetError() const { return error; }
		};
		
		//Render subsystem interface base class
		class Interface_Base
		{
			protected:
				//Error
				CGE::Error error;
				
				//Used configuration
				Config use_config;
				
			public:
				//Virtual destructor
				virtual ~Interface_Base() {}
				
				//Render interface
				virtual bool SetConfig(const Config &config) = 0;
				
				virtual Mesh *NewMesh(	const std::vector<uint16_t> &indices,
										const std::vector<CGE::Math::Vector<3, float>> &position,
										const std::vector<CGE::Math::Vector<3, float>> &normal,
										const std::vector<CGE::Math::Vector<2, float>> &uv,
										const std::vector<CGE::Math::Vector<4, float>> &colour) = 0;
				
				virtual bool Draw(const Mesh *mesh) = 0;
				
				virtual bool ClearColor(float r, float g, float b) = 0;
				virtual bool ClearDepth() = 0;
				virtual bool Flip() = 0;
				
				//Get error
				const CGE::Error &GetError() const { return error; }
		};
	}
}
