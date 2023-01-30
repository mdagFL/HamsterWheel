#pragma once
#include "glew.h"
#include "Transform.h"
#include <iostream>

namespace HW
{
	class GameObject
	{
	public:
		
		GameObject();
		~GameObject();
		Transform _Transform{};
		virtual void Render() const { std::cout << "bad\n"; } // empty virtual? it's ok??
	private:

	};
}
