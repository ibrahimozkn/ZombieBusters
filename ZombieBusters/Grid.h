/*  Adil Bozkurt Kebapçýoðlu - 2455954
I read and accept the submission rules and the important section specified in assignment file.
This is my own work that is done by myself and my team-mate only */
#ifndef GRID_H
#define GRID_H

#include "Entity.h"
#include <time.h>
#include <cmath>

struct element{
	int empty;
	Warrior* W;
	Resources* R;
	Zombies* Z;
	char character;
};

coordinate rand_coordinate(int);
int rand_divider(int);
bool found_struct_in_vector(int, int, vector<coordinate>);

class Grid {
private:
	int size;
	int tot_zombie_count;
	vector<vector<element>> grid;
	/*
	vector<Ammunition> ammo_vector;
	vector<SmallMedicineKit> s_med_vector;
	vector<LargeMedicineKit> l_med_vector;
	vector<SmallZombie> s_zombie_vector;
	vector<MediumZombie> m_zombie_vector;
	vector<LargeZombie> l_zombie_vector;*/

	coordinate P1_location;
	coordinate P2_location;

	Warrior* W1;
	Warrior* W2;

public:
	Grid(int s) {
		size = s;
		int i, j;
		for (i = 0; i < size; i++) {
			grid.push_back(vector<element>());
			for (j = 0; j < size; j++) {
				grid[i].push_back(element());
				grid[i][j].empty = 1;
				grid[i][j].W = NULL;
				grid[i][j].R = NULL;
				grid[i][j].Z = NULL;
				grid[i][j].character = '-';
			}
		}
	}

	//coordinate find_free_space();
	//void deploy_(char, char);
	
	void deploy(char, char);
	void deploy_derick(int);
	void deploy_chichonne(int);
	coordinate find_coordinate();

	vector<coordinate> get_possible_destinations(int);
	int move_warrior(int, int, int);

	int check_win_condition();

	vector<coordinate> get_free_neighbors(int, int);

	Warrior* get_warrior(int);

	void print_grid() {
		int i, j;
		for (i = 0; i < size; i++) {
			for (j = 0; j < size; j++) {
				if (grid[i][j].W != NULL) {
					cout << grid[i][j].W->get_Character();
				}
				else {
					cout << "-";
				}
				if (grid[i][j].R != NULL) {
					cout << grid[i][j].R->get_Character();
				}
				else {
					cout << "-";
				}
				if (grid[i][j].Z != NULL) {
					cout << grid[i][j].Z->get_Character() << " ";
				}
				else {
					cout << "- ";
				}
			}
			cout << "\n";
		}
	}
	void print_board();
};

