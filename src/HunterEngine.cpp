/*---------------------------------------------
* TAMK, Ohjelmointikielet, jatko, kevät 2014
* Antti E. K. Laine 13i220a
* Harjoitustyö, laivanupotus
* Aloitus pvm: 05.02.2014
*
* HUNTER - Game Engine
* v1
*
* SOURCE
*----------------------------------------------*/

#include "HunterEngine.h"
#include "HunterUtils.h"
#include "HunterUserInterface.h"

void updateScreen (GameInstance &game, int cursorCoordinates[], bool showCursor) {
	if (showCursor)
		game.updateCursor (cursorCoordinates);
	game.updateFrame ();
	setCursorPosition(0,0);
	printBoard (game);
}
void printBoard (GameInstance &game) {
	for (int row = 0; row < game.rows; row++) {
		for (int col = 0; col < game.columns; col++) {
			cout << setw(2) << game.board[row][col];
		}
		cout << "\n";
	}
}
void gameLoop (GameInstance &game) {
	bool exit = false;
	int coordinates[2];
	while (!exit) {
		placeShipsManually (game);
		askForCoordinates (coordinates);
		updateScreen (game, coordinates, true);
	}
}
void placeShipsManually (GameInstance &game) {
	int shipPosition[4];
	for (int i = 2; i < 6; i++) {
		shipPosition[0] = i;
		askForShipPosition (shipPosition);
		while (!game.addShipToBoard(shipPosition))
			askForShipPosition (shipPosition);
	}
}