/* Ibrahim Ozkan – 2456275
I read and accept the submission rules and the important section specified in assignment file.
This is my own work that is done by myself and my team-mate only */
#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include "Zombies.h"
#include "Warrior.h"
#include "Dice.h"
#include <Windows.h>

using std::cout;

int Battle(Zombies* z, Warrior* w) {
	int turn = 1;
	int Attack;

	switch (z->get_Character()) {
	case 'S':
		cout << "BATTLE -> You encounter a Small Zombie! Battle starts!\n";
		break;
	case 'M':
		cout << "BATTLE -> You encounter a Medium Zombie! Battle starts!\n";
		break;
	case 'L':
		cout << "BATTLE -> You encounter a Large Zombie! Battle starts!\n";
		break;
	default: 
		break;
	}

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
		Sleep(1000);
	}
	if (z->isAlive() == 0) {
		w->add_kill(z->get_Character());
		return 1;
	}
	else {
		return 0;
	}
}


#endif