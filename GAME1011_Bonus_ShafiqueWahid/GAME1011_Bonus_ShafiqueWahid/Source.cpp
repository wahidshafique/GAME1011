#include <string>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

template <class A>
class List {
	vector<A> vectorList;
public:
	List(int vectorSize) { vectorList.reserve(vectorSize); }

	int size() const {
		return vectorList.size();
	}

	void push(A item) { vectorList.push_back(item); }

	void pop() { vectorList.pop_back(); }

	void pushFront(A item) { vectorList.insert(vectorList.begin(), item); }

	void popFront() { vectorList.erase(vectorList.begin()); }

	A operator[] (A index) const { return vectorList[index]; }

	friend ostream& operator<< (ostream& out, const List<A> &object) {
		for (int i = 0; i < object.size(); i++) {
			out << object[i] << " ";
		}
		return out;
	}
};

int main() {
	List<char> object1(2);
	object1.push('q');
	object1.push(69);

	List<int> object2(3);
	object2.push(1);
	object2.push(2);
	object2.push(3);

	List<string> object3(4);
	object3.push("one");
	object3.push("two");
	object3.push("three");
	object3.push("four");
	object3.popFront();
	object3.pushFront("Hello!");
	object3.pop();

	cout << "First element in object2 is: " << object2[0] << endl;
	cout << "Object1 items are: " << object1 << endl;
	return 0;
}

