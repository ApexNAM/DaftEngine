#pragma once

#include <glad.h>
#include <glfw3.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Shader
{
public:
	Shader();
	~Shader();

	GLuint Program;

	void CreateShader(const GLchar* vertexPath, const GLchar* fragmentPath);
	void Use();
};

