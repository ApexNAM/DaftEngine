#include "Triangle.h"

Triangle::Triangle()
{
	vertexShaderString = readShaderSource("./Sources/Shader/vertex.frag");
	fragmentShaderString = readShaderSource("./Sources/Shader/fragment.frag");
}

Triangle::~Triangle()
{
}

string Triangle::readShaderSource(const char* filePath)
{
	string content = "";
	ifstream fileStream(filePath, ios::in);
	string line = "";

	while (!fileStream.eof())
	{
		getline(fileStream, line);
		content.append(line + "\n");
	}
	fileStream.close();
	return content;
}

// Ʈ���̾ޱ� ����
void Triangle::Init()
{
	int success; char infoLog[512];

	// glsl �Ҿ����
	vertexShaderSource = vertexShaderString.c_str();
	fragmentShaderSource = fragmentShaderString.c_str();
	
	vertexShader = glCreateShader(GL_VERTEX_SHADER); // ���ؽ� ���̴� ����
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); // �����̸�Ʈ ���̴� ����

	// �ҽ� �ҷ�����
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);

	// ���̴� ������ �Լ�
	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);

	/*
		������ �Ϸ� ���� �ڵ�� (51 ~ 61)
	*/

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "Error : Shader::Vertex:: Comp failed\n" << infoLog << std::endl;
	}

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "Error : Shader::fragment:: Comp failed\n" << infoLog << std::endl;
	}

	shaderProgram = glCreateProgram(); // ���̴� ���α׷� ����
	glAttachShader(shaderProgram, vertexShader); // ���ؽ� ����
	glAttachShader(shaderProgram, fragmentShader); // �����̸�Ʈ ����

	glLinkProgram(shaderProgram); // ��ũȭ

	// ��ũ ����
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "Error : Shader::Program:: Link failed\n" << infoLog << std::endl;
	}

	// ���ؽ��� �����̸�Ʈ ���̴� �ʱ�ȭ 
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

// Ʈ���̾ޱ� ����
void Triangle::Create()
{
	float verticles[] = {
		-0.5f, -0.5f, 0.0f, // left
		0.5f, -0.5f, 0.0f, // right
		0.0f, 0.5f, 0.0f // top
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticles), verticles, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

// Ʈ���̾ޱ� �׸���
void Triangle::Draw()
{
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

// Ʈ���̾ޱ� ���� 
void Triangle::Delete()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);
}


void Rect::Create()
{
	float verticles[] = {
	0.5f, 0.5f, 0.0f, // left
	0.5f, -0.5f, 0.0f, // bottom right
	-0.5f, -0.5f, 0.0f, // bottom left
	-0.5f, 0.5f, 0.0f
	};

	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticles), verticles, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Rect::Draw()
{
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Rect::Delete()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteProgram(shaderProgram);
}

void Triangle::Show(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_TAB) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
