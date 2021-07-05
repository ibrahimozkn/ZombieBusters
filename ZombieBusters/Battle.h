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

/* BATTLE FUNCTION
*
* @desc: This function handles the battle between the warrior and zombie
* 
* @param: Warrior object (*w) and Zombie Object (*z)
* 
* @output: Integer representing if warrior is dead or not.
*/

int Battle(Zombies* z, Warrior* w) {
	int turn = 1;
	int Attack;

	switch (z->get_Character()) { //print zombie types
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
			if (w->get_Character() == 'D') { //if warrior is derick
				cout << "\nTURN -> Derick's turn\n\n";

				
				if (w->get_ammo() == 1) { //if ammo left is 1 only shoot 1 salvos
					Attack = w->attack(1) * rollDice(); //roll the dice and get the damage with dice effect
					z->updateHealth(Attack); //update zombie health
					cout << "BATTLE -> You gave " << Attack << " damage to the Zombie!\n";
					cout << "BATTLE -> You are out of ammo!\n\n";
				}
				else if (w->get_ammo() > 1) { //if ammo is more than 1 shoot 2 salvos
					Attack = w->attack(1) * rollDice();
					z->updateHealth(Attack); //update zombie health
					cout << "BATTLE -> You gave " << Attack << " damage to the Zombie!\n";
					cout << "BATTLE -> You have " << w->get_ammo() << " ammo remaining!\n\n";

					if (z->isAlive() == 0) { //if zombie is dead dont shoot 2nd salvo
						continue;
					}

					//shoot the second salvo
					Attack = w->attack(1) * rollDice(); 
					z->updateHealth(Attack);
					cout << "BATTLE -> You gave " << Attack << " damage to the Zombie!\n";
					cout << "BATTLE -> You have " << w->get_ammo() << " ammo remaining!\n\n";
					
				}
				else if (w->get_ammo() <= 0) { //if theres no ammo left use knife of derick
					cout << "BATTLE -> You used your knife!" << "\n";
					Attack = w->attack(2);
					z->updateHealth(Attack);
					cout << "BATTLE-> You gave " << Attack << " damage to the Zombie!\n\n";

				}
			}
			else if (w->get_Character() == 'C') { //if character is chichonne
				cout << "BATTLE -> Chichonne's turn!\n\n";

				if (w->get_ammo() > 0) { //if ammo theres ammo
					Attack = w->attack(1) * rollDice(); //calculate attack and update health of zombie
					z->updateHealth(Attack);
					cout << "BATTLE -> You gave " << Attack << " damage to the Zombie!\n";

					if (w->get_ammo() == 0) {
						cout << "BATTLE -> You are out of ammo!\n\n";
					}
					else {
						cout << "BATTLE -> You have " << w->get_ammo() << " ammo remaining!\n\n";
					}
				}
				else if (w->get_ammo() <= 0) { //if there is no ammo, use katana of chichonne
					cout << "BATTLE -> You used your katana!" << "\n";
					Attack = w->attack(2);
					z->updateHealth(Attack);
					cout << "BATTLE -> You gave " << Attack << " damage to the Zombie!\n\n";

				}
			}
			cout << "BATTLE -> Zombie's current life: " << z->getLife() << "\n";
		}
		else if (turn % 2 == 0) { //Zombie's turn
			cout << "\nBATTLE -> Zombie's Turn!\n\n";
			w->reduce_life(z->getdmgPerHit()); //do the same damage everytime to warrior
			cout << "\nBATTLE -> Zombie gives you " << z->getdmgPerHit() << " damage!\n\n";
		}
		turn++;
		Sleep(1000);
	}
	if (z->isAlive() == 0) { //if zombie is dead
		w->add_kill(z->get_Character()); //add zombie to kill history of warrior and update his score
		return 1;
	}
	else {
		return 0;
	}
}


#endif