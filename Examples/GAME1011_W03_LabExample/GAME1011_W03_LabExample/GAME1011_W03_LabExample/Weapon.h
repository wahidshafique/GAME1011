#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>
using namespace std;

class Weapon
{
private:
	string name;
	int damage;
	int durability;
public:
	Weapon(string n = "Weapon", int dmg = 0, int dur = 100)
	{
		setAll(n, dmg, dur);
	}
	string getName()
	{
		return name;
	}
	int getDamage()
	{
		return damage;
	}
	int getDurability()
	{
		return durability;
	}
	void setName(string n)
	{
		name = n;
	}
	void setDamage(int dmg)
	{
		damage = dmg;
	}
	void setDurability(int dur)
	{
		durability = dur;
	}
	void setAll(string n, int dmg, int dur)
	{
		name = n;
		damage = dmg;
		durability = dur;
	}
};

#endif