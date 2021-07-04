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
	

	Grid* G = new Grid(7);
	G->deploy('D', 'C');
	G->print_grid();
	

	return 0;
}