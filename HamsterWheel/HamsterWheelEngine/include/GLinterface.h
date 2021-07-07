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

	static int CompileShader(unsigned int program)
	{

	}

	static int CreateShader(std::string vertex, std::string fragment)
	{

	}

	static ShaderProgramSource ReadShaderFile(const std::string& path)
	{
		ShaderProgramSource source;
		std::string line;
		std::ifstream inFile(path);
		bool isFragmentSource;

		while (std::getline(inFile, line))
		{
			if (line.find("#shader vertex"))
				isFragmentSource = false;
			else if (line.find("#shader fragment"))
				isFragmentSource = true;
			else
				std::cout << line << std::endl;
		}


	}


}