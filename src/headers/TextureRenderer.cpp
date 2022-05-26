#include "TextureRenderer.h"

namespace SmolEngine
{
	TextureRenderer::TextureRenderer()
	{
		float vertices[] =
		{
			0.0f, 0.0f,
			0.0f, 1.0f,
			1.0f, 0.0f,

			1.0f, 1.0f,
			0.0f, 1.0f,
			1.0f, 0.0f
		};

		// vertex buffer object
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		// vertex array object
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		
		// unbind
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	TextureRenderer::~TextureRenderer()
	{
		glDeleteBuffers(1, &VBO);
		glDeleteVertexArrays(1, &VAO);
	}

	void TextureRenderer::Draw(glm::vec2 position, glm::vec2 scale, glm::vec4 color, Texture texture, float windowWidth, float windowHeight)
	{
		shader.Use();
		texture.Bind();

		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 projection = glm::ortho(0.0f, windowWidth, windowHeight, 0.0f);

		model = glm::translate(model, glm::vec3(position.x, position.y, 0.0f));
		model = glm::scale(model, glm::vec3(scale.x, scale.y, 0.0f));

		shader.SetMat4("model", model);
		shader.SetMat4("projection", projection);

		shader.SetVec4("Tint", glm::vec4(color.x / 255.0f, color.y / 255.0f, color.z / 255.0f, color.w / 255.0f));

		// draw triangle
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);
	}

	void TextureRenderer::DrawEntity(Texture& texture, Entity& entity, float windowWidth, float windowHeight)
	{
		Draw(glm::vec2(entity.x, entity.y), glm::vec2(entity.width, entity.height), entity.color, texture, windowWidth, windowHeight);
	}
}