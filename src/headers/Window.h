#pragma once

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

#include <GLM/glm.hpp>

#include <string>
#include <iostream>

namespace SmolEngine
{
	class Window
	{
	public:
		Window(const int w, const int h, std::string name);
		~Window();

		void Update();

		bool ShouldClose() { return glfwWindowShouldClose(window); }
	private:
		void CreateWindow(std::string& name);

		const int width;
		const int height;
		
		GLFWwindow* window;
	};
}