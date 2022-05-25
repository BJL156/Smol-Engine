# Smol Game Engine
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
##### Draw Without an Entity Class
Drawing without entities has fewer steps then drawing with entities. Drawing without may not be the best solution for you check out "Draw With an Entity Class" to see if you should be using an entity class.

Rectangles are incredibly easy to draw. This is because there is only one method that needs to be called which is:

`void DrawRectangle(float x, float y, float w, float h)`

This needs to be called in the `void Update()` method because the rectangle should be drawn to the screen each frame. This should look something like this:
```
void Game::Update()
{
  DrawRectangle(0.0f, 0.0f, 100.0f, 100.0f);
}
```
##### Draw With an Entity Class
An Entity can be used for creating instances of postional and scaling data. This data can then be passed to a draw call that will draw geometry using the data from the entity class.

An Entity class is made with the consturctor:
```
Entity(float X, float Y, float W, float H)
```
Then the `DrawRectangle(Entity& e)` method should be used in the `void Update()` method in order for the geomtery to continue being draw to the screen. Here is an example of this being used:
```
Entity e(0.0f, 0.0f, 200.0f, 200.0f);
void Game::Update()
{
  DrawRectangle(e);
}
```
