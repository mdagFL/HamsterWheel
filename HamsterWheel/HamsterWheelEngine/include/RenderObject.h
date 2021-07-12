#include "GameObject.h"
#pragma once

struct VertexAttribParams
{
	int _attribIndex;
	int _attribStride;
	int _attribComponents;
	int _attribType;
	int _attribOffset;
	VertexAttribParams(int attribIndex, int attribStride, int attribComponents, int attribType, int attribOffset)
		: _attribIndex{ attribIndex }, _attribStride{ attribStride }, _attribComponents{ attribComponents },
		_attribType{ attribType }, _attribOffset{ attribOffset } {}
	VertexAttribParams() {}

};

namespace HW
{
	class RenderObject : public HW::GameObject
	{
	public:
		

		RenderObject();
		RenderObject(float* vertexBuffer, int* elementBuffer, VertexAttribParams params);
		~RenderObject();
	private:
		float* _vertexBuffer;
		int* _elementBuffer;


		VertexAttribParams _attribParams;
	};
}
