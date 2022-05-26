#pragma once

#include <GLAD/glad.h>
#include <GLM/glm.hpp>
#include <GLM/GTC/matrix_transform.hpp>

#include "Shader.h"
#include "Texture.h"
#include "Entity.h"

namespace SmolEngine
{
	class TextureRenderer
	{
	public:
		TextureRenderer();
		~TextureRenderer();

		void Draw(glm::vec2 position, glm::vec2 scale, glm::vec4 color, Texture texture, float windowWidth, float windowHeight);

		void DrawEntity(Texture& texture, Entity& entity, float windowWidth, float windowHeight);
	private:
		unsigned int VBO, VAO;
		Shader shader{"res/shaders/TextureVertex.glsl", "res/shaders/TextureFragment.glsl"};
	};
}