﻿#include "stdafx.h"
#include <iostream>

using namespace std;

class LinkedList {
	struct Node {
		int val;
		Node *next;
	};


public:
	
	~LinkedList() {
		Node *next = head;

		while (next) {
			Node *deleted = next;
			next = next->next;
			delete deleted;
		}
	}


	void pushFront(int val) {
		Node *newNode = new Node();
		newNode->val = val;
		newNode->next = NULL;

		if (tail == NULL) {
			tail = newNode;
		}

		newNode->next = head;
		head = newNode;

		//return val;
	}


	int popFront() {
		if (isEmpty()) {
			cout << "List is empty." << endl;
		}
		else {
			Node *newNode = head;
			int ret = newNode->val;

			head = head->next;
			delete newNode;
			return ret;
		}
	}


	void pushBack(int data) {
		if (tail == NULL) {
			pushFront(data);
		}

		Node * newNode = new Node();
		newNode->val = data;
		newNode->next = NULL;

		tail->next = newNode;

		tail = tail->next;

		//return true;
	}


	int popBack() {
		if (tail == NULL) {
			return 0;
		}

		Node * temp = head;
		int ret = tail->val;

		tail = NULL;

		while (temp->next->next) {
			temp = temp->next;
		}

		tail = temp;
		temp->next = NULL;

		return ret;
	}
	int remove(int id) {
		if (isEmpty()) {
			cout << "The list is empty" << endl;
		}
		else {
			int ret = 0;
			Node * temp = head;
			Node* prev = NULL;
			while (temp) {
				if (temp->val == id) {
					ret = temp->val;
					if (prev == NULL) {
						head = head->next;
					}
					else {
						prev->next = temp->next;
					}
					delete temp;
					return ret;
				}
				prev = temp;
				temp = temp->next;
			}

			return ret;
		}
	}

	void print() {
		if (isEmpty()) {
			cout << "The list is empty" << endl;
		}
		else {
			Node* check = head;
			cout << "List: " ;
			while (check != nullptr) {
				cout << check->val << " ";
				check = check->next;
			}
		}
		cout << endl;
	}

	bool isEmpty() {
		if (head == nullptr) {
			return true; 
		}
		else {
			return false; 
		}
	}


private:
	Node * head = NULL;
	Node * tail = NULL;
};

int main()
{
	LinkedList * ll = new LinkedList();

	//ll->pushFront(1);
	//ll->pushFront(2);
	//ll->pushFront(3);
	//ll->pushFront(4);
	//ll->pushBack(5);
	//ll->popBack();
	//ll->remove(2);
	//ll->print();

	//ll->remove(2);
	//ll->print();
	//ll->remove(2);
	//ll->print();
	//delete ll;

	int choose;
	int element;
	do
	{
		cout << "1.Add element to list (begin)" << endl;
		cout << "2.Add element to list (end)" << endl;

		cout << "3.Remove element by id" << endl;
		cout << "4.Remove first element " << endl;
		cout << "5.Remove last element " << endl;
		cout << "6.Display list" << endl;
		cout << "6.EXIT" << endl;
	
		cin >> choose;
	
		switch (choose) {
		case 1:
			cout << "Input element : ";
			cin >> element;
			ll->pushFront(element);
			break;
		case 2 :
			cout << "Input element : ";
			cin >> element;
			ll->pushBack(element);
			break;
		case 3:
			cout << "Input index of element : ";
			cin >> element;
			ll->remove(element);
			system("pause");
			break;
		case 4:
			ll->popFront();
			break;
		case 5:
			ll->popBack();
			break;
		case 6:
			ll->print();
			system("pause");
			break;
		}
		system("cls");
	
	} while (choose > 0 && choose <7);
	
	cout << "BYE" << endl;
	system("pause");
	return 0;
}

