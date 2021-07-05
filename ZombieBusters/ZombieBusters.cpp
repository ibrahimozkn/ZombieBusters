/* Ibrahim Ozkan – 2456275 - Adil Bozkurt Kebapçýoðlu - 2455954
I read and accept the submission rules and the important section specified in assignment file.
This is my own work that is done by myself and my team-mate only */
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
#include <Windows.h>

using namespace std;

void printDestinations(vector<coordinate>);
void printStats(Warrior*);

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
	int p1Alive = 1, p2Alive = 1;

	Grid* island;
	Warrior* tempWarrior = nullptr;

	if (chooseDice() == 1) { //if dice returns 1, Player 1 starts first
		cout << "\n-> Player 1, choose your warrior \n->1. Derick\n->2. Chichonne\n";

		while (1) { //let player pick warrior
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
	else { //if dice returns 2, Player 2 starts first
		cout << "\n-> Player 2, choose your warrior \n->1. Derick\n->2. Chichonne\n";
		
		while (1) { //let player choose warrior
			cout << "-> ";
			cin >> warriorPicker;

			if (warriorPicker == 1) {
				Player1 = 'C';

				Player2 = 'D';
				cout << "-> Player2 chose Derick. Player1 plays the game as Chichonne\n";
				break;
			}else if (warriorPicker == 2) {
				Player1 = 'D';

				Player2 = 'C';
				cout << "-> Player2 chose Chichonne. Player1 plays the game as Derick\n";
				break;
			}
			else {
				cout << "!> Wrong option! Enter (1) for Derick, (2) for Chichonne\n";
				continue;
			}
			}
	}

	int islandSize = 0;

	while (islandSize < 5) { //if island size is less than 5, take input again
		cout << "\n-> Enter the size of the island that you want to play in and must be greater than or equal to 5\n(Only enter one side of the nxn island Eg: 10 for 10x10 island): ";
		cin >> islandSize;
	}


	island = new Grid(islandSize); //initialize island (grid)


	cout << "-> Please wait, creating the island\n";
	Sleep(3000);
	island->deploy(Player1, Player2); //deploy grid
	cout << "-> Island created successfully!\n";
	island->print_board(); //print grid
	
	int startsFirst, xCoordinate, yCoordinate, currCondition;
	char dummy = '.';
	vector<coordinate> possibleDest;

	startsFirst = (chooseDice() == 1) ? 1 : -1; //choose which player is going to start first
	cout << ((startsFirst == 1) ? "\n\n-> Computer rolled the dice and Player 1 plays first!\n" : "-> Computer rolled the dice and Player 2 plays first!\n");
	
	while (island->check_win_condition() > 0 && (p1Alive == 1 ||p2Alive == 1)) { //play the game until win or lose condition occurs

		if (startsFirst == 1) { //if player1 starts first
			possibleDest = island->get_possible_destinations(1); 
			cout << "\n-> Player 1, ";
			printDestinations(possibleDest); //print possible destinations

			cout << "!> Please enter your coordinate as x,y (eg. 10,20): ";
			cin >> xCoordinate >> dummy >> yCoordinate;

			currCondition = island->move_warrior(1, xCoordinate, yCoordinate); //move the warrior to given coordinate

			if (currCondition == 0) { //if currCondition is 0, mark the player1 dead
				p1Alive = 0;
			}
			else { //print the stats
				cout << "\n==================== YOUR STATS PLAYER 1 ====================\n";
				tempWarrior = island->get_warrior(1);
				printStats(tempWarrior);
				cout << "\nSTATS -> Player1's kill history: ";
				tempWarrior->print_kill_history();
				cout << "\nSTATS -> Total Score: " << tempWarrior->get_score() << "\n";
				cout << "=============================================================\n";


			}
			


		}
		else if(startsFirst == -1){ //if player 2 starts first
			possibleDest = island->get_possible_destinations(2);
			cout << "\n-> Player 2, ";
			printDestinations(possibleDest); //print possible coordinations for player 2

			cout << "!> Please enter your coordinate as x,y (eg. 10,20): ";
			cin >> xCoordinate >> dummy >> yCoordinate;

			currCondition = island->move_warrior(2, xCoordinate, yCoordinate); //move the warrior to given coordinate
			
			if (currCondition == 0) { //if player 2 is dead, mark player 2 dead
				p2Alive = 0;
			}else { //print stats
				cout << "\n==================== YOUR STATS PLAYER 2 ====================\n";
				tempWarrior = island->get_warrior(2);
				printStats(tempWarrior);
				cout << "\nSTATS -> Player2's kill history: ";
				tempWarrior->print_kill_history();
				cout << "=============================================================\n";
			}

		}

		if (p1Alive == 1 && p2Alive == 1) { //if both player is alive, alternate the turns
			startsFirst = startsFirst * -1;
		}
		else if (p1Alive == 0) { //if player1 is dead, only player 2 plays
			startsFirst = -1;
		}
		else if (p2Alive == 0) { //if player2 is dead, only player 1 plays
			startsFirst = 1;
		}

		



	}

	Warrior* w1, * w2;
	w1 = island->get_warrior(1);
	w2 = island->get_warrior(2);

	if (p1Alive == 0 && p2Alive == 0) { //if both players are dead
		cout << "LOSERS -> You and your teammate lost the game :(\n";
	}
	else if(p1Alive == 1 && p2Alive == 1){ //if both players finished alive
		cout << "CONGRATULATIONS ->  You both managed to kill all the zombies and stay alive together! However, there can only be one winner\n" <<
			"AND THAT WINNER IS!!!!!\n";
		if (w1->get_score() > w2->get_score()) { //if player1's score is greater than player2
			cout << "PLAYER 1 its you buddy! You won the game with a score of " << w1->get_score() <<  "\nTo claim your reward, visit: https://bit.ly/3xlCh1E \n";
			cout << "\nMy loser friend PLAYER 2, don't worry I have a surprise for you as well. At least you lost the game with an honor and dignity.\n" << 
				"Here is your current score: " << w2->get_score() << ". You can claim your reward, visit: https://www.youtube.com/watch?v=G1IbRujko-A \n";
		}
		else if (w1->get_score() < w2->get_score()) { //if player2's score is greater than player1
			cout << "PLAYER 2 its you buddy! You won the game with a score of " << w2->get_score() << "\nTo claim your reward, visit: https://bit.ly/3xlCh1E \n";
			cout << "\nMy loser friend PLAYER 1, don't worry I have a surprise for you as well. At least you lost the game with an honor and dignity.\n" <<
				"Here is your current score: " << w1->get_score() << ". You can claim your reward, visit: https://www.youtube.com/watch?v=G1IbRujko-A \n";
		}
		else if (w1->get_score() == w2->get_score()) { //if draw
			cout << "PLAYER 1 and PLAYER 2 its you guys! You both won the game with a equal score of " << w2->get_score() << "\nTo claim your reward, visit: https://bit.ly/3xlCh1E \n";
		}
	}
	else if (p1Alive == 1 && p2Alive == 0) { //if only player 1 is alive
		cout << "CONGRATULATIONS ->  PLAYER 1 managed to kill all the zombies without help of loser PLAYER 2!\n You won the game with a score of " << w1->get_score() <<
			"\nTo claim your reward, visit: https://bit.ly/3xlCh1E \n";
		cout << "\nMy loser friend PLAYER 2, don't worry I have a surprise for you as well. At least you lost the game with an honor and dignity.\n" <<
			"Here is your current score: " << w2->get_score() << ". You can claim your reward, visit: https://www.youtube.com/watch?v=G1IbRujko-A \n";
	
	}else if(p1Alive == 0 && p2Alive == 1) { //if only player 2 is alive
		cout << "CONGRATULATIONS ->  PLAYER 2 managed to kill all the zombies without help of loser PLAYER 2!\n You won the game with a score of " << w2->get_score() <<
			"\nTo claim your reward, visit: https://bit.ly/3xlCh1E \n";
		cout << "\nMy loser friend PLAYER 1, don't worry I have a surprise for you as well. At least you lost the game with an honor and dignity.\n" <<
			"Here is your current score: " << w1->get_score() << ". You can claim your reward, visit: https://www.youtube.com/watch?v=G1IbRujko-A \n";
		
	}

	

	delete[] w1, w2;
	delete[] island;
	delete[] tempWarrior;

	return 0;
}

void printDestinations(vector<coordinate> v) { //prints the contents of vector
	int i;
	cout << "Choose one of the destinations: ";
	for (i = 0; i < v.size(); i++) {
		cout << "[" << v[i].x << "," << v[i].y << "] ";
	}
	cout << "\n";
}

void printStats(Warrior* w) { //prints stats of warrior
	cout << "STATS -> HP: " << w->get_life() <<
		" AMMO: " << w->get_ammo();
}
