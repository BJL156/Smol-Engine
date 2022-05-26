#include "headers/Window.h"
#include "headers/TextureRenderer.h"
#include "headers/Renderer.h"
#include "headers/Entity.h"
#include "headers/Input.h"
#include "headers/InputCodes.h"

int main()
{
	// set up
	SmolEngine::Window window(800, 600, "Samurai Game");
	SmolEngine::Renderer renderer;
	SmolEngine::TextureRenderer textureRenderer;

	// load textures
	SmolEngine::Texture ourTexture("res/textures/chicken.png");

	// create entities
	SmolEngine::Entity ourEntity(0.0f, 0.0f, 100.0f, 100.0f);

	while (!window.ShouldClose())
	{
		window.Update();

		// draw entities
		textureRenderer.DrawEntity(ourTexture, ourEntity, window.GetWidth(), window.GetHeight());
	}
}