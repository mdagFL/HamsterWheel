#pragma once
#include "RenderObject.h"

HW::RenderObject::RenderObject()
{
	// Create a simple quad as a default object
	_attribParams = VertexAttribParams(0, 3, 3, GL_FLOAT, 0);
	
}

HW::RenderObject::~RenderObject()
{
	delete[] _vertexBuffer;
	delete[] _elementBuffer;

}

HW::RenderObject::RenderObject(float* vertexBuffer, int* elementBuffer, VertexAttribParams params)
{
	_vertexBuffer = vertexBuffer;
	_elementBuffer = elementBuffer;
	_attribParams = params;
	
}