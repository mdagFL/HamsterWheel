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
		const ShaderProgram* _shaderProgram;
		const Texture* _texture;
		Material(const ShaderProgram* shaderProgram, const Texture* texture)
			: _shaderProgram{ shaderProgram }, _texture{ texture } {}
		Material();
		~Material();
	};
}
