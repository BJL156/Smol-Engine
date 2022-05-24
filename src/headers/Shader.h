#pragma once

#include <GLAD/glad.h>
#include <GLM/glm.hpp>

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

namespace SmolEngine
{
	class Shader
	{
	public:
		unsigned int ID;
		Shader(std::string vertexFilePath, std::string fragmentFilePath);

		void Use();
	private:
		void Compile(std::string& vertexFilePath, std::string& fragmentFilePath);
		const char* ReadFile(std::string& filePath);
	};
}