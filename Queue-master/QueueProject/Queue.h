#include "stdlib.h"
#include "stdafx.h"
#include <iostream>
#define SIZE 5

#ifndef Queue_H
#define Queue_H

template <class T> class Queue
{
public:
	//Defoult constructor
	Queue();
	//Destructor
	~Queue();

	//Methods
	void add(T);
	//Add's an item into queue

	void remove();
	//Removes the last item

	bool isEmpty();
	//Check's for empty collection

	T get();
	//Get the current item

	int getCount();
	//Returns the count of items in the collection

	void checkForEmpty();
	//Checks for empty collection and throws exeption in case of true





private:
	//Member variables
	T items[SIZE];
	int firstIndex;
	int lastIndex;
	int count;
};

#endif


