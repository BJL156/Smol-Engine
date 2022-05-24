#pragma once

#include "Window.h"
#include "Renderer.h"
#include "Shader.h"

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
				renderer.Draw();
			}
		}
	private:
		Window window{WIDTH, HEIGHT, "Smol Engine"};
		Renderer renderer;
	};
}