void Grid::deploy(char p1, char p2) {
	int ammo_count, med_count, s_med_count, l_med_count, zombie_count, s_zombie_count, m_zombie_count, l_zombie_count;
	coordinate tmp; int rand_num;
	vector<coordinate> tmp_cvector;
	srand(time(NULL));
	//deploy warriors
	if (p1 == 'D') {
		deploy_derick(1);
	}
	else {
		deploy_chichonne(1);
	}
	if (p2 == 'D') {
		deploy_derick(2);
	}
	else {
		deploy_chichonne(2);
	}

	//find resource and zombie count
	ammo_count = 2 * ((size * size) / 25);
	med_count = 3 * ((size * size) / 25);
	s_med_count = rand_divider(med_count);
	l_med_count = med_count - s_med_count;
	zombie_count = (2 * ((size * size) / 25) <= 3) ? 3 : (2 * ((size * size) / 25));
	tot_zombie_count = zombie_count;
	s_zombie_count = 1;
	m_zombie_count = 1;
	l_zombie_count = 1;
	if (zombie_count > 3) {
		while ((zombie_count - 3) > 0) {
			if (rand() % 3 == 0) {
				s_zombie_count++;
			}
			else if (rand() % 3 == 1) {
				m_zombie_count++;
			}
			else {
				l_zombie_count++;
			}
			zombie_count--;
		}
	}
	
	//deploy ammo
	//Ammunition a;
	while (ammo_count > 0) {
		tmp = find_coordinate();
		//ammo_vector.push_back(Ammunition());
		//cout << "\nammo char: " << ammo_vector[ammo_vector.size() - 1].get_Character() << "\n";
		Ammunition *a = new Ammunition();
		grid[tmp.x][tmp.y].R = a;
			//&ammo_vector[ammo_vector.size() - 1];
		grid[tmp.x][tmp.y].empty = 0;
		grid[tmp.x][tmp.y].R->add_coordinate(tmp.x, tmp.y);
		ammo_count--;
	}
	
	//deploy medkits
	//SmallMedicineKit sm;
	
	while (s_med_count > 0) {
		tmp = find_coordinate();
		//s_med_vector.push_back(SmallMedicineKit());
		SmallMedicineKit *sm = new SmallMedicineKit();
		grid[tmp.x][tmp.y].R = sm;
			//&s_med_vector[s_med_vector.size() - 1];
		grid[tmp.x][tmp.y].empty = 0;
		grid[tmp.x][tmp.y].R->add_coordinate(tmp.x, tmp.y);
		s_med_count--;
	}
	while (l_med_count > 0) {
		
		tmp = find_coordinate();
		//l_med_vector.push_back(LargeMedicineKit());
		LargeMedicineKit *lm = new LargeMedicineKit();
		grid[tmp.x][tmp.y].R = lm;
			//&l_med_vector[l_med_vector.size() - 1];
		grid[tmp.x][tmp.y].empty = 0;
		grid[tmp.x][tmp.y].R->add_coordinate(tmp.x, tmp.y);

		tmp_cvector = get_free_neighbors(tmp.x, tmp.y);
		rand_num = rand() % (tmp_cvector.size());
		grid[tmp_cvector[rand_num].x][tmp_cvector[rand_num].y].R = lm;
			//&l_med_vector[l_med_vector.size() - 1];
		grid[tmp_cvector[rand_num].x][tmp_cvector[rand_num].y].empty = 0;
		grid[tmp_cvector[rand_num].x][tmp_cvector[rand_num].y].R->add_coordinate(tmp_cvector[rand_num].x, tmp_cvector[rand_num].y);

		l_med_count--;
	}
	//deploy zombies
	
	while (s_zombie_count > 0) {
		tmp = find_coordinate();
		//s_zombie_vector.push_back(SmallZombie());
		SmallZombie *sz = new SmallZombie();
		grid[tmp.x][tmp.y].Z = sz;
			//&s_zombie_vector[(s_zombie_vector.size() - 1)];
		grid[tmp.x][tmp.y].empty = 0;
		grid[tmp.x][tmp.y].Z->add_coordinate(tmp.x, tmp.y);
		s_zombie_count--;
	}
	while (m_zombie_count > 0) {
		tmp = find_coordinate();
		//m_zombie_vector.push_back(MediumZombie());
		MediumZombie *mz = new MediumZombie();
		grid[tmp.x][tmp.y].Z = mz;
			//&m_zombie_vector[(m_zombie_vector.size() - 1)];
		grid[tmp.x][tmp.y].empty = 0;
		grid[tmp.x][tmp.y].Z->add_coordinate(tmp.x, tmp.y);

		tmp_cvector = get_free_neighbors(tmp.x, tmp.y);
		if (tmp_cvector.size() == 0) {
			continue;
		}
		rand_num = rand() % (tmp_cvector.size());
		grid[tmp_cvector[rand_num].x][tmp_cvector[rand_num].y].Z = mz;
			//&m_zombie_vector[m_zombie_vector.size() - 1];
		grid[tmp_cvector[rand_num].x][tmp_cvector[rand_num].y].empty = 0;
		grid[tmp_cvector[rand_num].x][tmp_cvector[rand_num].y].Z->add_coordinate(tmp_cvector[rand_num].x, tmp_cvector[rand_num].y);

		m_zombie_count--;
	}
	while (l_zombie_count > 0) {
		tmp = find_coordinate();
		LargeZombie *lz = new LargeZombie();
		//l_zombie_vector.push_back(LargeZombie());
		grid[tmp.x][tmp.y].Z = lz;
			//&l_zombie_vector[(l_zombie_vector.size() - 1)];
		grid[tmp.x][tmp.y].empty = 0;
		grid[tmp.x][tmp.y].Z->add_coordinate(tmp.x, tmp.y);

		tmp_cvector = get_free_neighbors(tmp.x, tmp.y);
		rand_num = rand() % (tmp_cvector.size());
		grid[tmp_cvector[rand_num].x][tmp_cvector[rand_num].y].Z = lz;
			//&l_zombie_vector[l_zombie_vector.size() - 1];
		grid[tmp_cvector[rand_num].x][tmp_cvector[rand_num].y].empty = 0;
		grid[tmp_cvector[rand_num].x][tmp_cvector[rand_num].y].Z->add_coordinate(tmp_cvector[rand_num].x, tmp_cvector[rand_num].y);

		
		tmp_cvector = get_free_neighbors(tmp_cvector[rand_num].x, tmp_cvector[rand_num].y);
		if (tmp_cvector.size() != 0) {
			rand_num = rand() % (tmp_cvector.size());
			grid[tmp_cvector[rand_num].x][tmp_cvector[rand_num].y].Z = lz;
				//&l_zombie_vector[l_zombie_vector.size() - 1];
			grid[tmp_cvector[rand_num].x][tmp_cvector[rand_num].y].empty = 0;
			grid[tmp_cvector[rand_num].x][tmp_cvector[rand_num].y].Z->add_coordinate(tmp_cvector[rand_num].x, tmp_cvector[rand_num].y);
		}

		l_zombie_count--;
	}
	cout << "\nINFO -> There are " << tot_zombie_count << " zombies remaining to kill!\n";
}

