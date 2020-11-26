#include "pch.h"
using namespace std;

Spiel::Spiel() {
	init();
	char spieler1 = 'x';
	char spieler2 = 'o';

	while (1) {
		
		runde(spieler1);
		system("cls");
		if (unentschieden()||gewonnen(spieler1))
			break;

		runde(spieler2);
		system("cls");
		if (unentschieden() || gewonnen(spieler2))
			break;
	}
}


void Spiel::runde(char spieler) {
	this->x = 0;
	this->y = 0;
	bool gesetzt = false;
	char anweisung;
	printf("Zum auswaehlen druecke '%c' druecken\n", spieler);
	ausgabe();
	while (1) {
		printf("(%d, %d) ausgewaehlt\n", int(x / 2), int(y / 2));
		anweisung = _getch();
		//beendet zug
		if (anweisung == spieler) {
			gesetzt = setze(x, y, spieler);
			if (gesetzt)
				break;
		}
		navigiere(anweisung);
		//vorlauefiges setzen damit man weiss wo sich das kreuz befindet
		tmp_setzen(spieler);
	}
}


bool Spiel::unentschieden() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			//gibt es mind ein noch nicht ausgewaehltes Feld so ist das Spiel noch nicht unentschieden
			if (feld[i][j] == ' ')
				return false;
		}
	}
	cout << "unentschieden" << endl;
	return true;
}


void Spiel::init() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (j % 2 == 0 && i % 2 == 0)
				feld[i][j] = ' ';
			else
				feld[i][j] = '#';
		}
	}
}


void Spiel::ausgabe() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << feld[i][j];
		}
		cout << endl;
	}
	cout << endl;
}


bool Spiel::setze(int w1, int w2, char spieler) {
	if (feld[w2][w1] == '#')
		throw "Fehler:Falsches Feld ausgewaehlt";
	if (feld[w2][w1] != ' ') {
		cout << "Bitte Waehle ein anderes Feld" << endl;
		return false;
	}
	else {
		feld[w2][w1] = spieler;
		return true;
	}
}


void Spiel::tmp_setzen(char spieler) {
	bool gesetzt = setze(this->x, this->y, spieler);
	//falls wirklich ein Punkt gesetzt wurde so setze ihn wieder zurueck
	if (gesetzt) {
		system("cls");
		printf("Zum auswaehlen bitte '%c' druecken\n", spieler);
		ausgabe();
		this->feld[this->y][this->x] = ' ';
	}
}


void Spiel::navigiere(char richtung) {
	//statt -2 mod 6 -> 4 mod 6
	if (richtung == 'w')
		y = (y + 4) % 6;
	else if (richtung == 's')
		y = (y + 2) % 6;
	else if (richtung == 'a')
		x = (x + 4) % 6;
	else if (richtung == 'd')
		x = (x + 2) % 6;
	else
		cout << "Taste nicht erkannt" << endl;
}


bool Spiel::gewonnen(char spieler) {
	for (int i = 0; i < 5; i += 2) {
		//horizontal
		if (feld[i][0] == spieler && feld[i][0] == feld[i][2] && feld[i][0] == feld[i][4]) {
			cout << spieler << " hat gewonnen" << endl;
			return true;
		}
		//vertikal
		else if (feld[0][i] == spieler && feld[0][i] == feld[2][i] && feld[0][i] == feld[4][i]) {
			cout << spieler << " hat gewonnen" << endl;
			return true;
		}
	}
	//diagonal
	if (feld[0][0] == spieler && feld[0][0] == feld[2][2] && feld[0][0] == feld[4][4]) {
		cout << spieler << " hat gewonnen" << endl;
		return true;
	}
	else if (feld[0][4] == spieler && feld[0][4] == feld[2][2] && feld[0][4] == feld[4][0]) {
		cout << spieler << " hat gewonnen" << endl;
		return true;
	}
	else
		return false;
}
