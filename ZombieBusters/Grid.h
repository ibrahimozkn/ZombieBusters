#ifndef GRID_H
#define GRID_H

#include "Entity.h"
#include <time.h>

struct element{
	int empty;
	Warrior* W;
	Resources* R;
	Zombies* Z;
	char character;
};

coordinate rand_coordinate(int);
int rand_divider(int);

class Grid {
private:
	int size;
	vector<vector<element>> grid;

	vector<Ammunition*> ammo_vector;
	vector<SmallMedicineKit*> s_med_vector;
	vector<LargeMedicineKit*> l_med_vector;
	vector<SmallZombie*> s_zombie_vector;
	vector<MediumZombie*> m_zombie_vector;
	vector<LargeZombie*> l_zombie_vector;

	coordinate P1_location;
	coordinate P2_location;

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

	void print_grid() {
		int i, j;
		for (i = 0; i < size; i++) {
			for (j = 0; j < size; j++) {
				cout << grid[i][j].character << " ";
			}
			cout << "\n";
		}
	}
};
/*
void Grid::deploy_(char C1, char C2) {
	srand(time(NULL));
	vector<coordinate> tmpvector;
	int randx = rand() % size;
	int randy = rand() % size;
	int randx2 = rand() % size;
	int randy2 = rand() % size;

	int ammo_count = 2 * ((size * size) / 25);
	vector<Ammunition*> ammo_vector;
	int ammo_index = 0;

	int med_count = 3 * ((size * size) / 25);

	int large_medcount = 0;
	vector<LargeMedicineKit*> large_med_vector;
	int large_med_index = 0;

	int small_medcount = 0;
	vector<SmallMedicineKit*> small_med_vector;
	int small_med_index = 0;
	/*
	int zombie_count = 2 * ((size * size) / 25);

	int large_zombie_count = 1;
	vector<LargeZombie*> large_zombie_vector;
	int large_zombie_index = 0;

	int medium_zombie_count = 1;
	vector<MediumZombie*> medium_zombie_vector;
	int medium_zombie_index = 0;

	int small_zombie_count = 1;
	vector<SmallZombie*> small_zombie_vector;
	int small_zombie_index = 0;
	
	int tmpx, tmpy;

	if (C1 == 'D') {
		Derick* derick1 = new Derick();
		grid[randx][randy].E = derick1;
		grid[randx][randy].character = 'D';
		grid[randx][randy].empty = 0;
	}
	else if (C1 == 'C') {
		Chichonne* chichonne1 = new Chichonne();
		grid[randx][randy].E = chichonne1;
		grid[randx][randy].character = 'C';
		grid[randx][randy].empty = 0;
	}
	while (randx == randx2 && randy == randy2) {
		randx2 = rand() % size;
		randy2 = rand() % size;
	}
	if (C2 == 'D') {
		Derick* derick2 = new Derick();
		grid[randx2][randy2].E = derick2;
		grid[randx2][randy2].character = 'D';
		grid[randx2][randy2].empty = 0;
	}
	else if (C2 == 'C') {
		Chichonne* chichonne2 = new Chichonne();
		grid[randx2][randy2].E = chichonne2;
		grid[randx2][randy2].character = 'C';
		grid[randx2][randy2].empty = 0;
	}

	

	while (ammo_count > 0) {

		tmpvector = find_free_space(1);
		tmpx = tmpvector[0].x;
		tmpy = tmpvector[0].y;
		tmpvector.clear();
		tmpvector.shrink_to_fit();

		Ammunition* a;
		ammo_vector.push_back(a);
		grid[tmpx][tmpy].E = ammo_vector[ammo_index];
		grid[tmpx][tmpy].character = 'A';
		grid[tmpx][tmpy].empty = 0;
		ammo_index++;

		ammo_count--;
	}
	cout << "test b4 med";
	while (med_count > 0) {
		if (rand() % 2 == 1) {
			large_medcount++;
		}
		else {
			small_medcount++;
		}
		med_count--;
	}
	cout << "test b4 small med";
	while (small_medcount > 0) {

		tmpvector = find_free_space(1);
		tmpx = tmpvector[0].x;
		tmpy = tmpvector[0].y;
		tmpvector.clear();
		tmpvector.shrink_to_fit();

		SmallMedicineKit* sm;
		small_med_vector.push_back(sm);
		grid[tmpx][tmpy].E = small_med_vector[small_med_index];
		grid[tmpx][tmpy].character = '+';
		grid[tmpx][tmpy].empty = 0;
		small_med_index++;

		small_medcount--;
	}
	cout << "test b4 large med";
	while (large_medcount > 0) {
		tmpvector = find_free_space(2);
		

		tmpx = tmpvector[0].x;
		tmpy = tmpvector[0].y;
		tmpvector.clear();
		tmpvector.shrink_to_fit();

		LargeMedicineKit* lm;
		large_med_vector.push_back(lm);
		grid[tmpx][tmpy].E = large_med_vector[large_med_index];
		grid[tmpx][tmpy].character = '*';
		grid[tmpx][tmpy].empty = 0;

		tmpx = tmpvector[1].x;
		tmpy = tmpvector[1].y;

		grid[tmpx][tmpy].E = large_med_vector[large_med_index];
		grid[tmpx][tmpy].character = '*';
		grid[tmpx][tmpy].empty = 0;

		large_med_index++;

		large_medcount--;
	}
	
	//small
	
	tmpvector = find_free_space(1);
	tmpx = tmpvector[0].x;
	tmpy = tmpvector[0].y;

	SmallZombie* s;
	small_zombie_vector.push_back(s);
	grid[tmpx][tmpy].E = small_zombie_vector[small_zombie_index];
	grid[tmpx][tmpy].character = 'S';
	grid[tmpx][tmpy].empty = 0;
	small_zombie_index++;

	small_zombie_count--;
	//medium
	tmpvector = find_free_space(2);

	tmpx = tmpvector[0].x;
	tmpy = tmpvector[0].y;
	
	MediumZombie* m;
	medium_zombie_vector.push_back(m);
	grid[tmpx][tmpy].E = medium_zombie_vector[medium_zombie_index];
	grid[tmpx][tmpy].character = 'M';
	grid[tmpx][tmpy].empty = 0;

	tmpx = tmpvector[1].x;
	tmpy = tmpvector[1].y;

	grid[tmpx][tmpy].E = medium_zombie_vector[medium_zombie_index];
	grid[tmpx][tmpy].character = 'M';
	grid[tmpx][tmpy].empty = 0;

	medium_zombie_index++;

	medium_zombie_count--;
	// medium end
	
	if (zombie_count > 3) {
		while (zombie_count - 3 > 0) {

			if (rand() % 3 == 0) {
				large_zombie_count++;
			}
			else if(rand() % 3 == 1){
				medium_zombie_count++;
			}
			else {
				small_zombie_count++;
			}
			zombie_count--;
		}

		while (small_zombie_count > 0) {

			tmpvector = find_free_space(1);
			tmpx = tmpvector[0].x;
			tmpy = tmpvector[0].y;

			SmallZombie* s;
			small_zombie_vector.push_back(s);
			grid[tmpx][tmpy].E = small_zombie_vector[small_zombie_index];
			grid[tmpx][tmpy].character = 'S';
			grid[tmpx][tmpy].empty = 0;
			small_zombie_index++;

			small_zombie_count--;
		}

		while (medium_zombie_count > 0) {
			tmpvector = find_free_space(2);

			tmpx = tmpvector[0].x;
			tmpy = tmpvector[0].y;

			MediumZombie* s;
			medium_zombie_vector.push_back(s);
			grid[tmpx][tmpy].E = medium_zombie_vector[medium_zombie_index];
			grid[tmpx][tmpy].character = 'M';
			grid[tmpx][tmpy].empty = 0;

			tmpx = tmpvector[1].x;
			tmpy = tmpvector[1].y;

			grid[tmpx][tmpy].E = medium_zombie_vector[medium_zombie_index];
			grid[tmpx][tmpy].character = 'M';
			grid[tmpx][tmpy].empty = 0;

			medium_zombie_index++;

			medium_zombie_count--;
		}
	}
	cout << "test end";
}

coordinate Grid::find_free_space() {
	int tmpx = rand() % size;
	int tmpy = rand() % size;

	while (grid[tmpx][tmpy].empty == 0) {
		tmpx = rand() % size;
		tmpy = rand() % size;
	}
	coordinate tmp_coordinate = { tmpx,tmpy }
	
	return tmp_coordinate;
}
*/
void Grid::deploy(char p1, char p2) {
	int ammo_count, med_count, s_med_count, l_med_count, zombie_count, s_zombie_count, m_zombie_count, l_zombie_count;
	coordinate tmp;
	srand(time(NULL));
	//deploy warriors
	if (p1 == 'D') {
		deploy_derick();
	}
	else {
		deploy_chichonne();
	}
	if (p2 == 'D') {
		deploy_derick();
	}
	else {
		deploy_chichonne();
	}

	//find resource and zombie count
	ammo_count = 2 * ((size * size) / 25);
	med_count = 3 * ((size * size) / 25);
	s_med_count = rand_divider(med_count);
	l_med_count = med_count - s_med_count;
	zombie_count = 2 * ((size * size) / 25);
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
	Ammunition a;
	while (ammo_count > 0) {
		tmp = find_coordinate();
		grid[tmp.x][tmp.y].R = &a;
		grid[tmp.x][tmp.y].character = 'A';
		grid[tmp.x][tmp.y].empty = 0;
		ammo_count--;
	}
	//deploy medkits
	SmallMedicineKit sm;
	while (s_med_count > 0) {
		tmp = find_coordinate();
		grid[tmp.x][tmp.y].R = &sm;
		grid[tmp.x][tmp.y].character = '+';
		grid[tmp.x][tmp.y].empty = 0;
		s_med_count--;
	}
	//deploy zombies
	while (s_zombie_count > 0) {
		tmp = find_coordinate();
		SmallZombie* sz;
		s_zombie_vector.push_back(sz);
		grid[tmp.x][tmp.y].Z = s_zombie_vector[(s_zombie_vector.size() - 1)];
		grid[tmp.x][tmp.y].character = 'S';
		grid[tmp.x][tmp.y].empty = 0;
		s_zombie_count--;
	}
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
	}
	else {
		P2_location.x = tmp.x;
		P2_location.y = tmp.y;
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
	}
	else {
		P2_location.x = tmp.x;
		P2_location.y = tmp.y;
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
			if (((tmpx + i) >= 0 && (tmpy + j) >= 0) && !((tmpx + i == tmpx) && (tmpy + j == tmpy))) {
				if (grid[(tmpx + i)][(tmpy + j)].W == NULL) {
					tmp.push_back({ tmpx + i, tmpy + j });
				}
			}
		}
	}

	return tmp;
}

coordinate rand_coordinate(int n) {
	coordinate tmp;
	tmp.x = rand() % n;
	tmp.y = rand() % n;
	return tmp;
}

int rand_divider(int a) {
	int b = 0;
	while (a > 0) {
		if (rand() % 2 == 1) {
			b++;
		}
		a--;
		return b;
	}
}

#endif

/*//int x = n; int done = 0; int i, j; //int count = 0;	//int randnum = -1;
	while ((x - 1) != 0) {
		cout << " test ";
		while (!done) {
			cout << " test ";
			for (i = -1; i < 2; i++) {
				for (j = -1; j < 2; j++) {
					if (((tmpx + i) >= 0 && (tmpy + j) >= 0) && !((tmpx + i == tmpx) && (tmpy + j == tmpy))) {
						if (grid[(tmpx + i)][(tmpy + j)].empty == 1) {
							count++;
							if (randnum >= 0) {
								if (count == randnum) {
									free_spaces.push_back({ tmpx + i, tmpy + j});
									done = 1;
								}
							}
						}
					}
				}
			}
			randnum = rand() % count + 1;
			count = 0;
		}

		x--;
	}
	*/