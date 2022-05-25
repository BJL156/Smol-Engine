#include "Texture.h"

namespace SmolEngine
{
	Texture::Texture(std::string imageFilePath)
	{
		int numChannels;
		unsigned char* data = stbi_load(imageFilePath.c_str(), &width, &height, &numChannels, 0);

		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		// wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

		// filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
			std::cout << "FAILED TO LOAD IMAGE" << std::endl;
		stbi_image_free(data);
	}

	void Texture::Bind()
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);
	}
}