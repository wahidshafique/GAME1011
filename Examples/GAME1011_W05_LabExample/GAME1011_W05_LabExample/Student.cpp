#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

// Note the use of the scope resolution operator ::
bool Student::operator==(const Student& other) const
{
	cout << "Ran first version...\n";
	return this->firstName == other.firstName;
}

bool Student::operator==(const string& s) const
{
	cout << "Ran second version...\n";
	return this->firstName == s;
}

// No scope operator as it is a global function
bool operator==(const string& s, Student& stu)
{
	cout << "Ran third version...\n";
	return s == stu.firstName;
}

ostream& operator<<(ostream& o, const Student& stu)
{
    o << "Name: " << stu.firstName << endl;
    return o;
}

istream& operator>>(istream& i, Student& stu)
{
    i >> stu.firstName;
    return i;
}