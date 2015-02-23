#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student
{
private:
	int studentId;		// 4b
	string firstName;	// 32b
	string lastName;	// 32b
	float GPA;			// 4b
public:
	void setAll(int i, string &f, string &l, float g)
	{
		studentId = i;
		firstName = f;
		lastName = l;
		GPA = g;
	}
	void printStudent()
	{
		cout << "\nID: " << studentId << " Name: " << lastName << ", " << firstName << " GPA: ";
		cout << setprecision(2) << fixed << GPA << endl;
	}
};

#endif