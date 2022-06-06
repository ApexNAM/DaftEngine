#include "DaftGame.h"

int main(int argc, char* argv[])
{
	DaftGame* daftGame = new DaftGame();

	daftGame->Init("Daft Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	
	while (daftGame->RunningEngine())
	{
		daftGame->HandleEvents();
		daftGame->Update();
		daftGame->Render();
	}

	daftGame->EndClear();
	return 0;
}