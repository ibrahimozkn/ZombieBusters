/* Ibrahim Ozkan – 2456275
I read and accept the submission rules and the important section specified in assignment file.
This is my own work that is done by myself and my team-mate only */
#ifndef DICE_H
#define DICE_H

#include <iostream>


using std::cout;

/* ROLLDICE FUNCTION
*
* @desc: Rolls the dice and returns according coefficient of dice effect for damage calculation
*
* @param: void 
* 
* @return: double value of damage coefficient
* 
*/

double rollDice() {
	
	
	int dice = 1 + (rand() % 6);
	cout << "You rolled " << dice << "\n";

	double rValue;

	if (dice == 5 || dice == 6) { //if its 5-6
		cout << "DICE EFFECT -> That's a lot of damage, CRITICAL HIT!\n";
		rValue = 2; //critical hit coefficient of 2
	}
	else if (dice == 1 || dice == 2) { //if its 1-2 its minor scratch
		cout << "DICE EFFECT -> Oh no, Minor scratch :(\n";
		rValue = 0.40;
	}else { //otherwise no effect
		cout << "DICE EFFECT -> NO EFFECT!\n";
		rValue = 1;
	}

	return rValue;

}

int chooseDice() { //a dice for choosing player turn which produces a number between 1 to 2
	return 1 + (rand() % 2);
}



#endif