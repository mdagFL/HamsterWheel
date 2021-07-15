#pragma once
#include "RenderObject.h"

HW::RenderObject::RenderObject() : HW::GameObject::GameObject()
{
	// Create a simple quad as a default object
	_attribParams = VertexAttribParams(0, 3, GL_FLOAT, false, 3 * sizeof(float), 0);
	_vertexBuffer = new float[12] 
	{ -1.0f, 1.0f, 0.5f,
	   1.0f, 1.0f, 0.5f,
	   1.0f, -1.0f, 0.5f,
	  -1.0f, -1.0f, 0.5f,
	};
	_indexBuffer = new unsigned int[4]{ 0, 1, 3, 2 };
	_mode = GL_TRIANGLE_STRIP;

	glGenBuffers(1, &_vertexBufferId);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferId);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), _vertexBuffer, GL_STATIC_DRAW);
	glVertexAttribPointer(_attribParams._Index, _attribParams._Components, _attribParams._Type, _attribParams._Normalized,
		_attribParams._Stride, &_attribParams._Offset);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBufferId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 4, _indexBuffer, GL_STATIC_DRAW);

	

}

HW::RenderObject::~RenderObject()
{
	delete[] _vertexBuffer;
	delete[] _indexBuffer;

}

HW::RenderObject::RenderObject(float* vertexBuffer, unsigned int* elementBuffer, VertexAttribParams &params, Material& material)
{
	_vertexBuffer = vertexBuffer;
	_indexBuffer = elementBuffer;
	_attribParams = params;
	
}

void HW::RenderObject::Render()
{
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBufferId);

	glDrawElements(_mode, 4, GL_UNSIGNED_INT, _indexBuffer);
}

