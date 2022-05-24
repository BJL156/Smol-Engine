#pragma once

#include <GLM/glm.hpp>

#include "Renderer.h"

namespace SmolEngine
{
	class Game
	{
	public:
		Game(int w, int h)
			: WIDTH(w), HEIGHT(h)
		{
			Init();
		}

		void Init();

		void Update();

		void DrawRectangle(float x, float y, float w, float h)
		{
			renderer.Draw(glm::vec2(x, y), glm::vec2(w, h), WIDTH, HEIGHT);
		}
	private:
		const int WIDTH;
		const int HEIGHT;
		Renderer renderer;
	};
}