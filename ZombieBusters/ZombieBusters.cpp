#include <iostream>
#include <time.h>
#include "Dice.h"
#include "Entity.h"
#include "Zombies.h"
#include "Resources.h"
#include "Battle.h"
#include "Derick.h"
#include "Chichonne.h"
using std::cout;

int main(){

	srand(time(NULL));

	Warrior* w = new Derick();
	Zombies* z = new LargeZombie();

	cout << Battle(*z, *w);
	return 0;
}