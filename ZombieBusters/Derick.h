/* Adil Bozkurt Kebapçıoğlu - 2455954
I read and accept the submission rules and the important section specified in assignment file.
This is my own work that is done by myself and my team-mate only */
#ifndef DERICK_H
#define DERICK_H

#include "Warrior.h"

class Derick : public Warrior {
public:
	Derick() : Warrior(100, 30, 1, 'D') { // constructor

	}
	int attack(int choice) { //dericks attack function, returns damage
		if (choice == 1) {
			this->reduce_ammo(1);
			return 5;
		}else{
			return 1;
		}
	}
};

#endif