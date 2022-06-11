#pragma once

#include <glad.h>
#include <glfw3.h>

#include <iostream>
#include "../Other/Triangle.h"

enum ObjectType
{
	TriangleType,
	RectType
};

class DaftGame
{
public:
	DaftGame() 
	{
	};

	bool Initialize();
	void RunLoop();
	void DaftEnd();
private:
	void ProcessInput();
	void DaftUpdate();
	void GenerateOutput();

	GLFWwindow* window;
	Triangle triangle;
	ObjectType objType = RectType;
};

