#pragma once

#include <string>
#include <iostream>
#include <fstream>

#include "glew.h"

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
		Vertex,
		Fragment
	};

	ShaderProgramSource DefaultShaderProgramSource = {
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
	static int CompileShader(const std::string &shader, ShaderType type)
	{
		const char* src = shader.c_str();
		unsigned int id = glCreateShader((type == ShaderType::Vertex)? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER);
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
			std::cout << "Failed to compile " << ((type == ShaderType::Vertex) ? "vertex" : "fragment") << "shader!" << std::endl;
			std::cout << message << std::endl;
			glDeleteShader(id);
			return -1;
		}

	}

	static int CreateShader(const std::string &vertex, const std::string &fragment)
	{
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		const char* vertexSrc = vertex.c_str();
		const char* fragmentSrc = fragment.c_str();
		glShaderSource(vertexShader, 1, &vertexSrc, nullptr);
		glShaderSource(fragmentShader, 1, &fragmentSrc, nullptr);

	}

	static ShaderProgramSource ReadShaderFile(const std::string& path)
	{
		ShaderProgramSource source;
		std::string line;
		std::ifstream inFile(path);
		ShaderType lineType = ShaderType::Vertex;
		while (std::getline(inFile, line))
		{
			if (line.find("#shader vertex") != std::string::npos)
				lineType = ShaderType::Vertex;
			else if (line.find("#shader fragment") != std::string::npos)
				lineType = ShaderType::Fragment;
			else
				if (lineType == ShaderType::Fragment)
					source.FragmentShader.append(line);
				else if (lineType == ShaderType::Vertex)
					source.VertexShader.append(line);
		}

		inFile.close();

		return source;
	}


}