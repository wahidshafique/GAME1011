#include <string>
using namespace std;

bool operator==(const string& s, Student& other)
{
	cout << "Third version...\n";
	return s == other.firstName;
}