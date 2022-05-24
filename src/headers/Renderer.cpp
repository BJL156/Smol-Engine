#include "Renderer.h"

namespace SmolEngine
{
	Renderer::Renderer()
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

		// set up projection
	}

	Renderer::~Renderer()
	{
		glDeleteBuffers(1, &VBO);
		glDeleteVertexArrays(1, &VAO);
	}

	void Renderer::Draw(glm::vec2 position, glm::vec2 scale, float windowWidth, float windowHeight)
	{
		shader.Use();

		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 projection = glm::ortho(0.0f, windowWidth, windowHeight, 0.0f);

		model = glm::translate(model, glm::vec3(position.x, position.y, 0.0f));
		model = glm::scale(model, glm::vec3(scale.x, scale.y, 0.0f));

		shader.SetMat4("model", model);
		shader.SetMat4("projection", projection);

		// draw triangle
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);
	}
}