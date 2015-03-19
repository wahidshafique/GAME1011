#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <stdlib.h>
#include <string>

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

	GOT_S1_S2(string GOTinformation);
};

GOT_S1_S2::GOT_S1_S2(string GOTinformation) {

	stringstream GOTstream(GOTinformation);
	GOTstream >> episodeName;
	GOTstream >> USviewersInMillions;
	GOTstream >> deathCount;
	GOTstream >> boolalpha >> didAnyMajorCharacterDie;
}

class GOT_PRINT {

private:
	string foo;

public:
	GOT_PRINT(string file);
	//private:
	vector<GOT_S1_S2> information;//priv
};

GOT_PRINT::GOT_PRINT(string file) {

	ifstream inFile;
	inFile.open(file);

	if (inFile.fail()){
		cerr << "Error Error" << endl;
		exit(1);
	}

	string contents;
	while (!inFile.eof()) {
		getline(inFile, contents);
		GOT_S1_S2 s(contents);
		information.push_back(s);
	}
	inFile.close();
}

void printEpisodes(GOT_S1_S2 info) {

	static int i = 0;
	i++;

	cout << "(" << i << ") " << "Name of Episode: " << info.getName() << endl;
	cout << "US Viewers in Millions: " << info.getViewers() << endl;
	cout << "Notable Deaths: " << info.getDeaths() << endl;
	cout << "Did Any Major Characters die: ";
	info.getMajorChars() == 0 ? cout << "No" << endl : cout << "Yes" << endl;
	cout << "------------------------------" << endl;
	cout << endl;
}

int main() {
	GOT_PRINT info("Information.txt");
	for (GOT_S1_S2 s : info.information){
		printEpisodes(s);
	}
}