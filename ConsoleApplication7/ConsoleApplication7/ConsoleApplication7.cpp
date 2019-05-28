#include <stdlib.h>
#include "pch.h"
#include <cstddef>
#include <iostream>
#include <string>
#include "pch.h"
using namespace std;

struct Node
{
	int x;
	Node *Next;
	Node *Previous;
};

class List
{
	Node *Head;
	int size;
public:
	List() :Head(NULL), size(0) {};
	~List();  
	void Add(int x);
	void Show(int size);
	void Delete(int size);
	int Count();
};

List::~List()
{
	while (size != 0)
	{
		Node *temp = Head->Next;
		delete Head;
		Head = temp;
		size--;
	}
}

int List::Count()
{
	return size;
}

void List::Add(int x)
{
	Node *temp = Head;
	int count = 1;

	while (count <= size)
	{
		if(temp->Next != NULL)
			temp = temp->Next;
		count++;
	}

	Node *newItem = new Node;
	newItem->x = x;
	newItem->Next = NULL;
	if (temp == NULL) {
		newItem->Previous = NULL;
		temp = newItem;
	}
	else {
		newItem->Previous = temp;
		temp->Next = newItem;
	}

	size++;
	count = size;

	while (count > 1) {
		count--;
		if(temp->Previous != NULL)
			temp = temp->Previous;
	}

	Head = temp;
}

void List::Delete(int x)
{
	Node* temp = Head;

	while (true) {
		if (temp == NULL) {
			break;
		}
		if (temp->x == x) {
			if (temp->Previous == NULL && temp->Next == NULL) {
				temp = NULL;
				size--;
				break;
			} else if (temp->Previous == NULL) {
				temp = temp->Next;
				temp->Previous = NULL;
			}
			else if (temp->Next == NULL) {
				temp = temp->Previous;
				temp->Next = NULL;
			}
			else {
				Node* tempItem = temp->Next;
				temp = temp->Previous;
				tempItem->Previous = temp;
				temp->Next = tempItem;
			}
			size--;
		}
		if (temp->Next != NULL)
			temp = temp->Next;
		else
			break;
	}

	while (true) {
		if (temp != NULL && temp->Previous != NULL)
			temp = temp->Previous;
		else
			break;
	}

	Head = temp;
}

void List::Show(int temp)
{
	Node *tempHead = Head;

	while (true)
	{
		if (tempHead == NULL) {
			cout << "Not element for view";
			break;
		}
		cout << tempHead->x << " ";
		tempHead = tempHead->Next;
	}
}

int main()
{
	List lst;
	string str;

	cout << "to enter an item, enter I " << endl;
	cout << "to display enter S " << endl;
	cout << "to remove elment enter D and element " << endl;
	cout << "to exit enter E " << endl;
	cout << "command: ";
		
	while (true) {

		getline(cin, str);
		if (str == "") {
			continue;
		} else if (str == "I") {
			int temp;
			cout << "please enter element: ";
			cin >> temp;
			lst.Add(temp);
			cout << endl;
		} else if (str == "S") {
			cout << endl;
			lst.Show(lst.Count());
			cout << endl;
		} else if (str == "D") {
			int temp;
			cout << "please enter element for delete: ";
			cin >> temp;
			lst.Delete(temp);
			cout << endl;
		} else if (str == "E") {
			break;
		} else {
			cout << "uncnown command" << endl;
		}
		cout << endl;

		cout << "to enter an item, enter I " << endl;
		cout << "to display enter S " << endl;
		cout << "to remove elment enter D and element " << endl;
		cout << "to exit enter E " << endl;
		cout << "command: ";
	}
	system("pause");
	return 0;
}