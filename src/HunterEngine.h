/*---------------------------------------------
*
* TAMK, Ohjelmointikielet, jatko, kevät 2014
* Antti E. K. Laine 13i220a
* Harjoitustyö, laivanupotus
* Aloitus pvm: 05.02.2014
*
* HUNTER - Game Engine
* v1
*
* HEADER
*
*----------------------------------------------*/

#include <vector>
#include <string>

using namespace std;

const int WINDOW_PADDING = 4;
const int FRAME_VERTICAL_WIDTH = 4;
const int FRAME_HORIZONTAL_HEIGHT = 4;

const char CURSOR = 'X';
const char EMPTY_CELL = ' ';
const char CORNER_LEFT_UP = (char)200;
const char CORNER_LEFT_DOWN = (char)201;
const char CORNER_RIGHT_UP = (char)188;
const char CORNER_RIGHT_DOWN = (char)187;
const char VERTICAL_LINE = (char)186;
const char HORIZONTAL_LINE = (char)205;

const char FRAME_MARKINGS[] = {'1', 'A'};

struct GameInstance {
	int rows, columns;
	int gameRows, gameColumns;
	int cursorData[3];
	vector < vector<char> > board;
	vector < vector<char> > gameArea;
	void clearBoard () {
		for (int row = 0; row < gameRows; row++) {
			for (int col = 0; col < gameColumns; col++) {
				gameArea[row][col] = EMPTY_CELL;
			}
		}
	}
	void createBoard () {
		/*--------------------------------------------------
		*
		* nimi: createBoard
		* toiminta: Luo uuden pelialueen.
		* parametri(t): Rivien ja sarakkeiden lukumäärä.
		* paluuarvo(t): -
		*
		*--------------------------------------------------*/
		rows = gameRows + WINDOW_PADDING;
		columns = gameColumns + WINDOW_PADDING;
		gameArea.resize(gameRows);
		for (int i = 0; i < gameRows; i++) {
			gameArea[i].resize(gameColumns);
		}
		board.resize(rows);
		for (int i = 0; i < rows; i++) {
			board[i].resize(columns);
		}
		generateBoardDecorations ();
		cursorData[0] = 0;
		cursorData[1] = 0;
		cursorData[2] = (int)EMPTY_CELL;
	}
	void updateCursor (int cursorCoodrinates[]) {
		gameArea[cursorData[0]][cursorData[1]] = (char)cursorData[2];
		cursorData[0] = cursorCoodrinates[0] - 1;
		cursorData[1] = cursorCoodrinates[1] - 1;
		cursorData[2] = gameArea[cursorCoodrinates[0] - 1][cursorCoodrinates[1] - 1];
		gameArea[cursorCoodrinates[0] - 1][cursorCoodrinates[1] - 1] = CURSOR;
	}
	void generateBoardDecorations () {
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < columns; col++) {
				//Test Filler
				//board[row][col] = '-';
				//Horizontal Axis
				if ((row == 0 || row == rows - 1) && col > 1 && col < columns - 2) {
						board[row][col] = '1' + col - 2;
				}
				//Horizontal Lines and Corners
				if (row == rows - 2) {
					if (col == 1)
						board[row][col] = CORNER_LEFT_UP;
					if (col == columns - 2) 
						board[row][col] = CORNER_RIGHT_UP;
					if (col >= 2 && col <= columns - 3)
						board[row][col] = HORIZONTAL_LINE;
				}
				if (row == 1) {
					if (col == 1)
						board[row][col] = CORNER_LEFT_DOWN;
					if (col == columns - 2)
						board[row][col] = CORNER_RIGHT_DOWN;
					if (col >= 2 && col <= columns - 3)
						board[row][col] = HORIZONTAL_LINE;
				}
				//Vertical Axis
				if ((col == 0 || col == columns - 1) && row >= 2 && row <= rows - 3)
						board[row][col] = 'A' + row - 2;
				//Vertical Lines and Corners
				if ((col == 1 || col == columns - 2) && row >= 2 && row <= rows - 3)
					board[row][col] = VERTICAL_LINE;
			}
		}
	}
	void updateFrame () {
		for (int row = 2; row < gameRows + 2; row++) {
			for (int col = 2; col < gameColumns + 2; col++) {
				//Combine gameArea with the board vector
				board[row][col] = gameArea[row - 2][col - 2];
			}
		}
	}
	bool addShipToBoard (int shipPosition[]) {
		return true;
	}
};

void updateScreen (GameInstance&, int[], bool);
void printBoard (GameInstance&);
void clearBoard (GameInstance&);
void clearScreen ();
void gameLoop (GameInstance&);
void placeShipsManually (GameInstance&);