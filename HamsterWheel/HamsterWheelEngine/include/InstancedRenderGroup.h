#pragma once
#include "GameObject.h"
#include "RenderObject.h"

namespace HW
{
	class InstancedRenderGroup : public GameObject
	{
	public:
		InstancedRenderGroup();
		~InstancedRenderGroup();
		void Render();
	private:
		VertexArrayObject* _vao;

	};
}