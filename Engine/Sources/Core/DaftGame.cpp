#include "DaftGame.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
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
	triangle.Init();
	return true;
}

void DaftGame::RunLoop()
{
	if (objType == ObjectType::TriangleType)
		triangle.Create();
	else if (objType == ObjectType::RectType)
		triangle.CreateRect();

	while (!glfwWindowShouldClose(window))
	{
		ProcessInput();
		DaftUpdate();
		GenerateOutput();
	}
}

void DaftGame::DaftEnd()
{
	if (objType == ObjectType::TriangleType)
		triangle.DeleteTriangle();
	else if (objType == ObjectType::RectType)
		triangle.DeleteRect();

	glfwTerminate();
}

void DaftGame::ProcessInput()
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	triangle.Show(window);
}

void DaftGame::DaftUpdate()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	if (objType == ObjectType::TriangleType)
		triangle.Draw();
	else if (objType == ObjectType::RectType)
		triangle.DrawRect();
}

void DaftGame::GenerateOutput()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}
