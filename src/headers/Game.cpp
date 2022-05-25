#include "Game.h"

#include "Entity.h"

namespace SmolEngine
{
	Entity e(0.0f, 0.0f, 200.0f, 200.0f);
	void Game::Init()
	{
	}

	void Game::Update()
	{
		DrawRectangle(e);
	}
}