#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Player.h"
#include "Enemies.h"

using namespace std;

int main(void)
{
	srand((unsigned)time(NULL));
	Novice n("Ashur");
	cout << n.getKC() << endl;
	return 0;
}