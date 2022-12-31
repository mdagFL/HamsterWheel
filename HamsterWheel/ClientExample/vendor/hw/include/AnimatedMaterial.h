#pragma once
#include "Material.h"
#include "Sprite.h"

namespace HW
{
	class AnimatedMaterial : public Material
	{
	public:
		Sprite _sprite;
		AnimatedMaterial(const ShaderProgram shaderPrefab, const Sprite spritePrefab);
		void Update(float delta_time) override;
	};
}
