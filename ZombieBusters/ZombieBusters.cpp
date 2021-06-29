#include <iostream>
#include "Dice.h"
#include "Entity.h"
#include "Zombies.h"

using std::cout;

int main()
{
	Zombies* z;
	z = new SmallZombie();
	cout << z->getLife();

	return 0;
}