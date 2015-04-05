#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class GOT {
protected:
	string episodeName;
	float USviewersInMillions;
	int deathCount;
	bool didAnyMajorCharacterDie;
public:
	GOT();
	void printEpisodes();
	//virtual void foo() = 0;
};

void GOT::printEpisodes() {
	static int i = 0;
	i++;
	cout << "(" << i << ") " << "Name of Episode: " << episodeName << endl;
	cout << "US Viewers in Millions: " << USviewersInMillions << endl;
	cout << "Notable Deaths: " << deathCount << endl;
	cout << "Did Any Major Characters die: ";
	didAnyMajorCharacterDie == 0 ? cout << "No" << endl : cout << "Yes" << endl;
	cout << "------------------------------" << endl;
	cout << endl;
}

GOT::GOT() {
	ifstream inFile;
	try {
		inFile.open("Information.txt");
		if (inFile.fail()) {
			throw 99;
		}
	} catch (...) {
		cout << "error opening file" << endl;
		terminate();
	}
	string contents;
	static int i = 0;
	static int j = 1;
	i++;
	j++;
	for (i = 1; i < j; i++){
		getline(inFile, contents);
	}
	stringstream GOTstream(contents);
	GOTstream >> episodeName;
	GOTstream >> USviewersInMillions;
	GOTstream >> deathCount;
	GOTstream >> boolalpha >> didAnyMajorCharacterDie;
}

class GOT_INFO : public GOT {
	//Inherit this class publically from the base class.
private:
	//This class will only have ONE new private member variable
	string foo;
public:
	GOT_INFO(string in) {
		//set the string to whatever you like when you create an object of this subclass
		//( non-default constructor)
		static int num = 0;
		num++;
		foo = in;
		cout << foo << num << endl;
	}
	//virtual void foo() {}
};

int main() {
	// create a vector of objects from the subclass NOT the base class
	vector<GOT_INFO> information;
	//create five objects of the subclass
	for (int i = 0; i < 5; i++){
		GOT_INFO info("Load batch ");
		information.push_back(info);
	}
	for (GOT_INFO s : information) {
		s.printEpisodes();
	}
	//check to see how many objects in vector
	cout << "of " << information.size() << endl;
}