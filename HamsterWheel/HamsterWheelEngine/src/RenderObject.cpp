#pragma once
#include "RenderObject.h"

using namespace HW;

RenderObject::RenderObject() : GameObject::GameObject()
{
	_vertexBufferId = 0;
	Init(new Material());

}
RenderObject::RenderObject(Material* material)
{
	Init(material);
	
}

void RenderObject::Init(Material* material)
{
	_material = material;
	// Create a simple quad as a default object
	_nPositionComponents = 3;
	_nVerts = 4;
	unsigned int textureComponents = _material->_texture? 2 : 0;
	unsigned int totalComponents = _nPositionComponents + textureComponents;
	unsigned int vertexBufferCount = _nVerts * totalComponents;
	_attribParams = VertexAttribParams(0, 3, GL_FLOAT, GL_FALSE, totalComponents*sizeof(float), 0);
	_vertexBuffer = new float[vertexBufferCount];
	memset(_vertexBuffer, 0, vertexBufferCount * sizeof(float));

	// TODO: generalize below
	float positionVerts[12] =
	{ -0.5f, 0.5f, 0.5f,
	   0.5f, 0.5f, 0.5f,
	   0.5f, -0.5f, 0.5f,
	  -0.5f, -0.5f, 0.5f,
	};
	
	// interleave texture and position into one buffer
	for (int v = 0; v < _nVerts; v++)
	{
		for (int p = 0; p < _nPositionComponents; p++)
		{
			_vertexBuffer[totalComponents * v + p] = positionVerts[v * _nPositionComponents + p];
		}
		for (int t = 0; t < textureComponents; t++)
		{
			_vertexBuffer[totalComponents * v + _nPositionComponents + t] =
				_material->_texture->_uvBuffer[textureComponents * v + t];
		}
	}

	_indexBuffer = new unsigned int[4]{ 0, 1, 3, 2 };
	_mode = GL_TRIANGLE_STRIP;
	_material = material;

	GLint size;
	//glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
	//printf("ELEMENT_ARRAY_BUFFER SIZE: %d\n", size);


	glGenBuffers(1, &_indexBufferId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBufferId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * 4, _indexBuffer, GL_STATIC_DRAW);
	glGenBuffers(1, &_vertexBufferId);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferId);
	glBufferData(GL_ARRAY_BUFFER, 5 * _nVerts * sizeof(GLfloat), _vertexBuffer, GL_STATIC_DRAW);

	glEnableVertexAttribArray(_attribParams._Index);
	glVertexAttribPointer(_attribParams._Index, _attribParams._Components, _attribParams._Type, _attribParams._Normalized,
		_attribParams._Stride, 0);
	int texAttribIndex = glGetAttribLocation(_material->_shaderProgram->GetId(), "inTexCoord");
	VertexAttribParams uvParams = VertexAttribParams(texAttribIndex, 2, GL_FLOAT, GL_FALSE, totalComponents * sizeof(float), _nPositionComponents * sizeof(float));
	glBindTexture(GL_TEXTURE_2D, this->_material->_texture->_id);

	glEnableVertexAttribArray(uvParams._Index);
	glVertexAttribPointer(uvParams._Index, uvParams._Components, uvParams._Type, uvParams._Normalized, uvParams._Stride, (void*)uvParams._Offset);


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
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferId);
	



	_material->_shaderProgram->SetActive();
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBufferId);

	// Draw the object
	glDrawElements(_mode, 4, GL_UNSIGNED_INT, nullptr);
}

