#pragma once

#include <GLAD/glad.h>
#include "STB_IMAGE/stb_image.h"

#include <string>
#include <iostream>

namespace SmolEngine
{
	class Texture
	{
	public:
		int width, height;
		Texture(std::string imageFilePath);

		void Bind();
	private:
		unsigned int texture;
	};
}