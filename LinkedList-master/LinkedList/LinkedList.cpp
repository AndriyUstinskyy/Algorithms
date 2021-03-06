﻿#include "stdafx.h"
#include <iostream>

using namespace std;

class LinkedList {

	struct Node {
		int data;
		Node *next;
	};

public:

	LinkedList() {
		head = NULL;
		tail = NULL;
	}

	~LinkedList() {
		Node *next = head;

		while (next) {
			Node *deleteMe = next;
			next = next->next;
			delete deleteMe;
		}
	}

	bool pushFront(int data) {
		Node *newNode = new Node();
		newNode->data = data;
		newNode->next = NULL;

		if (tail == NULL) {
			tail = newNode;
		}

		newNode->next = head;
		head = newNode;

		return true;
	}

	int popFront() {
		if (isEmpty()) 
			return 0;

		Node *newNode = head;
		int ret = newNode->data;

		head = head->next;
		delete newNode;
		return ret;
	}

	bool pushBack(int data) {
		if (tail == NULL) {
			pushFront(data);
		}

		Node * newNode = new Node();
		newNode->data = data;
		newNode->next = NULL;

		tail->next = newNode;
		
		tail = tail->next;

		return true;
	}

	int popBack() {
		if (tail == NULL) {
			return 0; 
		}

		Node * temp = head;
		int ret = tail->data;

		tail = NULL;

		while (temp->next->next) {
			temp = temp->next;
		}

		tail = temp;
		temp->next = NULL;

		return ret;
	}

	bool contains(int key) {
		Node * temp = head;

		while (temp->next) {
			if (temp->next->data == key) {
				return true;
			}

			temp = temp->next;
		}

		return tail->data == key;
	}

	bool insertBefore(int key, int value) {
		if (isEmpty()) {
			return false;
		}

		Node * newNode = new Node();
		newNode->data = value;
		Node * temp = head;

		if (temp->data == key) {
			pushFront(value);
			return true;
		}

		while (temp->next) {
			if (temp->next->data == key) {
				newNode->next = temp->next;
				temp->next = newNode;

				return true;
			}

			temp = temp->next;
		}

		return false;
	}

	int remove(int key) {
		int ret = 0;
		Node * temp = head;

		while (temp) {
			if (temp->data == key) {
				ret = temp->data;
				temp = temp->next;

				return ret;
			}

			temp = temp->next;
		}

		return ret;
	}

	bool isEmpty() {
		return head == NULL;
	}

private:
	Node * head;
	Node * tail;
};

int main()
{
	LinkedList * ll = new LinkedList();

	ll->pushFront(1);
	ll->pushFront(2);
	ll->pushFront(3);
	ll->pushFront(4);
	
	cout << ll->remove(5) << endl;
	
	delete ll;

	system("pause");
	return 0;
}


