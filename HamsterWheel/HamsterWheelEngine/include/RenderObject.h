
#pragma once
#include "GameObject.h"
#include "Renderer.h"
#include "Material.h"

struct VertexAttribParams
{	
	int _Index;
	int _Stride;
	int _Comonents;
	int _Type;
	int _Offset;
	VertexAttribParams(int attribIndex, int attribComponents, int attribType, int attribStride, int attribOffset)
		: _Index{ attribIndex }, _Stride{ attribStride }, _Comonents{ attribComponents },
		_Type{ attribType }, _Offset{ attribOffset } {}	
	VertexAttribParams() { 
		return;
	}
};

namespace HW
{
	class RenderObject : public GameObject
	{
	public:
		

		RenderObject();
		RenderObject(float* vertexBuffer, unsigned int* elementBuffer, VertexAttribParams& params, Material& material);
		~RenderObject();
		
	private:
		float* _vertexBuffer;
		unsigned int* _elementBuffer;
		unsigned int _bufferId;
		//Material& _material;

		VertexAttribParams _attribParams;
	};
}
