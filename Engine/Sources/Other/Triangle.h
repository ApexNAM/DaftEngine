#pragma once

#include <glad.h>
#include <glfw3.h>

#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::ifstream;
using std::ios;

// Ʈ���̾ޱ� Ŭ����
class Triangle
{
protected:
	/*
		Vertex Buffer Object
		Vertex Array Object
		Element Buffer Object

		unsigned int var
	*/
	unsigned int VBO, VAO, EBO;


	unsigned int vertexShader; // ���ؽ� ���̴�
	unsigned int fragmentShader; // �����׸�Ʈ ���̴�
	unsigned int shaderProgram; // ���̴� ���α׷�

	// glsl ���� �б�
	string readShaderSource(const char* filePath);

	// glsl ������ �б� ���� string ����
	string vertexShaderString, fragmentShaderString;

	// string ���� �������� �ҽ�
	const char* vertexShaderSource;
	const char* fragmentShaderSource;

public:
	Triangle();
	~Triangle();

	void Init();

	virtual void Create();
	virtual void Draw();
	virtual void Delete();

	void Show(GLFWwindow* window);
};

// Rect�� ���� Ʈ���̾ޱ� �ڽ� Ŭ����
class Rect : public Triangle
{
public:
	virtual void Create();
	virtual void Draw();
	virtual void Delete();
};