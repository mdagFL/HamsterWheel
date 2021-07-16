#pragma once
#include "glew.h"
#include "Transform.h"

namespace HW
{
	class GameObject
	{
	public:
		
		GameObject();
		~GameObject();
		Transform _Transform;
		virtual void Render() const {} // empty virtual? it's ok??
	private:

	};
}
