#include "Camera.h"
#include "Mat4.h"

#include <math.h>

namespace HW
{
	Camera::Camera()
	{
		_cameraShader = nullptr;
		_projectionMatrixUniformComponentName = "";
		_worldTranslateUniformName = "";
		_worldRotateUniformName = "";
	}

	Camera::Camera(const ShaderProgram* cameraShader, std::string worldTranslateUniformName,
		std::string worldRotateUniformName, std::string projectionMatrixUniformComponentName)
	{
		SetCameraShader(cameraShader, worldTranslateUniformName, worldRotateUniformName, projectionMatrixUniformComponentName);
	}

	void Camera::SetCameraShader(const ShaderProgram* cameraShader, std::string worldTranslateUniformName,
		std::string worldRotateUniformName, std::string projectionMatrixUniformComponentName)
	{
		_cameraShader = cameraShader;
		_worldTranslateUniformName = worldTranslateUniformName;
		_worldRotateUniformName = worldRotateUniformName;
	}

	void Camera::SetScreenFOV(float width, float height)
	{
		Mat4 orthoProjection = Mat4::OrthographicProjection(width, 0, 0, height, 500, -500);
		_cameraShader->PassUniform(_projectionMatrixUniformComponentName.c_str(), orthoProjection);
	}

	void Camera::Update(float delta_time)
	{
		this->_cameraShader->PassUniform(_worldTranslateUniformName.c_str(), _worldTransform._Position);
		this->_cameraShader->PassUniform(_worldRotateUniformName.c_str(), _worldTransform._Rotation);
	}
}