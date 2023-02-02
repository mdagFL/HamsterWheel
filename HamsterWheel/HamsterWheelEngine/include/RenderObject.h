
#pragma once
#include "GameObject.h"
#include "Renderer.h"
#include "Material.h"

#include <string>
#include <map>

namespace HW
{

	struct VertexBufferObject
	{
		float* _vertexBuffer;
		unsigned int  _vertexBufferCount;
		unsigned int  _vboId;

		VertexBufferObject( float* vertexBuffer, unsigned int vertexBufferCount) 
			: _vertexBuffer{ vertexBuffer }, _vertexBufferCount { vertexBufferCount }
		{
			Init();
		}

		void Init()
		{
			glGenBuffers(1, &_vboId);
			glBindBuffer(GL_ARRAY_BUFFER, _vboId);
			glBufferData(GL_ARRAY_BUFFER, sizeof(float) * _vertexBufferCount, _vertexBuffer, GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		~VertexBufferObject()
		{
			delete[] _vertexBuffer;
		}
	};

	struct VertexAttribute
	{
		VertexBufferObject* _Vbo;
		int _Index;
		int _Stride;
		int _Components;
		int _Normalized;
		int _Type;
		int _Offset;
		VertexAttribute(int index, int components, int type, int normalized, int stride, int offset, VertexBufferObject* vbo)
			: _Index{ index }, _Stride{ stride }, _Components{ components }, _Normalized{ normalized },
			_Type{ type }, _Offset{ offset }, _Vbo{ vbo } 
		{

		}
	};

	struct VertexArrayObject
	{
		std::vector<VertexAttribute> _attributes;
		unsigned int _id;
		unsigned int* _indexBuffer;
		unsigned int  _indexBufferCount;
		unsigned int  _indexBufferId;
		int		      _drawMode;

		VertexArrayObject(unsigned int* indexBuffer, unsigned int indexBufferCount, int drawMode)
			: _indexBuffer{ indexBuffer }, _indexBufferCount{ indexBufferCount }, _drawMode{ drawMode }
		{
			Init();
		}

		void AddAttribute(VertexAttribute& attribute)
		{
			_attributes.push_back(attribute);
			glBindVertexArray(_id);
			glBindBuffer(GL_ARRAY_BUFFER, attribute._Vbo->_vboId);

			glEnableVertexAttribArray(attribute._Index);
			glVertexAttribPointer(attribute._Index, attribute._Components, attribute._Type, attribute._Normalized,
				attribute._Stride, 0);
		}

		void Init()
		{
			// Setup VAO in OGL
			glGenVertexArrays(1, &_id);
			glBindVertexArray(_id);

			// Setup index buffer if it exists
			if (_indexBuffer)
			{
				glGenBuffers(1, &_indexBufferId);
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBufferId);
				glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * _indexBufferCount, _indexBuffer, GL_STATIC_DRAW); //vertexBufferCount
			}
			glBindVertexArray(0);

		}

		~VertexArrayObject()
		{
			delete[] _indexBuffer;
		}
	};

	class RenderObject : public GameObject
	{
	public:
		RenderObject(VertexArrayObject* vao, VertexBufferObject* vbo, Material* material);
		~RenderObject();
		void Render() const override;

	private:
		void Init(VertexArrayObject* vao, VertexBufferObject* vbo, Material* material);
		VertexArrayObject* _vao;
		VertexBufferObject* _vbo;
		Material* _material;
	};
}
