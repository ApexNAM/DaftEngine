#pragma once

#include <glad.h>
#include <glfw3.h>

#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::ifstream;
using std::ios;

// 트라이앵글 클래스
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


	unsigned int vertexShader; // 버텍스 쉐이더
	unsigned int fragmentShader; // 프레그먼트 쉐이더
	unsigned int shaderProgram; // 쉐이더 프로그램

	// glsl 파일 읽기
	string readShaderSource(const char* filePath);

	// glsl 파일을 읽기 위한 string 변수
	string vertexShaderString, fragmentShaderString;

	// string 변수 가져오기 소스
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

// Rect를 위한 트라이앵글 자식 클래스
class Rect : public Triangle
{
public:
	virtual void Create();
	virtual void Draw();
	virtual void Delete();
};