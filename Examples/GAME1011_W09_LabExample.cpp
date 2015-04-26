#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T>
class ListClass
{
private:
	string name;		// The name of the list.
	int maxSize;		// This will be used to determine if fixed vector.
	vector<T> vList;	// Our actual vector container.
public:
	ListClass(string n, bool fixed=false, int sz=1)	// Our list should AT LEAST have one element inside it.
	{
		name = n;
		vList.reserve(sz);
		if (fixed)
		{
			maxSize = sz;
		}
		else
		{
			maxSize = -1; // Set to -1 to say list has no fixed size
		}
	}
	void pop()
	{
		vList.pop_back();
	}
	void push(T item)
	{
		if (maxSize != -1 && (int)vList.size() == maxSize)
		{
			cout << "Cannot add to list.\n";
		}
		else
		{
			vList.push_back(item);
			cout << "Added item " << item << " to " << name << ".\n";
		}
	}
	void printList()
	{
		for (int i = 0; i < (int)vList.size(); i++)
		{
			cout << vList[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	ListClass<string> closet("My closet"); // Creating an unlimited container of strings.
	closet.push("Shirt");
	closet.push("Hat");

	ListClass<int> primes("List of prime numbers", true, 3); // Creating a fixed list of 3 ints.
	primes.push(1);
	primes.push(3);
	primes.push(5);
	primes.push(7);		// Uh oh, list full. Can't push.
	primes.pop();		// Deleting last element of container.
	primes.push(23);	
	primes.printList();	// Printing the container.
	return 0;
}