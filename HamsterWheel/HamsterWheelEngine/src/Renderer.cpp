#include "Renderer.h"
#include <iostream>
#include <fstream>

using namespace HW;
unsigned int Renderer::CompileShader(const std::string& shader, ShaderType type)
{
	const char* src = shader.c_str();
	unsigned int id = glCreateShader((type == ShaderType::VERTEX) ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER);
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = new char[length];
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile " << ((type == ShaderType::VERTEX) ? "vertex" : "fragment") << "shader!" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		delete[] message;
		return 0;
	}
	return id;

}

unsigned int Renderer::CreateShaderProgram(const unsigned int vertexId, const unsigned int fragmentId)
{
	unsigned int program = glCreateProgram();
	glAttachShader(program, vertexId);
	glAttachShader(program, fragmentId);
	glLinkProgram(program);

	int result;
	glGetProgramiv(program, GL_LINK_STATUS, &result);

	if (result == GL_FALSE)
	{
		int length;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
		char* message = new char[length];
		glGetProgramInfoLog(program, length, &length, message);
		std::cout << "Failed to link shaders!" << std::endl;
		std::cout << message << std::endl;
		glDeleteProgram(program);
		delete[] message;
		return -1;
	}

	return program;
}

ShaderProgramSource Renderer::ReadShaderFile(const char* path)
{
	ShaderProgramSource source;
	std::string line;
	std::ifstream inFile(path);
	ShaderType lineType = ShaderType::VERTEX;
	while (std::getline(inFile, line))
	{
		if (line.find("#shader vertex") != std::string::npos)
			lineType = ShaderType::VERTEX;
		else if (line.find("#shader fragment") != std::string::npos)
			lineType = ShaderType::FRAGMENT;
		else
			if (lineType == ShaderType::FRAGMENT)
				source.FragmentShader.append(line);
			else if (lineType == ShaderType::VERTEX)
				source.VertexShader.append(line);
	}

	inFile.close();

	return source;
}