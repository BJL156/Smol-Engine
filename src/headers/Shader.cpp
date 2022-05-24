#include "Shader.h"

namespace SmolEngine
{
	Shader::Shader(std::string vertexFilePath, std::string fragmentFilePath)
	{
		GetShaders(vertexFilePath, fragmentFilePath);
		Compile();
	}

	void Shader::GetShaders(std::string vertexFilePath, std::string fragmentFilePath)
	{
		// get vertex shader source
		std::fstream vertexFile;
		std::stringstream vertexStream;

		vertexFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		try
		{
			vertexFile.open(vertexFilePath);
			vertexStream << vertexFile.rdbuf();
			vertexFile.close();
		}
		catch (std::ifstream::failure exception)
		{
			std::cout << "FAILED TO READ VERTEX SHADER FILE" << std::endl;
		}

		vertexShaderString = vertexStream.str();

		// get fragment shader source
		std::fstream fragmentFile;
		std::stringstream fragmentStream;

		fragmentFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		try
		{
			fragmentFile.open(fragmentFilePath);
			fragmentStream << fragmentFile.rdbuf();
			fragmentFile.close();
		}
		catch (const std::exception&)
		{
			std::cout << "FAILED TO READ FRAGMENT SHADER FILE" << std::endl;
		}

		fragmentShaderString = fragmentStream.str();
	}

	void Shader::Compile()
	{
		// create shader program
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		const char* vertexShaderSource = vertexShaderString.c_str();
		glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
		glCompileShader(vertexShader);

		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		const char* fragmentShaderSource = fragmentShaderString.c_str();
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

	void Shader::SetMat4(std::string name, glm::mat4& mat4)
	{
		glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat4[0][0]);
	}
}