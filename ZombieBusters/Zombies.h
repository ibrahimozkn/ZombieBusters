/* Ibrahim Ozkan – 2456275
I read and accept the submission rules and the important section specified in assignment file.
This is my own work that is done by myself and my team-mate only */
#ifndef ZOMBIES_H
#define ZOMBIES_H

#include "Entity.h"

/* ZOMBIES CLASS
*
* @desc: Its is parent class for zombie types
* 
* @variables: Life for zombie life, dmgPerHit for damage given per hit, scorePerItem for score going to be given at each kill of zombie, alive for living status of zombie
* 
* 
* 
*/

class Zombies : public Entity{
private:
	int Life;
	int dmgPerHit;
	int scorePerItem;
	int alive;
	vector<coordinate> coordinates;
public:
	//constructor
	Zombies( int zombLife,  int damage,  int score,  char repCharacter, int s) : Entity(repCharacter, s){
		this->Life = zombLife;
		this->dmgPerHit = damage;
		this->scorePerItem = score;
		this->alive = 1;
	}


	int getLife() { //returns life of the zombie
		if (this->Life < 0) {
			return 0;
		}
		else {
			return this->Life;
		}
	}

	int getdmgPerHit() { //returns damage per hit of the zombie
		return this->dmgPerHit;
	}

	int getscorePetItem() { //returns score per item
		return this->scorePerItem;
	}

	int isAlive() { //returns if zombie is alive or not
		return this->alive;
	}

	void updateHealth(int dmgTaken) { //updates the life of the zombie, if life is less than or equal to 0, set alive variable to 0
		this->Life -= dmgTaken;

		if (this->Life <= 0) {
			this->alive = 0;
		}
	}
	void add_coordinate(int x, int y) { coordinates.push_back({ x,y }); } //pushes the given coordinates of the object to the end of the grid
	vector<coordinate> get_coordinates() { return coordinates; } //gets the coordinates of object
};


class LargeZombie : public Zombies{
public:
	LargeZombie() : Zombies(12, 8, 100, 'L', 3) {}; //constructor
};

class MediumZombie : public Zombies {
public:
	MediumZombie() : Zombies(8, 4, 75, 'M', 2) {}; //constructor
};

class SmallZombie : public Zombies {
public:
	SmallZombie() : Zombies(4, 2, 50, 'S', 1) {}; //constructor
};

#endif