#pragma once

#include <string>
#include <iostream>

namespace HW
{
	class Texture
	{
	public:
		Texture(std::string path);
		~Texture();
	private:
		unsigned char* _textureBytes;
		unsigned int _id{};
	};
}