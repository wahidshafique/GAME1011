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

	void printEpisodes(GOT_S1_S2 info);
	void open(string file);

	GOT_S1_S2();
	GOT_S1_S2(string GOTinformation);

	vector<GOT_S1_S2> information;
};

GOT_S1_S2::GOT_S1_S2(string GOTinformation) {
	stringstream GOTstream(GOTinformation);
	GOTstream >> episodeName;
	GOTstream >> USviewersInMillions;
	GOTstream >> deathCount;
	GOTstream >> boolalpha >> didAnyMajorCharacterDie;
}

GOT_S1_S2::GOT_S1_S2() {
	ifstream inFile;
	inFile.open("Information.txt");

	if (inFile.fail()){
		cerr << "Error Error" << endl;
		exit(1);
	}

	string contents;

	static int i = 0;
	static int j = 4;
	for (i; i < j; i++) {
		getline(inFile, contents);
		GOT_S1_S2 s(contents);
		information.push_back(s);
	}
	j += 4;
	inFile.close();
}

void GOT_S1_S2::printEpisodes(GOT_S1_S2 info) {
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

class GOT_INFO :public GOT_S1_S2 {
private:
	string foo;

public:
	GOT_INFO(string in) : GOT_S1_S2() {
		foo = in;
		cout << foo << endl << endl;

		for (GOT_S1_S2 s : information){
			printEpisodes(s);
		}
	}
};

int main() {

	GOT_INFO info1("Load first batch");
	GOT_INFO info2("Load second batch");
	GOT_INFO info3("Load third batch");
	GOT_INFO info4("Load forth batch");
	GOT_INFO info5("Load fifth batch");
	cout << info1.information.size();
}