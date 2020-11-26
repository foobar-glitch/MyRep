/*
 * viergewinnt.cpp
 *
 *  Created on: 20.11.2020
 *      Author: asami
 */
#include "viergewinnt.h"

void clearScreen(){
	// linux based OS
	//system("clear");
	// windows
	system("CLS");
}

void VierGewinnt::setArrow() {
	spielfeld[Y_LENGTH - 1][chosenColumn] = '*';
}

void VierGewinnt::deleteArrow() {
	spielfeld[Y_LENGTH - 1][chosenColumn] = ' ';
}

bool VierGewinnt::undecided() {
	for (int row = 0; row < X_LENGTH; row++) {
		// no free space left on uppest column
		if (spielfeld[0][row] == ' ') {
			return false;
		}
	}
	return true;
}

bool VierGewinnt::won(char player) {
	int counterRow, counterColumn;

	/*
	* Check all rows for a choosen coloumn
	* If at least 4 elements of the characters 
	* of 'player' follow after each other
	* player has a four row
	*/
	
	for (int y = 0; y < Y_LENGTH; y++) {
		counterRow = 0;
		for (int x = 0; x < X_LENGTH; x++) {
			if (counterRow >= 4) {
				return true;
			}

			if (spielfeld[y][x] == player) {
				counterRow++;
			}
			else {
				counterRow = 0;
			}			
		}
	}
	
	/*
	* Check each coloumn for every row
	* If at least four 'player' characters
	* follow without an interruption then
	* the player has a four coloumn
	*/

	for (int x = 0; x < X_LENGTH; x++) {
		counterColumn = 0;
		for (int y = 0; y < Y_LENGTH; y++) {
			if (counterColumn >= 4) {
				return true;
			}

			if (spielfeld[y][x] == player) {
				counterColumn++;
			}
			else {
				counterColumn = 0;
			}

		}
	}
	
	/*
	* Check from buttom to top 
	*
	*/
	
	for (int row = Y_LENGTH - 3; row >= 0; row--) {
		// look if there is a diagonal left to right winner
		for (int column = 0; column < X_LENGTH; column++) {
			if (row + 3 < Y_LENGTH && column - 3 >= 0) {
				if (spielfeld[row][column] == player && spielfeld[row + 1][column - 1] == player && spielfeld[row + 2][column - 2] == player && spielfeld[row + 3][column - 3] == player) {
					return true;
				}
			}
		}
		// from right to left
		for (int column = X_LENGTH; column > 0; column--) {
			if (row - 3 >= 0 && column >= 0) {
				if (spielfeld[row][column] == player && spielfeld[row - 1][column - 1] == player && spielfeld[row - 2][column - 2] == player && spielfeld[row - 3][column - 3] == player) {
					return true;
				}
			}
		}

	}

	return false;
}

bool VierGewinnt::setPlayerAtArrow(char player) {
	int maxNotSet = Y_GAMELENGTH;
	while (1) {
		if (maxNotSet < 0) {
			cout << "already full"<<endl;
			// didnt set value
			return false;
		}
		
		// can only set if field isnt set already
		if (spielfeld[maxNotSet][chosenColumn] == ' ') {
			spielfeld[maxNotSet][chosenColumn] = player;
			// return that setting has been successfull
			return true;
		}
		else {
			maxNotSet--;
		}
	}
}

void VierGewinnt::init() {
	for (int y = 0; y < Y_LENGTH; y++) {
		for (int x = 0; x < X_LENGTH; x++) {
			// define two bars at the sides and one at the bottom
			if ((((x == 0 || x == X_LENGTH - 1))) && y != Y_LENGTH-1) {
				spielfeld[y][x] = '|';
			}
			else if (y == Y_LENGTH - 2) {
				spielfeld[y][x] = '=';
			}
			else {
				spielfeld[y][x] = ' ';
			}
		}
	}
	setArrow();
}

void VierGewinnt::draw() {
	for (int y = 0; y < Y_LENGTH; y++) {
		for (int x = 0; x < X_LENGTH; x++) {
			cout << spielfeld[y][x];
		}
		cout << endl;
	}
}

bool VierGewinnt::choose_column(char player) {
	char direction, confirmation;
	cin >> direction;
	deleteArrow();
	// move to the right with 'd'
	if (direction == 'd') {
		chosenColumn++;
		if (chosenColumn == X_LENGTH-1) {
			chosenColumn = 1;
		}
	} 
	// move to the left with 's'
	else if (direction == 'a') {
		// (1-X_GAMELENGTH)
		chosenColumn--;
		if (chosenColumn == 0) {
			chosenColumn = X_LENGTH - 2;
		}
	}
	// set with s
	else if (direction == 's') {
		cout << "\nConfirm with 's' \n" << endl;
		cin >> confirmation;
		clearScreen();
		setArrow();
		if (confirmation == 's') {
			return setPlayerAtArrow(player);
		}
	}
	setArrow();
	clearScreen();
	// return that no value has been set
	return false;
}

VierGewinnt::VierGewinnt() {
	init();
	draw();
	
	char p[2] = { 'x','o' }, currentplayer;
	bool turnOver;
	int i = 0;

	while (1) {
		currentplayer = p[i];
		turnOver = false;
		while (!turnOver) {
			cout << "It's the turn of '" << currentplayer<<"'" << endl;
			turnOver = choose_column(currentplayer);
			draw();
			if (won(currentplayer)) {
				cout << currentplayer <<" won the game" << endl;
				return;
			}
			else if (undecided()) {
				cout << "Draw. Noone won" << endl;
				return;
			}
		}
		// add 1 mod 2 => invert player
		i ^= 1;
	}
}
