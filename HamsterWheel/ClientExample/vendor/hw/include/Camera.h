#pragma once
#include <string>

#include "Renderer.h"
#include "Transform.h"
#include "ShaderProgram.h"
namespace HW
{
	class Camera
	{
	public:
		Transform _worldTransform;
		Transform _screenTransform;
		Camera( ShaderProgram* shader, std::string screenUniformName );
		Camera(void);
		void Update( float delta_time );
	private:
		ShaderProgram _cameraShader;
		std::string _screenUniformName;

	};
}