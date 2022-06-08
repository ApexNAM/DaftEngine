#include "DaftGame.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

DaftGame::DaftGame()
{
}

bool DaftGame::Initialize()
{
	glfwInit();

	if (!glfwInit())
	{
		std::cout << "Error : Failed GLFW" << std::endl;
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(1024, 768, "Daft Engine", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Error : Failed Window" << std::endl;
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Error : Failed Init GLAD" << std::endl;
		return false;
	}

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	return true;
}

void DaftGame::RunLoop()
{
	while (!glfwWindowShouldClose(window))
	{
		ProcessInput();
		DaftUpdate();
		GenerateOutput();
	}
}

void DaftGame::DaftEnd()
{
	glfwTerminate();
}

void DaftGame::ProcessInput()
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	glfwSwapBuffers(window);
	glfwPollEvents();
}

void DaftGame::DaftUpdate()
{
}

void DaftGame::GenerateOutput()
{
}
