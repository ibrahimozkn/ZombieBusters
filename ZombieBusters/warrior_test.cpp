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

int main() {

	Derick* D = new Derick();
	Chichonne* C = new Chichonne();

	cout << D->get_life << "\n";
	cout << D->get_ammo << "\n";

	D->add_life(50);
	D->add_ammo(50);

	cout << D->get_life << "\n";
	cout << D->get_ammo << "\n";

	return 0;
}