/*---------------------------------------------
*
* TAMK, Ohjelmointikielet, jatko, kevät 2014
* Antti E. K. Laine 13i220a
* Harjoitustyö, laivanupotus
* Aloitus pvm: 05.02.2014
*
* HUNTER - Game Engine User Interface
* v1
*
* SOURCE
*
*----------------------------------------------*/

#include "HunterUserInterface.h"

void setCursorPosition (int x, int y) {
	COORD position = {x ,y};
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, position);
}

void translateCoordinates (int output[], char input[]) {
}

void askForCoordinates (int coordinates[]) {
	std::cout << "\t\nAnna ampumiskoordinaatit: ";
	std::cin >> coordinates[0] >> coordinates[1];
}

void askForShipPosition (int shipPosition[]) {
	std::cout << "\t\nAnna " << shipPosition[0] << " pituisen laivan sijoituspiste: ";
}

