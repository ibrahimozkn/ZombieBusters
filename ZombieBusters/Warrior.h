/* Adil Bozkurt Kebap��o�lu - 2455954
I read and accept the submission rules and the important section specified in assignment file.
This is my own work that is done by myself and my team-mate only */
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
	Warrior(int life, int ammo, int unit_size, char rep_Character) : Entity(rep_Character, unit_size) { //Warrior constructor, calls entity constructor
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
	void add_kill(char); //adds kill repreented by a char to kill_history vector 
	void print_kill_history(); //checks prints kill_history vector
	void add_coordinate(int, int); //adds coordinate to past_coordinates
	vector<coordinate> get_past_coordinates(); //getter for past_coordinates
	virtual int attack(int) = 0; // virtual attack function for subclasses Derick and Chichonne
	int get_score();
};

int Warrior::get_life() {
	if (this->life_points < 0) {
		return 0;
	}
	else {
		return this->life_points;
	}
}
int Warrior::get_ammo() {
	return ammunition;
}

void Warrior::reduce_life(int l) {
	life_points -= l;
}

void Warrior::add_life(int l) {
	life_points = ((l + life_points) > 100) ? 100 : (life_points + l);
}

void Warrior::reduce_ammo(int a) {
	ammunition -= a;
}

void Warrior::add_ammo(int a) {
	ammunition += a;
}

int Warrior::check_alive() {
	if (this->life_points <= 0) {
		this->alive = 0;
	}
	return this->alive;
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

void Warrior::print_kill_history() {
	int i;
	for (i = 0; kill_history.size() > i; i++) {
		if (kill_history[i] == 'L') {
			cout << "Large Zombie";
		}
		else if (kill_history[i] == 'M') {
			cout << "Medium Zombie";
		}
		else if (kill_history[i] == 'S') {
			cout << "Small Zombie";
		}
		if ((kill_history.size() - i) == 1) {
			cout << ".\n";
		}
		else {
			cout << ", ";
		}
	}

	if (kill_history.size() == 0) {
		cout << "NONE\n\n";
	}
	
}

void Warrior::add_coordinate(int X, int Y) {
	past_coordinates.push_back(coordinate());
	past_coordinates[i].x = X;
	past_coordinates[i].y = Y;
	i++;
}

vector<coordinate> Warrior::get_past_coordinates() {
	return past_coordinates;
}

int Warrior::get_score() {
	return score;
}

#endif