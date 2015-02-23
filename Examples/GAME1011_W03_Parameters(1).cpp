#include <iostream>
using namespace std;

/* Function prototypes. As long as these are here, you can define your functions AFTER main.
   Note that I DO NOT have to put the variable NAMES in, only their TYPES, like int. */
void passByValue(int, int, int);
void passByPointer(int*, int*, int*);
void passByReference(int&, int&, int&);

void arrayToArray(int [2]);
void arrayToPointer(int*);

int main(void)
{
	int x = 0, y = 0, z = 0;
	int foo[2] = {0,0};

	cout << "Passing By Value...\nValues before function: " << x << "," << y << "," << z << endl;
	passByValue(x,y,z);
	cout << "Values after function: " << x << "," << y << "," << z << endl;

	cout << "\nPassing By Pointer...\nValues before function: " << x << "," << y << "," << z << endl;
	passByPointer(&x,&y,&z); // For passing by pointer, we pass the ADDRESS of the variable.
	cout << "Values after function: " << x << "," << y << "," << z << endl;

	cout << "\nPassing By Reference...\nValues before function: " << x << "," << y << "," << z << endl;
	passByReference(x,y,z); // Note that for references, we don't need to pass in the addresses.
	cout << "Values after function: " << x << "," << y << "," << z << endl;

	cout << "\nPassing Array to Array...\nValues before function: " << foo[0] << "," << foo[1] << endl;
	arrayToArray(foo);
	cout << "Values after function: " << foo[0] << "," << foo[1] << endl;

	cout << "\nPassing Array to Pointer...\nValues before function: " << foo[0] << "," << foo[1] << endl;
	arrayToPointer(foo);
	cout << "Values after function: " << foo[0] << "," << foo[1] << endl;

	cout << "\nWhat did we learn?\n";
	cout << "- Passing by value didn't change original variables.\n";
	cout << "- But passing by pointer and reference does change them!\n";
	cout << "- Why? Pointers and references hold the ADDRESSES of the original values.\n\n";
	cout << "- Array names are aliases for the address of their FIRST element!\n";
	cout << "- So in those functions, the array elements DO change too!\n";
	return 0;
}

/* The following function contains 3 normal parameters that will become
   copies of those passed into the function. The original values will 
   NOT change, i.e., x, y and z. */
void passByValue(int a , int b, int c)
{
	a = 9;
	b = 9;
	c = 9;
}

/* The following function contains 3 normal pointer parameters that will
   hold the addresses of x, y and z. Because we are indirectly accessing
   x, y and z through these parameters, the original values WILL change.
   I will explain this in the Week 3 lecture on Pointers & References. */
void passByPointer(int* a, int* b, int* c) // Pointer parameters.
{
	*a = 3; // The asterisk in these three lines is the dereference operator
	*b = 6; // not to be confused with the asterisk in the declaration lines 
	*c = 9; // of pointer variables, including parameters like this function.
}

/* The following function contains 3 reference parameters that will
   hold the addresses of x, y and z. Because we are indirectly accessing
   x, y and z through these parameters, the original values WILL change.
   I will explain this in the Week 3 lecture on Pointers & References. */
void passByReference(int& a, int& b, int& c)
{
	a = 7; // Note that we don't need to provide a dereference operator
	b = 7; // with reference variables as they are automatically
	c = 7; // dereferenced. I call references stealth pointers.
}

void arrayToArray(int bar[2])
{
	bar[0] = 6;
	bar[1] = 9;
}

void arrayToPointer(int* bar)
{
	bar[0] = 4;
	bar[1] = 2;
	/* Could also do the following which does the EXACT same thing:

	   *bar = 4;
	   bar++;
	   *bar = 2;

	   We dereference the pointer and set the value of the first element,
	   then we increment the pointer to point to the NEXT address in memory
	   or the second array element, then dereference to set its value. This
	   is considered bad form, but we call it POINTER ARITHMETIC.

	   Another thing to note of important is that we CANNOT use pointer 
	   arithmetic with references because once a reference holds an address
	   to another variable, we CANNOT change that address being held by a 
	   reference. With pointers we can change the address being 'pointed' to.
	   I'll explain this with diagrams too in the Week 3 lecture.
	*/
}