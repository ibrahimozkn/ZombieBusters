#ifndef DICE_H
#define DICE_H

#include <iostream>
#include <time.h>

using std::cout;

double rollDice() {
	
	
	int dice = 1 + (rand() % 6);

	if (dice == 5 || dice == 6) {
		return 2;
	}
	else if (dice == 1 || dice == 2) {
		return 0.40;
	}
	else {
		return 1;
	}
}



#endif