#ifndef CHARACTER_H
#define CHARACTER_H

#include "Weapon.h"

class Character
{
protected:
	int health, prowess, attack, defense, level;
	int bonusPrw[2], bonusAtk[2], bonusDef[2], bonusDmg[2];
	string type, name;
	Weapon* wArray;
public:
	Character()
	{
		bonusPrw[0] = bonusPrw[1] = 0;
		bonusAtk[0] = bonusAtk[1] = 0;
		bonusDef[0] = bonusDef[1] = 0;
		bonusDmg[0] = bonusDmg[1] = 0;
		wArray = new Weapon[2];
	}
};

#endif