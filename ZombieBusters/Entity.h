#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>

class Entity {
private:
	char Character;
	int Size;
protected:
	void Entity(char, int);
public:
	char get_Character();
	int get_Size();
};

//constructor (to be called by derived classes)

void Entity::Entity(char c, int s) {
	Character = c;
	Size = s;
}

//Getters

char Entity::get_Character() {
	return Character;
}
int Entity::get_Size() {
	return Size;
}

#endif