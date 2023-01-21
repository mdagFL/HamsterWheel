#include "Material.h"

namespace HW
{
	Material::Material()
	{
		_shaderProgram = new ShaderProgram();
		_texture = nullptr;
	}
	void Material::Update(float delta_time)
	{

	}
	Material::~Material()
	{
		if (_texture != nullptr)
			delete _texture;
		delete _shaderProgram;
	}
}
