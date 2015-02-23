#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

void processStudents(Student* sPtr, int n)
{
	int tempId;
	string tempFN;
	string tempLN;
	float tempGpa;

	for (int i = 0; i < n; i++)
	{
		cout << "\nFor student #" << i+1 << "...\n";
		cout << "Enter student ID: ";
		cin >> tempId;
		cout << "Enter first name: ";
		cin >> tempFN;
		cout << "Enter last name: ";
		cin >> tempLN;
		cout << "Enter student GPA: ";
		cin >> tempGpa;
		/* The following if block checks to see in the input stream is in a fail state.
		   We will cover this in the lecture this week as well. */
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(255, '\n');
			cout << "Hey dummy, re-enter the GPA: ";
			cin >> tempGpa;
		}
		sPtr[i].setAll(tempId, tempFN, tempLN, tempGpa);
	}
	// Now print all the students...
	for (int i = 0; i < n; i++)
	{
		sPtr[i].printStudent();
	}
}

int main(void)
{
	int numStudents;
	Student* stuPtr;

	cout << "How many students are there? ";
	cin >> numStudents;
	if (numStudents > 0)
	{
		stuPtr = new Student[numStudents];
		processStudents(stuPtr, numStudents);
	}
	else
		cout << "Fine. Bye-bye!\n";
	return 0;
}