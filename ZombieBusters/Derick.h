#ifndef DERICK_H
#define DERICK_H

#include "Warrior.h"

class Derick : public Warrior {
public:
	Derick() : Warrior(100, 30, 1, 'D') {

	}
	int attack(int choice) {
		if (choice == 1) {
			this->reduce_ammo(1);
			return 5;
		}else{
			return 1;
		}
	}
};

#endif