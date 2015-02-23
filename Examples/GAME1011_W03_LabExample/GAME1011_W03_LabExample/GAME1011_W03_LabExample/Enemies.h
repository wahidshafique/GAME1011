#ifndef ENEMIES_H
#define ENEMIES_H

#include <iostream>
#include <string>
#include "Character.h"
using namespace std;

class Enemy: public Character
{
protected:
	int killChance;
public:
	Enemy() 
	{
		// Empty...
	}
	int getKC()
	{
		return killChance;
	}
};

class Novice: public Enemy
{
private:
	int maxHealth;
public:
	Novice(string n = "Novice", string t = "Novice", int h = 40, int a = 2, int d = 2, int l = 1, int kc = 25)
	{
		maxHealth = 40 + 10*l;
		name = n;
		type = t;
		health = h + 10*l;
		attack = a;
		defense = d;
		level = l;
		killChance = kc + rand() % 26;
	}
	bool dodge()
	{

	}
	int getMaxHealth()
	{
		return maxHealth;
	}
};

class Veteran: public Novice
{
private:
	int maxHealth;
public:
	Veteran(string n = "Veteran", string t = "Veteran", int h = 100, int a = 2, int d = 2, int l = 3)
			:Novice(n, t, h, a, d, l, 50)
	{
		maxHealth = 100;
	}
	int getMaxHealth()
	{
		return maxHealth;
	}
};

class Champion: public Novice
{
private:
	int maxHealth;
public:
	Champion(string n = "Champion", string t = "Champion", int h = 200, int a = 2, int d = 2, int l = 5)
			:Novice(n, t, h, a, d, l, 75)
	{
		maxHealth = 200;
	}
	int getMaxHealth()
	{
		return maxHealth;
	}
};

#endif
