#include <iostream>
#include "Dice.h"
#include "Entity.h"
#include "Zombies.h"

using std::cout;

int main()
{
	srand(time(NULL));

	cout << rollDice(5);

	return 0;
}