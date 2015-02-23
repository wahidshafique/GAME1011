#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class StuRec
{
private:
	string firstName;
	string lastName;
	int studentId;
	float GPA;

public:
	/*StuRec() // Default constructor. Because of the defaulted parameters in the next constructor, we don't need this one.
	{
		cout << "New student constructed!\n";
		firstName = lastName = "";
		studentId = 0;
		GPA = 0.0;
	}*/
	StuRec(string fName = "Unset", string lName = "Unset", int sId = 100000000, float gpa = 0.0) // Non-default constructor. Note the defaulted parameters.
	{
		cout << "New student constructed with non-default constructor!\n";
		// setStudent(fName, lName, sId, gpa); // This is a common example of calling a full member setter. It would replace the four statements below.
		firstName = fName;
		lastName = lName;
		studentId = sId;
		GPA = gpa;
	}
	float getGPA() // Simply returns the member variable, GPA.
	{
		return GPA;
	}
	int getId() // Simply returns the member variable, studentId.
	{
		return studentId;
	}
	void setGPA(float gpa)
	{
		GPA = gpa;
	}
	/* The following function is a full setter. A common practice is to provide one that can be called in the constructor body
	   but can also be called on its own. I will create an example of this. But if you've read the book you've likely seen it used. */
	void setStudent(string fName, string lName, int sId, float gpa) 
	{
		firstName = fName;
		lastName = lName;
		studentId = sId;
		GPA = gpa;
	}
	void printStudent() // Simply prints a full student record to the common output.
	{
		cout << "Name: " << lastName << ", " << firstName << "  Id: " << studentId << "  GPA: " << GPA << endl;
	}
};

int main()
{
	StuRec student1, student2("John", "Doe"), student3("Jane", "Smith", 100280085, 3.8);
	student1.setGPA(1.7);
	cout << fixed << setprecision(0);
	cout << "Student3's ID is: " << student3.getId() << endl;
	cout << setprecision(2);
	cout << "Student1's GPA is: " << student1.getGPA() << "\n\n";
	student1.printStudent();
	student2.printStudent();
	student3.printStudent();
	return 0;
}