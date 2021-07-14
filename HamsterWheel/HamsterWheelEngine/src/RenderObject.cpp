#pragma once
#include "RenderObject.h"

HW::RenderObject::RenderObject() : HW::GameObject::GameObject()
{
	// Create a simple quad as a default object
	_attribParams = VertexAttribParams(0, 3, GL_FLOAT, 3 * sizeof(float), 0);
	_vertexBuffer = new float[12] 
	{ -1.0f, 1.0f, 0.5f,
	   1.0f, 1.0f, 0.5f,
	   1.0f, -1.0f, 0.5f,
	  -1.0f, -1.0f, 0.5f,
	};
	_elementBuffer = new unsigned int[4]{ 0, 1, 3, 2 };

	glGenBuffers(1, &_bufferId);
	glBindBuffer(GL_ARRAY_BUFFER, _bufferId);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), _vertexBuffer, GL_STATIC_DRAW);
	//glVertexAttribPointer()

}

HW::RenderObject::~RenderObject()
{
	delete[] _vertexBuffer;
	delete[] _elementBuffer;

}

HW::RenderObject::RenderObject(float* vertexBuffer, unsigned int* elementBuffer, VertexAttribParams params, Material& material)
{
	_vertexBuffer = vertexBuffer;
	_elementBuffer = elementBuffer;
	_attribParams = params;
	
}