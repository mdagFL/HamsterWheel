#pragma once
#include "RenderObject.h"

namespace HW
{
	RenderObject::RenderObject(VertexArrayObject* vao, VertexBufferObject* vbo, Material* material)
	{
		Init(vao, vbo, material);
	}

	void RenderObject::Init(VertexArrayObject* vao, VertexBufferObject* vbo, Material* material)
	{
		_material = material;
		_vao = vao;
		_vbo = vbo;

		if (_material && _material->_texture)
		{
			glBindTexture(GL_TEXTURE_2D, this->_material->_texture->_id);
		}

	}


	RenderObject::~RenderObject()
	{
		delete _vbo;
		delete _vao;
		delete _material;
	}

	void RenderObject::Render() const
	{
		glBindVertexArray(_vao->_id);

		if (_material)
		{
			_material->_shaderProgram->SetActive();
		}
		else
		{
			printf("no material - not implemented!\n");
		}

		// Draw the object
		if (_vao->_indexBuffer)
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _vao->_indexBufferId);
			glDrawElements(_vao->_drawMode, _vao->_indexBufferCount, GL_UNSIGNED_INT, nullptr);
		}
		else
		{
			printf("no index buffer - not implemented!!\n");
		}
		glBindVertexArray(0);

	}


}


