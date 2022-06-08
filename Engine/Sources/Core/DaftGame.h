#pragma once

#include <glad.h>
#include <glfw3.h>

#include <iostream>

class DaftGame
{
public:
	DaftGame();

	bool Initialize();
	void RunLoop();
	void DaftEnd();
private:
	void ProcessInput();
	void DaftUpdate();
	void GenerateOutput();

	GLFWwindow* window;
};

