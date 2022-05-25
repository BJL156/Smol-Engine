#pragma once

#include <GLM/glm.hpp>

#include "Renderer.h"
#include "Entity.h"

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

		/*void DrawRectangle(float x, float y, float w, float h)
		{
			renderer.Draw(glm::vec2(x, y), glm::vec2(w, h), glm::vec4(50.0f, 75.0f, 100.0f, 128.0f), WIDTH, HEIGHT);
		}*/

		void DrawRectangle(Entity& e)
		{
			renderer.Draw(glm::vec2(e.x, e.y), glm::vec2(e.width, e.height), e.color, WIDTH, HEIGHT);
		}
	private:
		const int WIDTH;
		const int HEIGHT;
		Renderer renderer;
	};
}