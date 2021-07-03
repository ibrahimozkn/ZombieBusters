#include <iostream>
#include <time.h>
#include "Dice.h"
#include "Entity.h"
#include "Zombies.h"
#include "Resources.h"
#include "Battle.h"
#include "Derick.h"
#include "Chichonne.h"
#include "Grid.h"
using std::cout;

int main(){


	Grid* G = new Grid(5);
	coordinate* c1 = new coordinate();
	coordinate* c2 = new coordinate();
	c1->x = 0;
	c1->y = 0;
	c2->x = 3;
	c2->y = 4;
	G->initialize_grid('D', c1, 'C', c2);
	G->print_grid();
	

	return 0;
}