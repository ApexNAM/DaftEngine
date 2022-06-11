#pragma once

#include "../Render/Shader.h"

class DrawObject
{
private:
	unsigned int VBO, VAO;
	Shader ourShader;
public:
	DrawObject();
	~DrawObject();

	void Init();
	void Draw();
	void RemoveDelete();
};

