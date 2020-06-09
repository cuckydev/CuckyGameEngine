#pragma once

/*
Project: CuckyGameEngine

File: CGE/OpenGL/Render.h
Purpose: Declare the OpenGL render subsystem base class

Authors: Regan "cuckydev" Green
*/

//Base class
#include <CGE/Render.h>

//CuckyGameEngine namespace
namespace CGE
{
	//Render namespace
	namespace Render
	{
		//OpenGL mesh
		class Mesh_OpenGL : public CGE::Render::Mesh
		{
			private:
				//GL objects that represent the mesh
				GLuint vaoId = 0, vboId = 0, eabId = 0;
				
				//Buffer sizes, so we know when to use glBufferData or glBufferSubData
				GLsizei vboSize = 0, eabSize = 0;
				GLsizei vboSizeMax = 0, eabSizeMax = 0;
				
			public:
				//Constructor and destructor
				Mesh_OpenGL(const std::vector<uint16_t> &indices,
							const std::vector<CGE::Math::Vector<3, float>> &position,
							const std::vector<CGE::Math::Vector<3, float>> &normal,
							const std::vector<CGE::Math::Vector<2, float>> &uv,
							const std::vector<CGE::Math::Vector<4, float>> &colour);
				~Mesh_OpenGL();
				
				//Mesh interface
				bool SetData(	const std::vector<uint16_t> &indices,
								const std::vector<CGE::Math::Vector<3, float>> &position,
								const std::vector<CGE::Math::Vector<3, float>> &normal,
								const std::vector<CGE::Math::Vector<2, float>> &uv,
								const std::vector<CGE::Math::Vector<4, float>> &colour);
				
				//Internal mesh interface
				bool Draw() const;
		};
		
		//OpenGL interface
		class Interface_OpenGL : public Interface_Base
		{
			public:
				//Virtual destructor
				virtual ~Interface_OpenGL() {}
				
				//General OpenGL render interface
				Mesh *NewMesh(	const std::vector<uint16_t> &indices,
								const std::vector<CGE::Math::Vector<3, float>> &position,
								const std::vector<CGE::Math::Vector<3, float>> &normal,
								const std::vector<CGE::Math::Vector<2, float>> &uv,
								const std::vector<CGE::Math::Vector<4, float>> &colour);
				
				bool Draw(const Mesh *mesh);
				
				bool ClearColor(float r, float g, float b);
				bool ClearDepth();
				
				//Virtual render interface
				virtual bool SetConfig(const Config &config) = 0;
				virtual bool Flip() = 0;
		};
	}
}
