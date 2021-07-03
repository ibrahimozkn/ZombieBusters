#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include "Zombies.h"
#include "Warrior.h"

#include "Dice.h"

using std::cout;

int Battle(Zombies* z, Warrior* w) {
	int turn = 1;
	int Attack;

	while (z->isAlive() != 0 && w->check_alive() != 0) {
		if (turn % 2 == 1) { //Player's turn
			if (w->get_Character() == 'D') {
				cout << "\nDerick's turn\n";

				
				if (w->get_ammo() == 1) {
					Attack = w->attack(1) * rollDice();
					z->updateHealth(Attack);
					cout << "You gave " << Attack << " damage to the Zombie!\n";
					cout << "You are out of ammo!\n";
				}
				else if (w->get_ammo() > 1) {
					Attack = w->attack(1) * rollDice();
					z->updateHealth(Attack);
					cout << "You gave " << Attack << " damage to the Zombie!\n";
					cout << "You have " << w->get_ammo() << " ammo remaining!\n";

					if (z->isAlive() == 0) {
						continue;
					}

					Attack = w->attack(1) * rollDice();
					z->updateHealth(Attack);
					cout << "You gave " << Attack << " damage to the Zombie!\n";
					cout << "You have " << w->get_ammo() << " ammo remaining!\n";
					
				}
				else if (w->get_ammo() <= 0) {
					cout << "You used your knife!" << "\n";
					Attack = w->attack(2);
					z->updateHealth(Attack);
					cout << "You gave " << Attack << " damage to the Zombie!\n";

				}
			}
			else if (w->get_Character() == 'C') {
				cout << "Chichonne's turn!\n";

				if (w->get_ammo() > 0) {
					Attack = w->attack(1) * rollDice();
					z->updateHealth(Attack);
					cout << "You gave " << Attack << " damage to the Zombie!\n";

					if (w->get_ammo() == 0) {
						cout << "You are out of ammo!\n";
					}
					else {
						cout << "You have " << w->get_ammo() << " ammo remaining!\n";
					}
				}
				else if (w->get_ammo() <= 0) {
					cout << "You used your katana!" << "\n";
					Attack = w->attack(2);
					z->updateHealth(Attack);
					cout << "You gave " << Attack << " damage to the Zombie!\n";

				}
			}
			cout << "Zombie's current life: " << z->getLife() << "\n";
		}
		else if (turn % 2 == 0) { //Zombie's turn
			cout << "\nZombie's Turn!\n";
			w->reduce_life(z->getdmgPerHit());
			cout << "\nZombie gives you " << z->getdmgPerHit() << " damage!\n";
		}
		turn++;
	}
	if (z->isAlive() == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

/*int Battle(Zombies& zombie, Warrior& warrior) {
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
							cout << "\nYou rolled " << diceVal << "\n";
							wAttack += warrior.attack(1) * diceVal; 
						}
					}
					else {
						diceVal = rollDice();
						wAttack = warrior.attack(1) * diceVal;
						cout << "\nYou rolled " << diceVal << "\n";
					}
				}
			}else {
				wAttack = warrior.attack(2);
			}
			zombie.updateHealth(wAttack);
			cout << "\nYou hit " << wAttack << " to Zombie\n";
			cout << "\nZombie's remaining life " << zombie.getLife() << "\n";
		
		}else {
			warrior.reduce_life(zombie.getdmgPerHit());
			cout << "\nZombie hit" << zombie.getdmgPerHit() << "\n";

			cout << "\n" << ((warrior.get_Character() == 'D') ? "Derick" : "Chichonne") << "'s remaining life " << warrior.get_life() << "\n";
		}
		cout << "\n" << ((warrior.get_Character() == 'D') ? "Derick" : "Chichonne") << "'s remaining life " << warrior.get_life() << "\n";
		if (zombie.isAlive() == 0) {
			return 1;
		}

		if(warrior.check_alive() == 0){
			return 0;
		}

		
	}
}*/


#endif