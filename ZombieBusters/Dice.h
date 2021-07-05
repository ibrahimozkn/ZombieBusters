/* Ibrahim Ozkan – 2456275
I read and accept the submission rules and the important section specified in assignment file.
This is my own work that is done by myself and my team-mate only */
#ifndef DICE_H
#define DICE_H

#include <iostream>


using std::cout;

double rollDice() {
	
	
	int dice = 1 + (rand() % 6);
	cout << "You rolled " << dice << "\n";

	double rValue;

	if (dice == 5 || dice == 6) {
		cout << "Dice effect: Hell yeah, CRITICAL HIT!\n";
		rValue = 2;
	}
	else if (dice == 1 || dice == 2) {
		cout << "Dice Effect: Oh no, Minor scratch :(\n";
		rValue = 0.40;
	}else {
		cout << "Dice Effect: NO EFFECT!\n";
		rValue = 1;
	}

	return rValue;

}

int chooseDice() {
	return 1 + (rand() % 2);
}



#endif