#pragma once

#include <glad.h>
#include <glfw3.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Shader
{
private:
	GLuint Program;
public:
	void CreateShader(const GLchar* vertexPath, const GLchar* fragmentPath);
	void Use();
};

