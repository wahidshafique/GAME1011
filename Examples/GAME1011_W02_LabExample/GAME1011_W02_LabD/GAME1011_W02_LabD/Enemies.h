#include <iostream>
#include <string>
#include "Weapon.h"
using namespace std;

class Enemy
{
protected: // Member variables that can be inherited but are considered private.
	int health, maxHealth, attack, defense;
	string name;
	Weapon wArray[2]; // A static array of two weapons. Example of composition.
public:
	Enemy()
	{
		cout << "Enemy constructed!\n";
	}
};

class Novice: public Enemy
{
public:
	Novice(string n = "Novice")
	{
		cout << "Constructed '" << n << "' Novice!\n";
		setAll(n, 50, 50, 2, 2); // Calling full setter in constructor.
		wArray[0].setAll("Shortsword", 2, 75);
		wArray[1].setAll("Knife", 1, 50);
	}
	void printNovice()
	{
		cout << name << ": " << health << "/" << maxHealth << endl;
	}
	void setAll(string n, int h, int mH, int a, int d)
	{
		name = n;
		health = h;
		maxHealth = mH;
		attack = a;
		defense = d;
	}
};