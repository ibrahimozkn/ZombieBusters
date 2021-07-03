#ifndef RESOURCES_H
#define RESOURCES_H

#include "Entity.h"

class Resources : public Entity {
private:
	int Effect;
public:
	Resources(char C, int Size) : Entity(C, Size) {};
};

class MedicineKit : public Resources {
protected:
	int Heal;

public:
	MedicineKit(int hp, char C, int Size) : Resources(C, Size) {
		this->Heal = hp;
	}

	int getHeal() {
		return this->Heal;
	}
};

class SmallMedicineKit : public MedicineKit {
public:
	SmallMedicineKit() : MedicineKit(10, '+', 1) {};

};

class LargeMedicineKit : public MedicineKit {
public:
	LargeMedicineKit() : MedicineKit(20, '*', 2) {};
};

class Ammunition : public Resources {
private:
	int Ammo;
public:
	Ammunition() : Resources('A', 1) { this->Ammo = 10; };

	int getAmmo() { return this->Ammo; };
};

#endif // !
