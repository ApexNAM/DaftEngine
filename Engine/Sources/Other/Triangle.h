#pragma once

#include <glad.h>
#include <glfw3.h>

#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::ifstream;
using std::ios;

class Triangle
{
private:
	unsigned int VBO, VAO, EBO;
	unsigned int vertexShader;
	unsigned int fragmentShader;
	unsigned int shaderProgram;

	string readShaderSource(const char* filePath);

	string vertexShaderString;
	string fragmentShaderString;

	const char* vertexShaderSource;
	const char* fragmentShaderSource;

public:
	Triangle();
	~Triangle();

	void Init();
	void Create();
	void CreateRect();

	void Draw();
	void DrawRect();

	void DeleteTriangle();
	void DeleteRect();

	void Show(GLFWwindow* window);
};

