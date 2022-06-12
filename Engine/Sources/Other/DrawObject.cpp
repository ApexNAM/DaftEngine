#include "DrawObject.h"

void DrawObject::Init()
{
    ourShader.CreateShader("./Sources/Shader/default.vert", "./Sources/Shader/default.frag");

	float vertices[] = {
        // positions         // colors
         0.5f, -0.5f, 0.0f,     1.0f, 0.0f, 0.0f,  // bottom right
          -0.5f, -0.5f, 0.0f,     0.0f, 1.0f, 0.0f,  // bottom left
         0.0f,  0.5f, 0.0f,      0.0f, 0.0f, 1.0f   // top 
	};

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

void DrawObject::Draw()
{
    ourShader.Use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void DrawObject::RemoveDelete()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}
