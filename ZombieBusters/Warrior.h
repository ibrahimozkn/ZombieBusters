#ifndef WARRIOR_H
#define WARRIOR_H

#include "Entity.h"

class Warrior : public Entity {

private:
	int life_points;
	int ammunition;
	int alive;
	int score;
	vector<coordinate> past_coordinates;
	int i;
protected:
	vector<char> kill_history;
public:
	Warrior(int life, int ammo, int unit_size, char rep_Character) : Entity(rep_Character, unit_size) {
		life_points = life;
		ammunition = ammo;
		alive = 1;
		score = 0;
		i = 0;
	}
	int get_life();
	int get_ammo();
	void reduce_life(int);
	void add_life(int);
	void reduce_ammo(int);
	void add_ammo(int);
	int check_alive();
	void add_kill(char);
	void add_coordinate(int, int);
	virtual int attack(int) = 0;
};

int Warrior::get_life() {
	return life_points;
}
int Warrior::get_ammo() {
	return ammunition;
}

void Warrior::reduce_life(int l) {
	life_points -= l;

	if (life_points < 1) {
		alive = 0;
	}
}

void Warrior::add_life(int l) {
	life_points += l;
}

void Warrior::reduce_ammo(int a) {
	ammunition -= a;
}

void Warrior::add_ammo(int a) {
	ammunition += a;
}

int Warrior::check_alive() {
	return alive;
}

void Warrior::add_kill(char zombie) {
	if (zombie == 'L') {
		score += 100;
	}
	else if (zombie == 'M') {
		score += 75;
	}
	else if (zombie == 'S') {
		score += 50;
	}
	kill_history.push_back(zombie);
}

void Warrior::add_coordinate(int X, int Y) {
	past_coordinates.push_back(coordinate());
	past_coordinates[i].x = X;
	past_coordinates[i].y = Y;
	i++;
}

#endif