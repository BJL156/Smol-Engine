#pragma once

#include "Window.h"
#include "Renderer.h"
#include "Shader.h"
#include "Game.h"

namespace SmolEngine
{
	class Application
	{
	public:
		const int WIDTH = 800;
		const int HEIGHT = 600;

		void Run()
		{
			while (!window.ShouldClose()) {
				window.Update();
				game.Update();
			}
		}
	private:
		Window window{WIDTH, HEIGHT, "Smol Engine"};
		Game game{WIDTH, HEIGHT};
	};
}