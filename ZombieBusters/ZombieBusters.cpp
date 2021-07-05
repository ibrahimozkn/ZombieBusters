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
	
	cout << "-------------------------------------------------------------------------\n";
	cout << R"(
 ______                _     _       ______           _                
|___  /               | |   (_)      | ___ \         | |               
   / /  ___  _ __ ___ | |__  _  ___  | |_/ /_   _ ___| |_ ___ _ __ ___ 
  / /  / _ \| '_ ` _ \| '_ \| |/ _ \ | ___ \ | | / __| __/ _ \ '__/ __|
./ /__| (_) | | | | | | |_) | |  __/ | |_/ / |_| \__ \ ||  __/ |  \__ \
\_____/\___/|_| |_| |_|_.__/|_|\___| \____/ \__,_|___/\__\___|_|  |___/
                                                                       
                                                                      )";
	cout << "\n-------------------------------------------------------------------------\n";
	cout << "\n-> Welcome to ZombieBusters!\n-> Your goal is to clear the island which is raided by the zombies! \n-> The objective of the game is to clean the island together;"
		<< "however, you can also score and compete with your teammate depending on the number and sizes of the Zombies you kill.\n";

	int i;
	Grid* G = new Grid(5);
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