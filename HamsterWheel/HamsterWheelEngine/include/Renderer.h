#pragma once
#include "glew.h"
#include "GLFW/glfw3.h"
#include <string>

#define GLEW_STATIC
#include "RenderObject.h"

namespace HW
{
	void glErrorCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
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
	

	class Renderer
	{

	public:
		static Renderer* _Instance;

		ShaderProgramSource ReadShaderFile(const char* path);
		unsigned int CompileShader(const std::string &source, ShaderType type);
		unsigned int CreateShaderProgram(const unsigned int veretxShader, const unsigned int fragmentShader);
		void RenderObject(GameObject obj);
		
		Renderer();
		Renderer(int width, int height);
		~Renderer();

		ShaderProgramSource _DefaultShaderProgramSource = {
			// vertex shader
			"#version 330 core\n"
			"attribute vec4 position;\n"
			"varying vec4 color;\n"
			"void main()\n"
			"{\n"
			"	gl_Position = position;\n"
			"	color = vec4(1.0, 0.0, 0.0, 1.0)\n"

			"}; ",
			// fragment shader
			"	#version 330 core\n"
			"	varying vec4 color;\n"

			"void main()\n"
			"{\n"
			"	gl_FragColor = color;\n"
			"};" };
	private:
		


	};
}
