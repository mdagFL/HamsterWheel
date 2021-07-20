#pragma once
#include "RenderObject.h"

using namespace HW;

RenderObject::RenderObject() : GameObject::GameObject()
{
	Init(new Material());

}
RenderObject::RenderObject(Material *material)
{
	Init(material);
	
}

void RenderObject::Init(Material* material)
{

	// Create a simple quad as a default object
	_attribParams = VertexAttribParams(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	/*
	_vertexBuffer = new float[12]
	{ -0.5f, 0.5f, 1.5f,
	   0.5f, 0.5f, 1.5f,
	   0.5f, -0.5f, 1.5f,
	  -0.5f, -0.5f, 1.5f,
	};
	*/

	_vertexBuffer = new float[12] {
	-0.9f, -0.9f, 0.5f,
	-0.9F, 0.9F, 0.5f,
	0.9f, -0.9f, 0.5f,
	0.9F, 0.9F, 0.5f
	};

	_indexBuffer = new unsigned int[4]{ 0, 1, 2, 3 };
	_mode = GL_TRIANGLE_STRIP;
	_material = material;

	glGenBuffers(1, &_vertexBufferId);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferId);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(GLfloat), _vertexBuffer, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(_attribParams._Index, _attribParams._Components, _attribParams._Type, _attribParams._Normalized,
		_attribParams._Stride, 0);

	glGenBuffers(1, &_indexBufferId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBufferId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * 4, _indexBuffer, GL_STATIC_DRAW);
}


RenderObject::~RenderObject()
{
	delete[] _vertexBuffer;
	delete[] _indexBuffer;
	delete _material; // probably should make this managed by the client..
}


/*
RenderObject::RenderObject(float* vertexBuffer, unsigned int* elementBuffer, VertexAttribParams &params, Material &material)
{
	_vertexBuffer = vertexBuffer;
	_indexBuffer = elementBuffer;
	_attribParams = params;
	_material = *material;
	
}
*/
void RenderObject::Render() const
{
	_material->_shaderProgram->SetActive();
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBufferId);

	glDrawElements(_mode, 4, GL_UNSIGNED_INT, nullptr);
}

