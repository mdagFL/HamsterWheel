
#pragma once
#include "GameObject.h"
#include "Renderer.h"
#include "Material.h"

struct VertexAttribute
{	
	int _Index;
	int _Stride;
	int _Components;
	int _Normalized;
	int _Type;
	int _Offset;
	VertexAttribute(int index, int components, int type, int normalized, int stride, int offset)
		: _Index{ index }, _Stride{ stride }, _Components{ components }, _Normalized{ normalized },
		_Type{ type }, _Offset{ offset } {}	
	
	VertexAttribute() { 
		return;
	}
};

namespace HW
{
	class RenderObject : public GameObject
	{
	public:
		
		RenderObject();
		RenderObject(Material* material);
		RenderObject(float* vertexBuffer, unsigned int* elementBuffer, VertexAttribute& params, Material* material);
		~RenderObject();
		void Render() const override;

	private:
		void Init(Material* material);
		float* _vertexBuffer;
		unsigned int* _indexBuffer;
		unsigned int _vertexBufferId;
		unsigned int _indexBufferId;
		unsigned int _nVerts;
		unsigned int _nPositionComponents;
		int _mode;
		
		Material* _material;

		VertexAttribute _attribParams;
	};
}
