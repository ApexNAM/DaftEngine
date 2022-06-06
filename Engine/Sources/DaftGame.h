#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>

using std::cout;
using std::endl;

class DaftGame
{
public:
	DaftGame();
	~DaftGame();

	void Init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen);
	
	void HandleEvents();
	void Update();
	void Render();
	void EndClear();

	bool RunningEngine() { return isRunning; }
private:
	int cnt = 0;
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};

