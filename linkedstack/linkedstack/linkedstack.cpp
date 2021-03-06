#include "stdafx.h"
#include <iostream>

using namespace std;

class LinkStack {
	struct node {
		int val;
		node* next = NULL;
	};
private:
	node * ptr = NULL;
public:
	void  push(int d) {
		node* n = new node();
		n->next = ptr;
		n->val = d;
		ptr = n;
	}
	int  top(){
		return ptr->val; 
	}

	int pop() {
		node* tmp = ptr;
		ptr = ptr->next;
		int DeletedElemnt = tmp->val;
		delete tmp;
		tmp = NULL;
		return DeletedElemnt;
	}
	bool empty() { 
		return (!ptr); 
	}
	void GetElement(int id) {
		for (int i = 1; i < id; i++) {
			pop();
		}
		cout << top() << endl;
		pop();
	}
	void clear() {
		node* tmp;
		while (ptr != NULL) {
			tmp = ptr;
			ptr = ptr->next;
			delete tmp;
			tmp = NULL;
		}
	}
	void Print() {
		while (!empty()) {
			cout << top() << " ";
			pop();
		}
		cout << endl;
	}
};

int  main() {
	LinkStack lst;

	int choose;
	int element;
	do
	{
		cout << "1.Vvesty Element v stack" << endl;
		cout << "2.Vyvesty element zi stack" << endl;
		cout << "3.Vyvesty stack" << endl;
		cout << "4.EXIT" << endl;

		cin >> choose;

		switch (choose) {
		case 1:
			cout << "Vvedit element : ";
			cin >> element;
			lst.push(element);
			break;
		case 2:
			cout << "Vvedit index elementa : ";
			cin >> element;
			lst.GetElement(element);
			system("pause");
			break;
		case 3:
			lst.Print();
			system("pause");
			break;
		}
		system("cls");

	} while (choose > 0 && choose <4);

	cout << "BYE" << endl;

	system("pause");
	return 0;
}
