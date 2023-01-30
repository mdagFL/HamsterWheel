#include "Camera.h"

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
		glUniform3fv(glGetUniformLocation(_cameraShader->GetId(), _screenUniformName.c_str()), 1, &_screenTransform._Position.X);
	}
}