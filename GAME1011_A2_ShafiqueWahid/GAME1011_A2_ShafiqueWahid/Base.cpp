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
	virtual void stop() = 0;
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
private:
	string foo;
public:
	GOT_INFO(string in) {
		static int num = 0;
		num++;
		foo = in;
		cout << foo << num << endl;
	}
	void redundantPrintEpisodes(){ printEpisodes(); }
	virtual void stop(){}
};

int main() {
	vector<GOT_INFO> information;

	for (int i = 0; i < 5; i++){
		GOT_INFO info("Load batch ");
		information.push_back(info);
	}

	for (GOT_INFO s : information) {
		s.redundantPrintEpisodes();
	}
}