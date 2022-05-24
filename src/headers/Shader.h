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

		void SetMat4(std::string name, glm::mat4& mat4);
	private:
		std::string vertexShaderString;
		std::string fragmentShaderString;

		void GetShaders(std::string vertexFilePath, std::string fragmentFilePath);
		void Compile();
	};
}