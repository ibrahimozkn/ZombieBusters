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
	
	int i;
	Grid* G = new Grid(7);
	G->deploy('D', 'C');
	G->print_grid();

	vector<coordinate> test = G->get_possible_destinations(1);
	for (i = 0; i < test.size(); i++) {
		cout << "\n" << test[i].x << ", " << test[i].y << "\n";
	}
	cout << "\n\n";
	int testx, testy;
	cin >> testx;
	cin >> testy;

	cout << "\n\n";

	G->move_warrior(1, testx, testy);
	/*for (i = 0; i < G->get_free_neighbors(testx, testy).size(); i++) {
		cout << G->get_free_neighbors(testx, testy)[i].x << ", " << G->get_free_neighbors(testx, testy)[i].y << "\n";
	}*/

	G->print_grid();
	

	return 0;
}