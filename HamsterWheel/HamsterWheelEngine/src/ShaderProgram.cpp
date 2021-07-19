#include "ShaderProgram.h"
#include <iostream>
#include <fstream>
using namespace HW;

unsigned int ShaderProgram::CompileShader(const std::string& shader, ShaderType type)
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

unsigned int ShaderProgram::CreateShaderProgram(const unsigned int vertexId, const unsigned int fragmentId)
{
	unsigned int program = glCreateProgram();
	glAttachShader(program, vertexId);
	glAttachShader(program, fragmentId);
	glLinkProgram(program);
	glValidateProgram(program);

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

ShaderProgramSource ShaderProgram::ReadShaderFile(const char* path)
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

ShaderProgram::ShaderProgram()
{
	unsigned int vertexShader = CompileShader(SHADER_SOURCE_DEFAULT.VertexShader, ShaderType::VERTEX);
	unsigned int fragmentShader = CompileShader(SHADER_SOURCE_DEFAULT.FragmentShader, ShaderType::FRAGMENT);
	_id = CreateShaderProgram(vertexShader, fragmentShader);
}

ShaderProgram::ShaderProgram(const char* path)
{
	ShaderProgramSource source = ReadShaderFile(path);
	unsigned int vertexShader = CompileShader(source.VertexShader, ShaderType::VERTEX);
	unsigned int fragmentShader = CompileShader(source.FragmentShader, ShaderType::FRAGMENT);
	_id = CreateShaderProgram(vertexShader, fragmentShader);
}

ShaderProgram::~ShaderProgram()
{

}

void ShaderProgram::SetActive()
{
	glUseProgram(_id);
}

void ShaderProgram::PassUniform(const char* name, const float value)
{
	int location = glGetUniformLocation(_id, name);
	glUniform1f(location, value);
}

void ShaderProgram::PassUniform(const char* name, const Vector3 value)
{
	int location = glGetUniformLocation(_id, name);
	glUniform3fv(location, 1, (float*)(&value));

}
