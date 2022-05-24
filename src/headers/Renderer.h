#pragma once

#include <GLAD/glad.h>
#include <GLM/glm.hpp>
#include <GLM/GTC/matrix_transform.hpp>

#include "Shader.h"

namespace SmolEngine
{
	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		void Draw();
	private:
		unsigned int VBO, VAO;
		Shader shader{ "res/shaders/vertex.glsl", "res/shaders/fragment.glsl" };
	};
}