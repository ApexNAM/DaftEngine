#include "DaftGame.h"

DaftGame::DaftGame()
{
}

DaftGame::~DaftGame()
{
}

void DaftGame::Init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen)
{
	int daftFlags = 0;
	
	// fullScreen이면 daftFlag를 fullScreen으로.
	if (fullScreen) {
		daftFlags = SDL_WINDOW_FULLSCREEN;
	}

	// SDL_Init가 0이면 윈도우와 렌더러를 생성해준다.
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "SubSystem Init!" << endl;

		window = SDL_CreateWindow(title, xPos, yPos, width, height, daftFlags);

		if (window) {
			cout << "Window Create!" << endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			cout << "Renderer Create!" << endl;
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}
}

void DaftGame::HandleEvents()
{
	SDL_Event daftEvent;
	SDL_PollEvent(&daftEvent);

	switch (daftEvent.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void DaftGame::Update()
{
	cnt++;
}

void DaftGame::Render()
{
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}

// Daft Engine이 종료되면, SDL 관련 부분을 제거해줍니다.
void DaftGame::EndClear()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Daft Engine Ended!" << endl;
}

