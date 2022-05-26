#pragma once

#include <GLFW/glfw3.h>

#include "Window.h"

namespace Input
{
	// Keyboard
	bool IsKeyDown(SmolEngine::Window& window, int keyCode)
	{
		if (glfwGetKey(window.GetWindow(), keyCode) == GLFW_PRESS)
			return true;
		return false;
	}
	bool IsKeyUp(SmolEngine::Window& window, int keyCode)
	{
		if (glfwGetKey(window.GetWindow(), keyCode) == GLFW_RELEASE)
			return true;
		return false;
	}

	// Mouse
	bool IsMouseButtonDown(SmolEngine::Window& window, int mouseCode)
	{
		if (glfwGetMouseButton(window.GetWindow(), mouseCode) == GLFW_PRESS)
			return true;
		return false;
	}

	bool IsMouseButtonUp(SmolEngine::Window& window, int mouseCode)
	{
		if (glfwGetMouseButton(window.GetWindow(), mouseCode) == GLFW_RELEASE)
			return true;
		return false;
	}
}