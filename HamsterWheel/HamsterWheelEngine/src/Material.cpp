#include "Material.h"

using namespace HW;
Material::Material()
{
	_shaderProgram = new ShaderProgram();
	_texture = nullptr;
}
Material::~Material()
{
	if (_texture != nullptr)
		delete _texture;
	delete _shaderProgram;
}