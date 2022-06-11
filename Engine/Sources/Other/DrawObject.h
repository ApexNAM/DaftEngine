#pragma once

#include "../Render/Shader.h"

class DrawObject
{
private:
	GLuint VBO, VAO;
	Shader ourShader;
public:
	DrawObject();
	~DrawObject();

	void Init();
	void Draw();
	void RemoveDelete();
};

