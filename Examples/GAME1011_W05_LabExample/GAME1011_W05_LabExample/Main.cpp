#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

int main()
{
	Student one("Mark"), two("Julia");
	if ( one == two )
		cout << "Yep!\n";
	else
		cout << "Nope!\n";
	if ( one == "Mark" )
		cout << "Yep!\n";
	else
		cout << "Nope!\n";
	if ( "Mark" == one )
		cout << "Yep!\n";
	else
		cout << "Nope!\n";
	cout << one << two << endl;
	return 0;
}


