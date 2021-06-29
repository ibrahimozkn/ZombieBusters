#ifndef DICE_H
#define DICE_H

#include <iostream>
#include <time.h>

using std::cout;

int rollDice(int damage) {
	
	
	int dice = 1 + (rand() % 6);

	if (dice == 5 || dice == 6) {
		return damage * 2;
	}
	else if (dice == 1 || dice == 2) {
		return damage * 0.40;
	}
	else {
		return damage;
	}
}



#endif