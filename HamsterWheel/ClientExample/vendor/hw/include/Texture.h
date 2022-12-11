
#pragma once
#include <string>
#include <iostream>
#include "glew.h"
namespace HW
{
	class Texture
	{
	public:
		Texture(std::string path);
		~Texture();

		// Return openGL assigned ID
		unsigned int GetId() const { return _id; }


	private:
		void Init();

		// Bind and load the texture to OpenGL context
		void BindAndLoad();

		bool _isLoaded;
		unsigned char* _textureBytes;
		unsigned int _id{};
		int _width;
		int _height;
		GLenum _targetBuffer;
	};
}