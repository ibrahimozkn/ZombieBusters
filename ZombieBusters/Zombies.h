#ifndef ZOMBIES_H
#define ZOMBIES_H

#include "Entity.h"

class Zombies : public Entity{
private:
	int Life;
	int dmgPerHit;
	int scorePerItem;
	int alive;
	vector<coordinate> coordinates;
public:
	Zombies( int zombLife,  int damage,  int score,  char repCharacter, int s) : Entity(repCharacter, s){
		this->Life = zombLife;
		this->dmgPerHit = damage;
		this->scorePerItem = score;
		this->alive = 1;
	}


	int getLife() {
		if (this->Life < 0) {
			return 0;
		}
		else {
			return this->Life;
		}
	}

	int getdmgPerHit() {
		return this->dmgPerHit;
	}

	int getscorePetItem() {
		return this->scorePerItem;
	}

	int isAlive() {
		return this->alive;
	}

	void updateHealth(int dmgTaken) {
		this->Life -= dmgTaken;

		if (this->Life <= 0) {
			this->alive = 0;
		}
	}
	void add_coordinate(int x, int y) { coordinates.push_back({ x,y }); }
	vector<coordinate> get_coordinates() { return coordinates; }
};


class LargeZombie : public Zombies{
public:
	LargeZombie() : Zombies(12, 8, 100, 'L', 3) {};
};

class MediumZombie : public Zombies {
public:
	MediumZombie() : Zombies(8, 4, 75, 'M', 2) {};
};

class SmallZombie : public Zombies {
public:
	SmallZombie() : Zombies(4, 2, 50, 'S', 1) {};
};

#endif