#include <DaftGame.h>
#include <iostream>

int main()
{
	DaftGame game;
	bool success = game.Initialize();

	if (success) {
		game.RunLoop();
	}

	game.DaftEnd();
	return 0;
}