void Grid::deploy_derick(int player) {
	coordinate tmp = rand_coordinate(size);
	while (grid[tmp.x][tmp.y].empty == 0) {
		tmp = rand_coordinate(size);
	}

	Derick* derick = new Derick();
	grid[tmp.x][tmp.y].W = derick;
	grid[tmp.x][tmp.y].character = 'D';
	grid[tmp.x][tmp.y].empty = 0;

	grid[tmp.x][tmp.y].W->add_coordinate(tmp.x, tmp.y);
	if (player == 1) {
		P1_location.x = tmp.x;
		P1_location.y = tmp.y;
		W1 = derick;
	}
	else {
		P2_location.x = tmp.x;
		P2_location.y = tmp.y;
		W2 = derick;
	}
}
void Grid::deploy_chichonne(int player) {
	coordinate tmp = rand_coordinate(size);
	while (grid[tmp.x][tmp.y].empty == 0) {
		tmp = rand_coordinate(size);
	}

	Chichonne* chichonne = new Chichonne();
	grid[tmp.x][tmp.y].W = chichonne;
	grid[tmp.x][tmp.y].character = 'C';
	grid[tmp.x][tmp.y].empty = 0;

	grid[tmp.x][tmp.y].W->add_coordinate(tmp.x, tmp.y);
	if (player == 1) {
		P1_location.x = tmp.x;
		P1_location.y = tmp.y;
		W1 = chichonne;
	}
	else {
		P2_location.x = tmp.x;
		P2_location.y = tmp.y;
		W2 = chichonne;
	}
}

coordinate Grid::find_coordinate() {
	int tmpx = rand() % size;
	int tmpy = rand() % size;

	while (grid[tmpx][tmpy].empty == 0) {
		tmpx = rand() % size;
		tmpy = rand() % size;
	}
	coordinate tmp_coordinate = { tmpx,tmpy };

	return tmp_coordinate;
}

vector<coordinate> Grid::get_possible_destinations(int player) {
	int tmpx, tmpy, i, j;
	vector<coordinate> tmp;
	if (player == 1) {
		tmpx = P1_location.x;
		tmpy = P1_location.y;
	}
	else {
		tmpx = P2_location.x;
		tmpy = P2_location.y;
	}

	for (i = -1; i < 2; i++) {
		for (j = -1; j < 2; j++) {
			if (((tmpx + i) >= 0 && (tmpy + j) >= 0) && ((tmpx + i < size) && (tmpy + j < size)) && !(found_struct_in_vector(tmpx + i, tmpy + j, grid[tmpx][tmpy].W->get_past_coordinates()))) {
				if (grid[(tmpx + i)][(tmpy + j)].W == NULL) {
					tmp.push_back({ tmpx + i, tmpy + j });
				}
			}
		}
	}

	return tmp;
}

