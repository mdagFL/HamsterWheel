#include "ShaderProgram.h"
#include <iostream>
#include <fstream>

namespace HW
{
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

	unsigned int ShaderProgram::CreateShaderProgram(const std::string& vertex, const std::string& fragment)
	{
		unsigned int program = glCreateProgram();

		unsigned int vertexId = CompileShader(vertex, ShaderType::VERTEX);
		unsigned int fragmentId = CompileShader(fragment, ShaderType::FRAGMENT);

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
					source.FragmentShader.append(line + "\n");
				else if (lineType == ShaderType::VERTEX)
					source.VertexShader.append(line + "\n");
		}

		inFile.close();

		return source;
	}

	ShaderProgram::ShaderProgram()
	{
		Init(nullptr);
	}

	ShaderProgram::ShaderProgram(const char* path)
	{
		Init(path);
	}

	void ShaderProgram::Init(const char* path)
	{
		if (path == nullptr)
			_id = CreateShaderProgram(SHADER_SOURCE_DEFAULT.VertexShader, SHADER_SOURCE_DEFAULT.FragmentShader);
		else
		{
			ShaderProgramSource source = ReadShaderFile(path);
			_id = CreateShaderProgram(source.VertexShader, source.FragmentShader);
		}
	}

	ShaderProgram::~ShaderProgram()
	{

	}

	void ShaderProgram::SetActive() const
	{
		glUseProgram(_id);
	}

	void ShaderProgram::PassUniform(const std::string& name, const float value) const
	{
		SetActive();
		int location = glGetUniformLocation(_id, name.c_str());
		glUniform1f(location, value);
	}

	void ShaderProgram::PassUniform(const std::string& name, const Vector3& value) const
	{
		SetActive();
		int location = glGetUniformLocation(_id, name.c_str());
		glUniform3fv(location, 1, (float*)(&value));

	}

}
