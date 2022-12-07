#include "Texture.h"
#include "glew.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace HW
{
	Texture::Texture(std::string path)
	{
		_textureBytes = stbi_load(path.c_str(), &_width, &_height, nullptr, 0);
		Init();
	}

	Texture::~Texture()
	{
		//stbi_image_free(_textureBytes);
	}

	void Texture::Init()
	{
		_targetBuffer = GL_TEXTURE_2D;
		glGenTextures(1, &_id);

		BindAndLoad();
	}

	void Texture::BindAndLoad()
	{
		glBindTexture(_targetBuffer, _id);
		glTexImage2D(_targetBuffer, 0, 4, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _textureBytes);
		_isLoaded = true;
	}

}