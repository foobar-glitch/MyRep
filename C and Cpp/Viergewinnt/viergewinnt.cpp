/*
 * viergewinnt.cpp
 *
 *  Created on: 20.11.2020
 *      Author: asami
 */
#include "viergewinnt.h"

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
	int counterRow, counterColumn, counterDiagonal;

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

	
	for (int column = Y_LENGTH - 3; column > 1; column--) {
		// look if there is a diagonal left to right winner
		for (int row = 0; row < Y_LENGTH; row++) {
			if (row + 3 < Y_LENGTH) {
				if (spielfeld[column][row] == player && spielfeld[column - 1][row + 1] == player && spielfeld[column - 2][row + 2] == player && spielfeld[column - 3][row + 3] == player) {
					return true;
				}
			}
		}
		// from right to left
		for (int row = Y_LENGTH; row > 0; row--) {
			if (row - 3 > 0) {
				if (spielfeld[column][row] == player && spielfeld[column - 1][row - 1] == player && spielfeld[column - 2][row - 2] == player && spielfeld[column - 3][row - 3] == player) {
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

		if (spielfeld[maxNotSet][chosenColumn] == ' ') {
			spielfeld[maxNotSet][chosenColumn] = player;
			// has set value
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
			// both vertically and one horizontally
			if ((((x == 0 || x == X_LENGTH - 1))) && y!=Y_LENGTH-1) {
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
	//spielfeld[Y_LENGTH-1][0] = ' ';

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
	if (direction == 'd') {
		chosenColumn++;
		if (chosenColumn == X_LENGTH-1) {
			chosenColumn = 1;
		}
	} 
	else if (direction == 'a') {
		// (1-X_GAMELENGTH)
		chosenColumn--;
		if (chosenColumn == 0) {
			chosenColumn = X_LENGTH - 2;
		}
	}
	else if (direction == 's') {
		cout << "\nConfirm with 's' \n" << endl;
		cin >> confirmation;
		system("CLS");
		setArrow();
		if (confirmation == 's') {
			return setPlayerAtArrow(player);
		}
	}
	setArrow();
	system("CLS");
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
		// add 1 mod 2
		i ^= 1;
	}
}