#include <iostream>
#include <string>
using namespace std;

template <class T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node()
	{
		next = NULL;
	}
};

template <class T>
class List
{
private:
	Node<T>* head; // Node at the start of the list.
	Node<T>* tail; // Node at the end.
public:
	List()
	{
		head = tail = NULL;
	}
	bool isEmpty()
	{
		return (head == NULL);
	}
	void pushBack(const T& dIn)
	{
		Node<T>* newNode = new Node<T>();
		newNode->data = dIn;
		newNode->next = NULL; // This optional line is in constructor...
		if (isEmpty() == true)
		{
			head = newNode;
		}
		else 
		{
			tail->next = newNode;
		}
		tail = newNode;
	}
	void pushFront(const T& dIn)
	{
		Node<T>* newNode = new Node<T>();
		newNode->data = dIn;
		newNode->next = head; // NULL if empty.
		head = newNode;
		if (isEmpty() == true)
		{
			tail = head;
		}
	}
	void popBack()
	{
		if (isEmpty() == false) // If the list is not empty...
		{
			if (head == tail) // If there's only one node...
			{
				delete head; // Unallocate the memory for the node.
				head = tail = NULL;
			}
			else // More than one node...
			{
				Node<T>* temp = head; // Create a temporary node to iterate the list...
				while (temp->next != tail) // Finds the node BEFORE the tail, ensures it is pointed to by temp.
				{
					temp = temp->next; // Iterate to the next node.
				}
				delete tail; // Unallocate the memory for the old tail.
				temp->next = NULL;
				tail = temp;
			}
		}

	}
	void popFront()
	{
		if (isEmpty() == false) // If the list is not empty...
		{
			if (head == tail) // If there's only one node...
			{
				delete head; // Unallocate the memory for the node.
				head = tail = NULL;
			}
			else 
			{
				Node<T>* temp = head; // Point to the old head with a new pointer.
				head = head->next; // Move the head pointer to the next node.
				delete temp; // Unallocate the memory for the old head.
			}
		}
	}
	void print()
	{
		if (isEmpty() == false )
		{
			Node<T>* temp = head; // Create a temporary node to iterate the list...
			do 
			{
				cout << temp->data << ' ';
				temp = temp->next; // Iterate to the next node.
			} while (temp != NULL);
			cout << endl;
		}
		else 
		{
			cout << "Cannot print empty list!" << endl;
		}
	}
};

int main()
{
	List<int> iList;
	iList.pushBack(42);
	iList.pushBack(23);
	iList.pushBack(69);
	iList.print();
	iList.popBack();
	iList.print();
	iList.pushFront(117);
	iList.print();
	iList.popBack();
	iList.popFront();
	iList.popFront();
	iList.print();
	return 0;
}