#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>

using std::cout;
using std::endl;

class DaftGame
{
public:
	DaftGame(); // ������
	~DaftGame(); // �Ҹ���

	// ó�� �����Ҷ� ����Ǵ� Init �Լ�
	void Init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen);
	
	void HandleEvents(); // �Է� ���� �̺�Ʈ �Լ�
	void Update(); // ������Ʈ �Լ�
	void Render(); // ������ �Լ� 
	void EndClear(); // ���� �Լ�

	// ������ ����ǰ� �ִ°�?
	bool RunningEngine() { return isRunning; }
private:
	int cnt = 0;
	bool isRunning; // ���α׷� ���� ���� 
	SDL_Window* window; // â (������) 
	SDL_Renderer* renderer; // ������ 
};

