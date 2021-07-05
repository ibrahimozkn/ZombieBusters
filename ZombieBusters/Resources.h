/* Ibrahim Ozkan – 2456275
I read and accept the submission rules and the important section specified in assignment file.
This is my own work that is done by myself and my team-mate only */
#ifndef RESOURCES_H
#define RESOURCES_H

#include "Entity.h"
#include "Warrior.h"

class Resources : public Entity {
protected:
	int Effect;
	vector<coordinate> coordinates;
	char cha;
public:
	Resources(int effect, char C, int Size) : Entity(C, Size) {
		this->Effect = effect;
		this->cha = C;
	};
	void add_coordinate(int x, int y) { coordinates.push_back({ x,y }); }
	vector<coordinate> get_coordinates() { return coordinates; }
	virtual void getEffect(Warrior* w) = 0;
	void printEffect() {
		cout << "asdasd: " << Effect;
	}
};



class SmallMedicineKit : public Resources {
public:
	SmallMedicineKit() : Resources(10, '+', 1) {};

	void getEffect(Warrior* w) {
		cout << "-> You came across a Small Medicine Kit!  You got " << ((w->get_life() == 100) ? 0 : ((w->get_life() + Effect) > 100 ? ((100 + Effect) - w->get_life() - 10) : Effect)) << "HP\n";
		w->add_life(Effect);
	}
	
};

class LargeMedicineKit : public Resources {
public:
	LargeMedicineKit() : Resources(20, '*', 1) {};

	void getEffect(Warrior* w) {
		cout << "-> You came across a Large Medicine Kit! You got " << ((w->get_life() == 100) ? 0 : ((w->get_life() + Effect) > 100 ? ((100 + Effect) - w->get_life() - 10) : Effect)) << "HP\n";
		w->add_life(Effect);
	}
};

class Ammunition : public Resources {
public:
	Ammunition() : Resources(10,'A', 1) {  };

	void getEffect(Warrior* w) {
		cout << "-> You came across a Ammunition Pack! You got 10 Bullets!\n";
		w->add_ammo(Effect);
	}
};

#endif // !
