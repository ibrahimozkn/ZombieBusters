#ifndef GRID_H
#define GRID_H

#include "Entity.h"


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

	void initialize_grid(char, coordinate *, char, coordinate *);
	
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

void Grid::initialize_grid(char C1, coordinate* P1, char C2, coordinate* P2) {
	if (C1 == 'D') {
		Derick* derick1 = new Derick();
		grid[P1->x][P1->y].E = derick1;
		grid[P1->x][P1->y].character = 'D';
		grid[P1->x][P1->y].empty = 0;
	}
	else if (C1 == 'C') {
		Chichonne* chichonne1 = new Chichonne();
		grid[P1->x][P1->y].E = chichonne1;
		grid[P1->x][P1->y].character = 'C';
		grid[P1->x][P1->y].empty = 0;
	}
	if (C2 == 'D') {
		Derick* derick2 = new Derick();
		grid[P2->x][P2->y].E = derick2;
		grid[P2->x][P2->y].character = 'D';
		grid[P2->x][P2->y].empty = 0;
	}
	else if (C2 == 'C') {
		Chichonne* chichonne2 = new Chichonne();
		grid[P2->x][P2->y].E = chichonne2;
		grid[P2->x][P2->y].character = 'C';
		grid[P2->x][P2->y].empty = 0;
	}


}

#endif