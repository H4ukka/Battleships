
#include "HunterEngine.h"

int main () {
	GameInstance demo;
	demo.gameColumns = 20;
	demo.gameRows = 20;
	demo.createBoard();
	demo.clearBoard ();
	gameLoop (demo);
	return EXIT_SUCCESS;
}