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
bool found_struct_in_vector(int, int, vector<coordinate>);

class Grid {
private:
	int size;
	int tot_zombie_count;
	vector<vector<element>> grid;

	vector<Ammunition> ammo_vector;
	vector<SmallMedicineKit> s_med_vector;
	vector<LargeMedicineKit> l_med_vector;
	vector<SmallZombie> s_zombie_vector;
	vector<MediumZombie> m_zombie_vector;
	vector<LargeZombie> l_zombie_vector;

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
	int move_warrior(int, int, int);

	int check_win_condition();

	vector<coordinate> get_free_neighbors(int, int);

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
	zombie_count = 2 * ((size * size) / 25);
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
	cout << "\nammo count is " << ammo_count << "\n";
	while (ammo_count > 0) {
		tmp = find_coordinate();
		ammo_vector.push_back(Ammunition());
		cout << "\nammo char: " << ammo_vector[ammo_vector.size() - 1].get_Character() << "\n";
		grid[tmp.x][tmp.y].R = &ammo_vector[ammo_vector.size() - 1];
		grid[tmp.x][tmp.y].empty = 0;
		grid[tmp.x][tmp.y].R->add_coordinate(tmp.x, tmp.y);
		ammo_count--;
	}
	//deploy medkits
	//SmallMedicineKit sm;
	while (s_med_count > 0) {
		tmp = find_coordinate();
		s_med_vector.push_back(SmallMedicineKit());
		grid[tmp.x][tmp.y].R = &s_med_vector[s_med_vector.size() - 1];
		grid[tmp.x][tmp.y].empty = 0;
		grid[tmp.x][tmp.y].R->add_coordinate(tmp.x, tmp.y);
		s_med_count--;
	}
	while (l_med_count > 0) {
		
		tmp = find_coordinate();
		l_med_vector.push_back(LargeMedicineKit());
		grid[tmp.x][tmp.y].R = &l_med_vector[l_med_vector.size() - 1];
		grid[tmp.x][tmp.y].empty = 0;
		grid[tmp.x][tmp.y].R->add_coordinate(tmp.x, tmp.y);

		tmp_cvector = get_free_neighbors(tmp.x, tmp.y);
		rand_num = rand() % (tmp_cvector.size());
		grid[tmp_cvector[rand_num].x][tmp_cvector[rand_num].y].R = &l_med_vector[l_med_vector.size() - 1];
		grid[tmp_cvector[rand_num].x][tmp_cvector[rand_num].y].empty = 0;
		grid[tmp_cvector[rand_num].x][tmp_cvector[rand_num].y].R->add_coordinate(tmp_cvector[rand_num].x, tmp_cvector[rand_num].y);

		l_med_count--;
	}
	//deploy zombies
	
	while (s_zombie_count > 0) {
		tmp = find_coordinate();
		s_zombie_vector.push_back(SmallZombie());
		grid[tmp.x][tmp.y].Z = &s_zombie_vector[(s_zombie_vector.size() - 1)];
		grid[tmp.x][tmp.y].empty = 0;
		grid[tmp.x][tmp.y].Z->add_coordinate(tmp.x, tmp.y);
		s_zombie_count--;
	}
	while (m_zombie_count > 0) {
		tmp = find_coordinate();
		m_zombie_vector.push_back(MediumZombie());
		grid[tmp.x][tmp.y].Z = &m_zombie_vector[(m_zombie_vector.size() - 1)];
		grid[tmp.x][tmp.y].empty = 0;
		grid[tmp.x][tmp.y].Z->add_coordinate(tmp.x, tmp.y);

		tmp_cvector = get_free_neighbors(tmp.x, tmp.y);
		rand_num = rand() % (tmp_cvector.size());
		grid[tmp_cvector[rand_num].x][tmp_cvector[rand_num].y].Z = &m_zombie_vector[m_zombie_vector.size() - 1];
		grid[tmp_cvector[rand_num].x][tmp_cvector[rand_num].y].empty = 0;
		grid[tmp_cvector[rand_num].x][tmp_cvector[rand_num].y].Z->add_coordinate(tmp_cvector[rand_num].x, tmp_cvector[rand_num].y);

		m_zombie_count--;
	}
	while (l_zombie_count > 0) {
		tmp = find_coordinate();
		l_zombie_vector.push_back(LargeZombie());
		grid[tmp.x][tmp.y].Z = &l_zombie_vector[(l_zombie_vector.size() - 1)];
		grid[tmp.x][tmp.y].empty = 0;
		grid[tmp.x][tmp.y].Z->add_coordinate(tmp.x, tmp.y);

		tmp_cvector = get_free_neighbors(tmp.x, tmp.y);
		rand_num = rand() % (tmp_cvector.size());
		grid[tmp_cvector[rand_num].x][tmp_cvector[rand_num].y].Z = &l_zombie_vector[l_zombie_vector.size() - 1];
		grid[tmp_cvector[rand_num].x][tmp_cvector[rand_num].y].empty = 0;
		grid[tmp_cvector[rand_num].x][tmp_cvector[rand_num].y].Z->add_coordinate(tmp_cvector[rand_num].x, tmp_cvector[rand_num].y);

		
		tmp_cvector = get_free_neighbors(tmp_cvector[rand_num].x, tmp_cvector[rand_num].y);
		if (tmp_cvector.size() != 0) {
			rand_num = rand() % (tmp_cvector.size());
			grid[tmp_cvector[rand_num].x][tmp_cvector[rand_num].y].Z = &l_zombie_vector[l_zombie_vector.size() - 1];
			grid[tmp_cvector[rand_num].x][tmp_cvector[rand_num].y].empty = 0;
			grid[tmp_cvector[rand_num].x][tmp_cvector[rand_num].y].Z->add_coordinate(tmp_cvector[rand_num].x, tmp_cvector[rand_num].y);
		}

		l_zombie_count--;
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
		
		while (i < tmp.size()) {
			grid[tmp[i].x][tmp[i].y].R = NULL;
			i++;
		}
		return -1;
	}
	if (grid[X][Y].Z != NULL) {
		if (Battle(grid[X][Y].Z, grid[X][Y].W) == 1) {
			cout << "\nYou killed the zombie!!\n";
			tmp = grid[X][Y].Z->get_coordinates();
			i = 0;
			while (i < tmp.size()) {
				grid[tmp[i].x][tmp[i].y].Z = NULL;
				i++;
			}
			//delete[] grid[X][Y].Z;

			tot_zombie_count--;
			return 0;
		}
		else {
			grid[X][Y].W = NULL;
			return 1;
		}
	}
	
}

int Grid::check_win_condition() {
	if (tot_zombie_count <= 0) {
		return 1;
	}
	else {
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