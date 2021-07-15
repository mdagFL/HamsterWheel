#pragma once
#define GLEW_STATIC
#include "glew.h"
#include "ShaderProgram.h"
#include "Texture.h"


namespace HW
{
	class Material
	{
	public:
		ShaderProgram* _shaderProgram;
		Texture* _texture;
		Material(ShaderProgram& shader, char* texture) {}
		Material() {}
		~Material();
	};
}
