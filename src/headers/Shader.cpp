#include "Shader.h"

namespace SmolEngine
{
	Shader::Shader(std::string vertexFilePath, std::string fragmentFilePath)
	{
		Compile(vertexFilePath, fragmentFilePath);
	}

	void Shader::Compile(std::string& vertexFilePath, std::string& fragmentFilePath)
	{
		// get shader sources
		const char* vertexShaderSource = ReadFile(vertexFilePath);
		const char* fragmentShaderSource = ReadFile(fragmentFilePath);

		std::cout << vertexShaderSource << std::endl;
		std::cout << fragmentShaderSource << std::endl;

		// create shader program
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
		glCompileShader(vertexShader);

		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
		glCompileShader(fragmentShader);

		ID = glCreateProgram();
		glAttachShader(ID, vertexShader);
		glAttachShader(ID, fragmentShader);
		glLinkProgram(ID);

		// the shaders are now no longer needed
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	void Shader::Use()
	{
		glUseProgram(ID);
	}

	const char* Shader::ReadFile(std::string& filePath)
	{
		std::fstream file(filePath);
		std::stringstream fileStream;

		if (file.is_open()) {
			std::string line;
			while (std::getline(file, line)) {
				fileStream << line << std::endl;
			}
		}
		std::string fileString = fileStream.str();

		return fileString.c_str();
	}
}