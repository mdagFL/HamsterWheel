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
		void SetScreenFOV(float width, float height);
		// projectionMatrixUniformComponentName will have 0 to 3 appended for each column.
		Camera( const ShaderProgram* shader, std::string worldTranslateUniformName, std::string worldRotateUniformName,
			std::string projectionMatrixUniformComponentName );
		Camera(void);
		void SetCameraShader(const ShaderProgram* shader, std::string screenUniformName, std::string worldRotateUniformName,
			std::string projectionMatrixUniformComponentName);
		void Update( float delta_time );
	private:
		const ShaderProgram* _cameraShader;
		std::string _projectionMatrixUniformComponentName;
		std::string _worldTranslateUniformName;
		std::string _worldRotateUniformName;
	};
}