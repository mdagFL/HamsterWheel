#pragma once
#define GLEW_STATIC
#include "glew.h"
#include <string>
#include "Transform.h"

namespace HW
{

	struct ShaderProgramSource
	{
	public:
		std::string VertexShader;
		std::string FragmentShader;
	};

	enum class ShaderType
	{
		VERTEX,
		FRAGMENT
	};


	class ShaderProgram
	{
	public:
		
		ShaderProgramSource ReadShaderFile(const char* path);
		unsigned int CompileShader(const std::string& source, ShaderType type);
		unsigned int CreateShaderProgram(const unsigned int veretxShader, const unsigned int fragmentShader);
		ShaderProgram(const char* path);
		void SetActive();
		void PassUniform(const char* name, const float value);
		void PassUniform(const char* name, const Vector3 value);
		ShaderProgram();
		~ShaderProgram();

	private:
		unsigned int _id;
		void Init();
		
	};

	

		const static ShaderProgramSource SHADER_SOURCE_DEFAULT = {
		// vertex shader
		"#version 330 core\n"
		"in vec4 position;\n"
		"out vec4 color;\n"
		"void main()\n"
		"{\n"
		"	gl_Position = position;\n"
		"	color = vec4(1.0, 0.0, 0.0, 1.0);\n"

		"} ",
		// fragment shader
		"	#version 330 core\n"
		"in vec4 color;\n"
		"void main()\n"
		"{\n"
		"	gl_FragColor = color;\n"
		"};" };
}
