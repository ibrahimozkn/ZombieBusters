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