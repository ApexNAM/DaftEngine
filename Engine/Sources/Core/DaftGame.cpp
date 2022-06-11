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
	// glfwWindowHint(GLFW_DECORATED, false); // 윈도우 타이틀바 비활성화

	window = glfwCreateWindow(1280, 720, "Daft Engine", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Error : Failed Window" << std::endl;
		glfwTerminate();
		return false;
	}

	// glfwSetWindowPos(window, 300,150 );
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Error : Failed Init GLAD" << std::endl;
		return false;
	}

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	drawObj.Init();
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

	drawObj.RemoveDelete();
}

void DaftGame::DaftEnd()
{
	glfwTerminate();
}

void DaftGame::ProcessInput()
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_TAB) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void DaftGame::DaftUpdate()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	drawObj.Draw();
}

void DaftGame::GenerateOutput()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}
