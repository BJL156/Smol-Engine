#pragma once

#include <GLM/glm.hpp>

namespace SmolEngine
{
	class Entity
	{
	public:
		Entity(float X, float Y, float W, float H)
			: x(X), y(Y), width(W), height(H)
		{

		}

		float x, y;
		float width, height;
		glm::vec4 color = glm::vec4(255.0f, 255.0f, 255.0f, 255.0f);
	};
}