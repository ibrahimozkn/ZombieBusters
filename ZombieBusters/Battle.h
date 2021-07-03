#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include "Zombies.h"
#include "Warrior.h"
#include "Dice.h"

using std::cout;

int Battle(Zombies& zombie, Warrior& warrior) {
	int turn, i;
	int wAttack;
	double diceVal;
	for (turn = 1; ; turn++) {
		//Odd numbers = Player & Even Numbers = Zombie

		if (turn % 2 == 1) {
			wAttack = 0;
			if (warrior.get_ammo() > 0) {
				if (warrior.get_ammo() == 1) {
					diceVal = rollDice();
					wAttack = warrior.attack(1) * diceVal;
					cout << "\nYou rolled" << diceVal << "\n";
				}
				else {
					if (warrior.get_Character() == 'D') {
						for (i = 0; i < 2; i++) { 
							diceVal = rollDice();
							cout << "\nYou rolled " << diceVal;
							wAttack += warrior.attack(1) * diceVal; 
						}
					}
					else {
						diceVal = rollDice();
						wAttack = warrior.attack(1) * diceVal;
						cout << "\nYou rolled " << diceVal;
					}
				}
			}
			else {
				wAttack = warrior.attack(2);
			}
			zombie.updateHealth(wAttack);
			cout << "You hit " << wAttack << "to Zombie\n";
			cout << "\nZombie's remaining life " << ((zombie.getLife() < 0) ? '0' : zombie.getLife());
		
		}else {
			warrior.reduce_life(zombie.getdmgPerHit());
			cout << "\nZombie hit" << zombie.getdmgPerHit();

			cout << "\n" << ((warrior.get_Character() == 'D') ? "Derick" : "Chichonne") << "'s remaining life " << ((warrior.get_life() < 0) ? '0' : warrior.get_life()) << "\n";
		}
		if (zombie.isAlive() == 0) {
			return 1;
		}else if(warrior.check_alive() == 0){
			return 0;
		}

		
	}
}


#endif