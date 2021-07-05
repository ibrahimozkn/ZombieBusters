#ifndef RESOURCES_H
#define RESOURCES_H

#include "Entity.h"
#include "Warrior.h"

class Resources : public Entity {
protected:
	int Effect;
	vector<coordinate> coordinates;
public:
	Resources(int effect, char C, int Size) : Entity(C, Size) {};
	void add_coordinate(int x, int y) { coordinates.push_back({ x,y }); }
	vector<coordinate> get_coordinates() { return coordinates; }
	virtual void getEffect(Warrior* w) = 0;
};



class SmallMedicineKit : public Resources {
public:
	SmallMedicineKit() : Resources(10, '+', 1) {};

	void getEffect(Warrior* w) {
		w->add_life(Effect);
	}
	
};

class LargeMedicineKit : public Resources {
public:
	LargeMedicineKit() : Resources(20, '*', 1) {};

	void getEffect(Warrior* w) {
		w->add_life(Effect);
	}
};

class Ammunition : public Resources {
public:
	Ammunition() : Resources(10,'A', 1) {  };

	void getEffect(Warrior* w) {
		w->add_ammo(Effect);
	}
};

#endif // !
