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
		stbi_image_free(_textureBytes);
	}

	void Texture::Init()
	{
		_targetBuffer = GL_TEXTURE_2D;
		glGenTextures(1, &_id);
		_uvBuffer = new float[8]
		{
			0, 0,
			1, 0,
			1, 1,
			0, 1
		};

		BindAndLoad();
	}

	void Texture::BindAndLoad()
	{
		glBindTexture(_targetBuffer, _id);
		glTexImage2D(_targetBuffer, 0, GL_RGBA, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _textureBytes);
		glGenerateMipmap(GL_TEXTURE_2D);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		_isLoaded = true;
	}

}