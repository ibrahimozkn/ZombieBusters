/* Ibrahim Ozkan – 2456275
I read and accept the submission rules and the important section specified in assignment file.
This is my own work that is done by myself and my team-mate only */
#ifndef RESOURCES_H
#define RESOURCES_H

#include "Entity.h"
#include "Warrior.h"

/* RESOURCES CLASS : PARENT CLASS ENTITY
*
* @desc: It is parent class for ammunition and med kits subclasses
* 
* @variables: integer effect, coordinate vector coordinates
* 
* 
*/

class Resources : public Entity {
protected:
	int Effect;
	vector<coordinate> coordinates;
public:

	//constructor
	Resources(int effect, char C, int Size) : Entity(C, Size) {
		this->Effect = effect;
	};

	void add_coordinate(int x, int y) { coordinates.push_back({ x,y }); } //adds coordinates got from the grid to coordinated vector
	vector<coordinate> get_coordinates() { return coordinates; } //returns coordinates of current object

	virtual void getEffect(Warrior* w) = 0; //virtual function for getEffect
};





class SmallMedicineKit : public Resources {
public:
	SmallMedicineKit() : Resources(10, '+', 1) {}; //constructor

	/* GETEFFECT FUNCTION
	*
	* @desc: Adds health to player according to its current health state
	* 
	* @param: Warrior object
	* 
	* @return: void
	*/

	void getEffect(Warrior* w) {
		cout << "-> You came across a Small Medicine Kit!  You got " << ((w->get_life() == 100) ? 0 : ((w->get_life() + Effect) > 100 ? ((100 + Effect) - w->get_life() - 10) : Effect)) << "HP\n";
		w->add_life(Effect);
	}
	
};


class LargeMedicineKit : public Resources {
public:
	LargeMedicineKit() : Resources(20, '*', 1) {}; //constructor


	/* GETEFFECT FUNCTION
	*
	* @desc: Adds health to player according to its current health state
	*
	* @param: Warrior object
	*
	* @return: void
	*/
	void getEffect(Warrior* w) {
		cout << "-> You came across a Large Medicine Kit! You got " << ((w->get_life() == 100) ? 0 : ((w->get_life() + Effect) > 100 ? ((100 + Effect) - w->get_life() - 10) : Effect)) << "HP\n";
		w->add_life(Effect);
	}
};

class Ammunition : public Resources {
public:
	Ammunition() : Resources(10,'A', 1) {  }; //constructor

	/* GETEFFECT FUNCTION
	*
	* @desc: Adds ammunition to player
	*
	* @param: Warrior object
	*
	* @return: void
	*/
	void getEffect(Warrior* w) {
		cout << "-> You came across a Ammunition Pack! You got 10 Bullets!\n";
		w->add_ammo(Effect);
	}
};

#endif // !
