/*
 * viergewinnt.h
 *
 *  Created on: 20.11.2020
 *      Author: asami
 */

#ifndef VIERGEWINNT_H_
#define VIERGEWINNT_H_

#define X_GAMELENGTH 7
#define Y_GAMELENGTH 6

//zwei balken an seiten
#define X_LENGTH X_GAMELENGTH+2
//ein balken am boden
#define Y_LENGTH Y_GAMELENGTH+2


#include <iostream>
#include <stdio.h>

using namespace std;

class VierGewinnt {
private:
	// plus two to draw the border
	char spielfeld[Y_LENGTH][X_LENGTH];
	int chosenColumn = 1;
	// methods
	void init();
	void draw();
	void setArrow();
	void deleteArrow();
	bool choose_column(char);
	bool setPlayerAtArrow(char);
	
	bool undecided();
	bool won(char);
public:
	VierGewinnt();
};



#endif /* VIERGEWINNT_H_ */
