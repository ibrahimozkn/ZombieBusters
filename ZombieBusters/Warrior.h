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
	vector<char> kill_history;
	int i;
public:
	Warrior(int life, int ammu, int unit_size, char rep_Character) : Entity(rep_Character, unit_size) {
		life_points = life;
		ammunition = ammu;
		alive = 1;
		score = 0;
		i = 0;
	}
	int get_life();
	int get_ammu();
	void set_life(int);
	void set_ammu(int);
	int check_alive();
	void add_kill(char);
	void add_coordinate(int, int);
	virtual int attack() = 0;
};

int Warrior::get_life() {
	return life_points;
}
int Warrior::get_ammu() {
	return ammunition;
}

void Warrior::set_life(int l) {
	life_points = l;

	if (life_points < 1) {
		alive = 0;
	}
}
void Warrior::set_ammu(int a) {
	ammunition = a;
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