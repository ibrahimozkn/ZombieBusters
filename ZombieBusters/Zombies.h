#ifndef ZOMBIES_H
#define ZOMBIES_H

class Zombies : public Entity{
private:
	int Life;
	int dmgPerHit;
	int scorePerItem;
public:
	Zombies(int zombLife, int damage, int score, char repCharacter, int s) : Entity(repCharacter, s){
		Life = zombLife;
		dmgPerHit = damage;
		scorePerItem = score;
	}

	int getLife() {
		return this->Life;
	}

	int getdmgPerHit() {
		return this->dmgPerHit;
	}

	int getscorePetItem() {
		return scorePerItem;
	}
};


#endif