int Grid::move_warrior(int player, int X, int Y) {
	vector<coordinate> tmp;
	
	int i = 0;
	if (player == 1) {
		grid[X][Y].W = grid[P1_location.x][P1_location.y].W;
		grid[X][Y].W->add_coordinate(X, Y);
		grid[P1_location.x][P1_location.y].W = NULL;
		P1_location.x = X;
		P1_location.y = Y;
	}
	else {
		grid[X][Y].W = grid[P2_location.x][P2_location.y].W;
		grid[X][Y].W->add_coordinate(X, Y);
		grid[P2_location.x][P2_location.y].W = NULL;
		P2_location.x = X;
		P2_location.y = Y;
	}

	if (grid[X][Y].R != NULL) {
		grid[X][Y].R->getEffect(grid[X][Y].W);
		tmp = grid[X][Y].R->get_coordinates();
		print_board();
		while (i < tmp.size()) {
			grid[tmp[i].x][tmp[i].y].R = NULL;
			i++;
		}
	}
	else if (grid[X][Y].Z != NULL) {
		if (Battle(grid[X][Y].Z, grid[X][Y].W) == 1) {
			cout << "\nYou killed the zombie!!\n";
			tmp = grid[X][Y].Z->get_coordinates();
			i = 0;
			print_board();
			while (i < tmp.size()) {
				grid[tmp[i].x][tmp[i].y].Z = NULL;
				i++;
			}
			//delete[] grid[X][Y].Z;

			tot_zombie_count--;
			cout << "\nINFO -> There are " << tot_zombie_count << " zombies remaining to kill!\n";
		}
		else {
			cout << "RIP -> Oh no! Zombie killed you.\n";

			grid[X][Y].W = NULL;
			print_board();
			return 0;
		}
	}
	else {
		print_board();
	}
	return 1;
	
}

int Grid::check_win_condition() {
	if (tot_zombie_count <= 0) { //if all zombies are killed
		return -1;
	}
	else if(W1->check_alive() == 1 || W2->check_alive() == 1){ //if one of the players are alive
		return 1;
	}
	else { //if both are dead and there are still alive zombies left
		return 0;
	}
}

vector<coordinate> Grid::get_free_neighbors(int X, int Y) {
	int i, j;
	vector<coordinate> tmp;

	for (i = -1; i < 2; i++) {
		for (j = -1; j < 2; j++) {
			if (((X + i) >= 0 && (Y + j) >= 0) && ((X + i < size) && (Y + j < size))) {
				if (grid[(X + i)][(Y + j)].W == NULL && grid[(X + i)][(Y + j)].R == NULL && grid[(X + i)][(Y + j)].Z == NULL) {
					tmp.push_back({ X + i, Y + j });
				}
			}
		}
	}

	return tmp;

}

Warrior* Grid::get_warrior(int player) {
	if (player == 1) {
		return W1;
	}
	else {
		return W2;
	}
}

void Grid::print_board() {
	int i, j, k;
	cout << "     ";
	for (k = 0; k < size; k++) {
		cout << "     "<< k << "     ";
	}

	cout << "\n";
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (grid[i][j].W != NULL) {
				if (j == 0) {
					cout << i << "     [ " << grid[i][j].W->get_Character();
				}
				else {
					cout << "[ " << grid[i][j].W->get_Character();
				}
				
				if (grid[i][j].R != NULL) {
					cout << "  ](" << grid[i][j].R->get_Character() << ")" << "  ";
				}
				else if (grid[i][j].Z != NULL) {
					cout << "  ](" << grid[i][j].Z->get_Character() << ")" << "  ";
				}
				else {
					cout << "  (-)]" << "  ";
				}
			}
			else {
				if (j == 0) {
					cout<< i << "     [       ]  ";
				}
				else {
					cout << "[       ]  ";
				}
				
			}
		}
		cout << "\n\n";
	}
}

coordinate rand_coordinate(int n) {
	coordinate tmp;
	tmp.x = rand() % n;
	tmp.y = rand() % n;
	return tmp;
}

int rand_divider(int a) {
	int b = 1;
	while (a > 0) {
		if (rand() % 2 == 1) {
			b++;
		}
		a--;
		return b;
	}
}

bool found_struct_in_vector(int X, int Y, vector<coordinate> v) {
	int i;
	for (i = 0; i < v.size(); i++) {
		if (X == v[i].x && Y == v[i].y) {
			return true;
		}
	}
	return false;
}

#endif