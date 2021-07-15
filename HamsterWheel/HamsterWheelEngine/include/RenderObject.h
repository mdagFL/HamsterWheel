
#pragma once
#include "GameObject.h"
#include "Renderer.h"
#include "Material.h"

struct VertexAttribParams
{	
	int _Index;
	int _Stride;
	int _Components;
	bool _Normalized;
	int _Type;
	int _Offset;
	VertexAttribParams(int index, int components, int type, bool normalized, int stride, int offset)
		: _Index{ index }, _Stride{ stride }, _Components{ components }, _Normalized{ normalized },
		_Type{ type }, _Offset{ offset } {}	
	
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
		void Render();

	private:
		float* _vertexBuffer;
		unsigned int* _indexBuffer;
		unsigned int _vertexBufferId;
		unsigned int _indexBufferId;
		int _mode;
		
		//Material& _material;

		VertexAttribParams _attribParams;
	};
}
