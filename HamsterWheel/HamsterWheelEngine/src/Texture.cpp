#include "Texture.h"
#include "stb_image.h"

namespace HW
{
	Texture::Texture(std::string path)
	{
		_textureBytes = stbi_load(path.c_str(), nullptr, nullptr, nullptr, 0);
	}

	Texture::~Texture()
	{
		stbi_image_free(_textureBytes);
	}
}