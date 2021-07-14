#pragma once
#include "glew.h"
#include "ShaderProgram.h"
#define GLEW_STATIC

namespace HW
{
	class Material
	{
	public:
		unsigned int _shader;
		char* _texture;
		Material(ShaderProgram& shader, char* texture) {}
		Material() {}
		~Material();
	};
}
