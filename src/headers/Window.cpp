#include "Window.h"

namespace SmolEngine
{
	Window::Window(const int w, const int h, std::string name)
		: width(w), height(h)
	{
		CreateWindow(name);
	}

	Window::~Window()
	{
		// destory everything before terminating GLFW
		glfwDestroyWindow(window);

		glfwTerminate();
	}

	void Window::Update()
	{
		glfwSwapBuffers(window);
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Window::CreateWindow(std::string& name)
	{
		glfwInit();

		// set which OpenGL version that will be used
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			std::cout << "FAILED TO INITIALIZE GLAD" << std::endl;

		// make transparency transparent
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
	}
}