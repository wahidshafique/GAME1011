#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

class GOT_S1_S2 {

protected:
	string episodeName;
	float USviewersInMillions;
	int deathCount;
	bool didAnyMajorCharacterDie;


public:
	string getName() { return episodeName; }
	float getViewers() { return USviewersInMillions; }
	int getDeaths() { return deathCount; }
	bool getMajorChars() { return didAnyMajorCharacterDie; }

	string readFile(string file);

	GOT_S1_S2(string GOTinformation);
	~GOT_S1_S2();

	//private:

};

/*GOT_S1_S2::readFile(){
	inFile.open("information.txt");

	if (inFile.fail()){
	cerr << "Error Error" << endl;
	exit(1);
	}
	}*/

/*GOT_S1_S2::readFile(string file){
	ifstream GOTinformation(file);

	string contents;
	while (!file.eof()){
	getline(file, contents);

	}
	}*/

GOT_S1_S2::GOT_S1_S2(string GOTinformation) {

	stringstream GOTstream(GOTinformation);
	GOTstream >> episodeName;
	GOTstream >> USviewersInMillions;
	GOTstream >> deathCount;
	GOTstream >> boolalpha >> didAnyMajorCharacterDie;
	
}

GOT_S1_S2 ::~GOT_S1_S2() {
}


class GOT_EXTRA_INFO : public GOT_S1_S2 {
private:
	string director;

public:
	GOT_EXTRA_INFO(string);
};

int main(){

	GOT_S1_S2 shit("poop_do 12.2 13 false");
	cout << "Name: " << shit.getName() << endl;
	cout << "viewers: " << shit.getViewers() << endl;
	cout << "deaths: " << shit.getDeaths() << endl;
	cout << "maj: " << shit.getMajorChars() << endl;
}