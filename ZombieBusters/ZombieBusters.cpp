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
using std::cin;

int main(){
	srand(time(NULL));
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


	char Player1, Player2;
	int warriorPicker;

	Grid* island;

	if (chooseDice() == 1) {
		cout << "\n-> Player 1, choose your warrior \n->1. Derick\n->2. Chichonne\n";

		while (1) {
			cout << "-> ";
			cin >> warriorPicker;

			if (warriorPicker == 1) {
				Player1 = 'D';

				Player2 = 'C';
				cout << "-> Player1 chose Derick. Player2 plays the game as Chichonne\n";
				break;
			}else if (warriorPicker == 2) {
				Player1 = 'C';

				Player2 = 'D';
				cout << "-> Player1 chose Chichonne. Player2 plays the game as Derick\n";
				break;
			}else {
				cout << "!> Wrong option! Enter (1) for Derick, (2) for Chichonne\n";
				continue;
			}
		}


	}
	else {
		cout << "\n-> Player 2, choose your warrior \n->1. Derick\n->2. Chichonne\n";
		
		while (1) {
			cout << "-> ";
			cin >> warriorPicker;

			if (warriorPicker == 1) {
				Player1 = 'D';

				Player2 = 'C';
				cout << "-> Player2 chose Derick. Player1 plays the game as Chichonne\n";
				break;
			}else if (warriorPicker == 2) {
				Player1 = 'C';

				Player2 = 'D';
				cout << "-> Player2 chose Chichonne. Player1 plays the game as Derick\n";
				break;
			}
			else {
				cout << "!> Wrong option! Enter (1) for Derick, (2) for Chichonne\n";
				continue;
			}
			}
	}

	int islandSize;

	cout << "\n-> Enter the size of the island that you want to play in (Only enter one side of the nxn island Eg: 5 for 5x5 island): ";
	cin >> islandSize;

	island = new Grid(islandSize);






	return 0;
}