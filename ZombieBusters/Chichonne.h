#ifndef CHICHONNE_H
#define CHICHONNE_H

#include "Warrior.h"

class Chichonne : public Warrior {
private:
	int mega_status;
public:
	Chichonne() : Warrior(100, 25, 1, 'C') {
		mega_status = 0;
	}
	int attack(int choice) {
		update_mega_status();
		if (choice == 1) {
			this->reduce_ammo(1);
			return 5;
		}
		else if(choice == 2){
			if (mega_status == 1) {
				return 6;
			}
		}
		return 4;
	}
	int check_mega_status();
	void update_mega_status();
};

int Chichonne::check_mega_status() {
	return mega_status;
}

void Chichonne::update_mega_status() {
	if (kill_history.size() >= 2 && mega_status != 1) {
		cout << "Your katana has upgraded to a MEGA KATANA!\n";
		mega_status = 1;
	}
}

#endif