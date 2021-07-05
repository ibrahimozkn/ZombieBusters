/* Adil Bozkurt Kebapçýoðlu - 2455954
I read and accept the submission rules and the important section specified in assignment file.
This is my own work that is done by myself and my team-mate only */
#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <vector>
using namespace std;

struct coordinate {
	int x;
	int y;
};

class Entity {
private:
	char Character;
	int Size;
public:
	//constructor (to be called by derived classes)

	Entity(char c, int s) {
		Character = c;
		Size = s;
	}

	//Getters

	char get_Character() {
		return Character;
	}
	int get_Size() {
		return Size;
	}

};


#endif