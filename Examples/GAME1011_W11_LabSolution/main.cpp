#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class cupcake
{
private:
	string flavor;
	int numSprinkles;
public:
	cupcake(ifstream& in)
	{
		in >> flavor >> numSprinkles;
	}
	void print()
	{
		cout << flavor << ' ' << numSprinkles << endl;
	}
};


int main()
{
	ifstream inFile;
	inFile.open("data.txt");
	cupcake choc(inFile);
	cupcake van(inFile);
	cupcake blue(inFile);
	choc.print();
	van.print();
	blue.print();
	return 0;
}