#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string firstName;
public:
	bool operator==(const Student&) const;
	bool operator==(const string&) const;
	Student(string s) { firstName = s; }
	
	friend bool operator==(const string&, Student&);
	friend ostream& operator<<(ostream&, const Student&);
	friend istream& operator>>(istream&, Student&);
};

#endif