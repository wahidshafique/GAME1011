#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class GOT_S1_S2 {
protected:
	string episodeName;
	float USviewersInMillions;
	int deathCount;
	bool didAnyMajorCharacterDie;

public:
	void printEpisodes(GOT_S1_S2 info);
	//virtual void foo() = 0;
	GOT_S1_S2();
	GOT_S1_S2(string GOTinformation);
	vector<GOT_S1_S2> information;
};

GOT_S1_S2::GOT_S1_S2() {
	ifstream inFile;
	try {
		inFile.open("Information.txt");
		if (inFile.fail()) {
			throw 99;
		}
	} catch (...) {
		cout << "error opening file" << endl; 
		//exit(1);
		terminate();
	}

	string contents;

	for (int i = 0; i < 5; i++) {
		getline(inFile, contents);
		GOT_S1_S2 s(contents);
		information.push_back(s);
	}
	inFile.close();
}

GOT_S1_S2::GOT_S1_S2(string GOTinformation) {
	stringstream GOTstream(GOTinformation);
	GOTstream >> episodeName;
	GOTstream >> USviewersInMillions;
	GOTstream >> deathCount;
	GOTstream >> boolalpha >> didAnyMajorCharacterDie;
}

void GOT_S1_S2::printEpisodes(GOT_S1_S2 info) {
	static int i = 0;
	i++;

	cout << "(" << i << ") " << "Name of Episode: " << info.episodeName << endl;
	cout << "US Viewers in Millions: " << info.USviewersInMillions << endl;
	cout << "Notable Deaths: " << info.deathCount<< endl;
	cout << "Did Any Major Characters die: ";
	info.didAnyMajorCharacterDie == 0 ? cout << "No" << endl : cout << "Yes" << endl;
	cout << "------------------------------" << endl;
	cout << endl;
}

class GOT_INFO :public GOT_S1_S2 {
private:
	string foo;

public:
	GOT_INFO(string in) {
		foo = in; 
		cout << foo; 
	}
	void printEpisodes();
	/*GOT_INFO(string in) : GOT_S1_S2() {
		foo = in;
		cout << foo << endl << endl;

		for (GOT_S1_S2 s : information){
			printEpisodes(s);
		}
	}*/
};

int main() {
	vector<GOT_S1_S2> information;

	GOT_INFO info1("Load first batch");
	//GOT_INFO info2("Load second batch");
	//GOT_INFO info3("Load third batch");
	//GOT_INFO info4("Load forth batch");
	cout << info1.information.size();
}