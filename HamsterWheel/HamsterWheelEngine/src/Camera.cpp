#include "Camera.h"
#include <math.h>

namespace HW
{
	Camera::Camera()
	{
		_cameraShader = nullptr;
		_screenUniformName = "";
	}

	Camera::Camera(const ShaderProgram* cameraShader, std::string screenUniformName)
	{
		SetCameraShader(cameraShader, screenUniformName);
	}

	void Camera::SetCameraShader(const ShaderProgram* cameraShader, std::string screenUniformName)
	{
		_cameraShader = cameraShader;
		_screenUniformName = screenUniformName;
	}

	void Camera::Update(float delta_time)
	{
		static float time = 0;
		time += 0.01;
		_screenTransform._Position.X += sin(time);

		this->_cameraShader->PassUniform(_screenUniformName.c_str(), _screenTransform._Position);
	}
}