#ifndef GRID_H
#define GRID_H

#include "Entity.h"
#include <time.h>

struct element{
	int empty;
	Entity* E;
	char character;
};


class Grid {
private:
	int size;
	vector<vector<element>> grid;
public:
	Grid(int s) {
		size = s;
		int i, j;
		for (i = 0; i < size; i++) {
			grid.push_back(vector<element>());
			for (j = 0; j < size; j++) {
				grid[i].push_back(element());
				grid[i][j].empty = 1;
				grid[i][j].E = NULL;
				grid[i][j].character = '-';
			}
		}
	}

	vector<coordinate> find_free_space(int);
	void deploy_(char, char);
	

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

	int zombie_count = 2 * ((size * size) / 25);

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

		Ammunition* a;
		ammo_vector.push_back(a);
		grid[tmpx][tmpy].E = ammo_vector[ammo_index];
		grid[tmpx][tmpy].character = 'A';
		grid[tmpx][tmpy].empty = 0;
		ammo_index++;

		ammo_count--;
	}
	
	while (med_count > 0) {
		if (rand() % 2 == 1) {
			large_medcount++;
		}
		else {
			small_medcount++;
		}
		med_count--;
	}

	while (small_medcount > 0) {

		tmpvector = find_free_space(1);
		tmpx = tmpvector[0].x;
		tmpy = tmpvector[0].y;

		SmallMedicineKit* s;
		small_med_vector.push_back(s);
		grid[tmpx][tmpy].E = small_med_vector[small_med_index];
		grid[tmpx][tmpy].character = 'S';
		grid[tmpx][tmpy].empty = 0;
		small_med_index++;

		small_medcount--;
	}
	cout << "\nlarge med count: " << large_medcount << "\n";
	while (large_medcount > 0) {
		tmpvector = find_free_space(2);
		
		

		tmpx = tmpvector[0].x;
		tmpy = tmpvector[0].y;

		cout << "\n\n" << tmpx << "," << tmpy << "\n\n";

		LargeMedicineKit* s;
		large_med_vector.push_back(s);
		grid[tmpx][tmpy].E = large_med_vector[large_med_index];
		grid[tmpx][tmpy].character = 'L';
		grid[tmpx][tmpy].empty = 0;

		tmpx = tmpvector[1].x;
		tmpy = tmpvector[1].y;

		cout << "\n\n" << tmpx << "," << tmpy << "\n\n";

		grid[tmpx][tmpy].E = large_med_vector[large_med_index];
		grid[tmpx][tmpy].character = 'L';
		grid[tmpx][tmpy].empty = 0;

		large_med_index++

		large_medcount--;
	}

}

vector<coordinate> Grid::find_free_space(int n) {
	int x = n; int done = 0; int i, j; int count = 0;
	vector<coordinate> free_spaces;
	int tmpx = rand() % size;
	int tmpy = rand() % size;
	int randnum = -1;

	while (grid[tmpx][tmpy].empty == 0) {
		int tmpx = rand() % size;
		int tmpy = rand() % size;
	}
	free_spaces.push_back({ tmpx,tmpy });

	while ((x - 1) != 0) {
		
		while (!done) {
			for (i = -1; i < 2; i++) {
				for (j = -1; j < 2; j++) {
					if (((tmpx + i) >= 0 && (tmpy + j) >= 0) && !((tmpx + i == tmpx) && (tmpy + j == tmpy))) {
						if (grid[tmpx + i][tmpy + j].empty == 1) {
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

	return free_spaces;
}

#endif