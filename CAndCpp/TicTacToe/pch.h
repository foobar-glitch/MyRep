#ifndef PCH_H
#define PCH_H


// TODO: Fügen Sie hier Header hinzu, die vorkompiliert werden sollen.
#include <iostream>
#include <conio.h>


class Spiel {
private:
	int x;
	int y;
	char feld[5][5];
	

	//initialisiere
	void init();

	//gebe Wert ein + bool wurde auch wirklich gesetzt
	bool setze(int, int, char);

	//vorlaufiges setzen
	void tmp_setzen(char);
	
	//gebe feld aus
	void ausgabe();

	//Navigation ueber wasd
	void navigiere(char);

	//Runde fuer einen spieler
	void runde(char);
	
	//finde heraus ob Spiel unentschieden
	bool unentschieden();

	//finde heraus ob spieler gewonnen hat
	bool gewonnen(char);

public:
	//Kontruktor
	Spiel();
};


#endif //PCH_H