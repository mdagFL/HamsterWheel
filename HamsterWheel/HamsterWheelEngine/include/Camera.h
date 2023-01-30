#pragma once
#include <string>

#include "Transform.h"
#include "ShaderProgram.h"
namespace HW
{
	class Camera
	{
	public:
		Transform _worldTransform;
		Transform _screenTransform;
		Camera( const ShaderProgram* shader, std::string screenUniformName );
		Camera(void);
		void SetCameraShader(const ShaderProgram* shader, std::string screenUniformName);
		void Update( float delta_time );
	private:
		const ShaderProgram* _cameraShader;
		std::string _screenUniformName;

	};
}