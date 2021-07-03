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



#endif