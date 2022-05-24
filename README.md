# Smol Graphics Engine
SmolGE (Smol Graphics Engine) is was made mostly for me further deepen my skills with OpenGL.

This is my second attempt on making a game tool with OpenGL my first was called "OpenGL Game Test" which can be found here: https://github.com/BJL156/OpenGL-Game-Test.

## Front End
Games are written in the `Game.cpp` file were it looks something along the lines of this:
```
#include "Game.h"

namespace SmolEngine
{
	void Game::Init()
	{
  
	}

	void Game::Update()
	{
  
	}
}
```

## Drawing Rectangles
Rectangles are incredibly easy to draw there is only one method that needs to be called which is `void DrawRectangle(float x, float y, float w, float h)` That add the arguments for the rectangle. This needs to be called in the `void Update()` method because the rectangle should be drawn to the screen each frame.
```
void Game::Update()
{
  DrawRectangle(0.0f, 0.0f, 100.0f, 100.0f);
}
```
