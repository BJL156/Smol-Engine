# Smol Game Engine
SmolGE (Smol Game Engine) is was made mostly for me further deepen my skills with OpenGL.

This is my second attempt on making a game tool with OpenGL my first was called "OpenGL Game Test" which can be found here: https://github.com/BJL156/OpenGL-Game-Test.

## Front End
Games are written in the `Game.cpp` file were it looks something along the lines of this:
```
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

	while (!window.ShouldClose())
	{
		window.Update();
		
	}
}
```

## Drawing Rectangles
An Entity can be used for creating instances of postional and scaling data. This data can then be passed to a draw call that will draw geometry using the data from the entity class.

An Entity class is made with the follwing constructor **which is in the `SmolEngine` namespace**:
```
Entity(float X, float Y, float W, float H)
```
##### Changing the Color
The color can be changed with the entity class. In the entity that was created there is a public variable called `color` this is a `glm::vec4`. Here is an example changing the color to red:
```
ourEntity.color = glm::vec4(255.0f, 0.0f, 0.0f, 255.0f);
```

##### Draw Solid Colors
Then the `DrawEntity(Entity& entity, float windowWidth, float windowHeight)` method should be called. This is a method from the `Renderer` class to draw solid colors.

##### Draw Textures
Then the `DrawEntity(Texture& texture, Entity& entity, float windowWidth, float windowHeight)` method should be called. This is a method from the `TextureRenderer` class to draw textures. This takes a texture which can be created with the `Texture` class which is found in the `SmolEngine` namespace.

##### Drawing Solid Colors and Textured Entities Example
Here is drawing both a chicken image and solid white color:
```
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

	// create entities
	SmolEngine::Entity ourEntity(0.0f, 0.0f, 100.0f, 100.0f);
	
	// load textures
	SmolEngine::Texture ourTexture("res/textures/chicken.png");
	
	while (!window.ShouldClose())
	{
		window.Update();

		// draw solid color entity
		renderer.DrawEntity(ourEntity, window.GetWidth(), window.GetHeight());
		
		// draw textures
		textureRenderer.DrawEntity(ourTexture, ourEntity, window.GetWidth(), window.GetHeight());
	}
}
```
