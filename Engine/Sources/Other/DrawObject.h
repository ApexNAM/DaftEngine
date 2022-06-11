#pragma once

#include "../Render/Shader.h"

class DrawObject
{
private:
	GLuint VBO, VAO;
	Shader ourShader;
public:
	void Init();
	void Draw();
	void RemoveDelete();
};

