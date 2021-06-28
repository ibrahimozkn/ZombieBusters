#ifndef WARRIOR_H
#define WARRIOR_H

#include "Entity.h"


class Warrior : public Entity {

private:
	int life_points;
	int ammunition;
public:
	int get_life();
	int get_ammu();
	void set_life(int);
	void set_ammu(int);
};

int Warrior::get_life() {
	return life_points;
}
int Warrior::get_ammu() {
	return ammunition;
}

void Warrior::set_life(int l) {
	life_points = l;
}
void Warrior::set_ammu(int a) {
	ammunition = a;
}

#endif