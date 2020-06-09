/*
Project: CuckyGameEngine

File: CGE/OpenGL/Render.cpp
Purpose: Define the OpenGL render subsystem base class

Authors: Regan "cuckydev" Green
*/

//Libraries
#include <GL/glew.h>

//Declaration
#include "Render.h"

//OpenGL mesh object
CGE::Render::Mesh_OpenGL::Mesh_OpenGL(	const std::vector<uint16_t> &indices,
										const std::vector<CGE::Math::Vector<3, float>> &position,
										const std::vector<CGE::Math::Vector<3, float>> &normal,
										const std::vector<CGE::Math::Vector<2, float>> &uv,
										const std::vector<CGE::Math::Vector<4, float>> &colour)
{
	SetData(indices, position, normal, uv, colour);
}

CGE::Render::Mesh_OpenGL::~Mesh_OpenGL()
{
	//Destroy OpenGL objects associated with this mesh
}

bool CGE::Render::Mesh_OpenGL::SetData(	const std::vector<uint16_t> &indices,
										const std::vector<CGE::Math::Vector<3, float>> &position,
										const std::vector<CGE::Math::Vector<3, float>> &normal,
										const std::vector<CGE::Math::Vector<2, float>> &uv,
										const std::vector<CGE::Math::Vector<4, float>> &colour)
{
	//Allocate buffer that holds all data
	GLsizei size = position.size()*3 + normal.size()*3 + uv.size()*2 + colour.size()*4;
	GLfloat *data = new GLfloat[size];
	
	//Get positions in buffer that mark each of the attributes
	GLfloat *position_pointer = data;
	GLfloat *normal_pointer = position_pointer + position.size()*3;
	GLfloat *uv_pointer = normal_pointer + normal.size()*3;
	GLfloat *colour_pointer = uv_pointer + uv.size()*2;
	
	//Copy given data to temp data
	GLfloat *dataStream = data;
	for (auto &i : position)
	{
		*dataStream++ = i[0];
		*dataStream++ = i[1];
		*dataStream++ = i[2];
	}
	for (auto &i : normal)
	{
		*dataStream++ = i[0];
		*dataStream++ = i[1];
		*dataStream++ = i[2];
	}
	for (auto &i : uv)
	{
		*dataStream++ = i[0];
		*dataStream++ = i[1];
	}
	for (auto &i : colour)
	{
		*dataStream++ = i[0];
		*dataStream++ = i[1];
		*dataStream++ = i[2];
		*dataStream++ = i[3];
	}
	
	//Send our new data to VBO (and attach it to VAO)
	glBindVertexArray(vaoId);
	glBindBuffer(GL_ARRAY_BUFFER, vboId);
	
	vboSize = size;
	if (vboSize > vboSizeMax)
	{
		glBufferData(GL_ARRAY_BUFFER, vboSize * sizeof(GLfloat), data, GL_STATIC_DRAW);
		vboSizeMax = vboSize;
	}
	else
	{
		glBufferSubData(GL_ARRAY_BUFFER, 0, vboSize * sizeof(GLfloat), data);
	}
	
	//Send indices to EAB
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eabId);
	
	eabSize = indices.size();
	if (eabSize > eabSizeMax)
	{
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, eabSize * sizeof(uint16_t), indices.data(), GL_STATIC_DRAW);
		eabSizeMax = eabSize;
	}
	else
	{
		glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, eabSize * sizeof(uint16_t), indices.data());
	}
	
	//Setup our VAO attributes
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)((position_pointer - data) * sizeof(GLfloat)));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)((normal_pointer - data) * sizeof(GLfloat)));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*)((uv_pointer - data) * sizeof(GLfloat)));
	glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, 0, (GLvoid*)((colour_pointer - data) * sizeof(GLfloat)));
	
	//Finished
	delete[] data;
	return false;
}

//OpenGL mesh internal interface
bool CGE::Render::Mesh_OpenGL::Draw() const
{
	//Bind VAO, VBO, EBO, and draw
	glBindVertexArray(vaoId);
	glBindBuffer(GL_ARRAY_BUFFER, vboId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eabId);
	glDrawElements(GL_TRIANGLES, eabSize, GL_UNSIGNED_SHORT, nullptr);
	return false;
}

//OpenGL render interface
CGE::Render::Mesh *CGE::Render::Interface_OpenGL::NewMesh(	const std::vector<uint16_t> &indices,
															const std::vector<CGE::Math::Vector<3, float>> &position,
															const std::vector<CGE::Math::Vector<3, float>> &normal,
															const std::vector<CGE::Math::Vector<2, float>> &uv,
															const std::vector<CGE::Math::Vector<4, float>> &colour)
{
	return new Mesh_OpenGL(indices, position, normal, uv, colour);
}

bool CGE::Render::Interface_OpenGL::Draw(const CGE::Render::Mesh *mesh)
{
	//TODO: batching
	if (mesh->Draw())
	{
		error.Push(mesh->GetError());
		return true;
	}
	return false;
}

bool CGE::Render::Interface_OpenGL::ClearColor(float r, float g, float b)
{
	glClearColor(r, g, b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	return false;
}

bool CGE::Render::Interface_OpenGL::ClearDepth()
{
	glClear(GL_DEPTH_BUFFER_BIT);
	return false;
}
