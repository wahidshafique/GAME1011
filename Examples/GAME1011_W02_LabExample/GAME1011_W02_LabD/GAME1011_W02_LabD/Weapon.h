#ifndef WEAPON_H
#define WEAPON_H

#include <string>
using namespace std;

class Weapon
{
private:
	int damage, durability;
	string name;
public:
	Weapon(string n = "Weapon", int dmg = 0, int dur = 100)
	{
		setAll(n, dmg, dur);
	}
	void setAll(string n, int dmg, int dur)
	{
		name = n;
		damage = dmg;
		durability = dur;
	}
};

#endif