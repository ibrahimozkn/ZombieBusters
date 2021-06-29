#ifndef DICE_H
#define DICE_H

#include <iostream>
#include <time.h>

int rollDice() {
	srand(time(NULL));

	return 1 + (rand() % 6);
}



#endif