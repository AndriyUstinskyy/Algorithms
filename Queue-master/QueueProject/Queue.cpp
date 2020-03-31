#include "stdafx.h"
#include "Queue.h"



	template <class T>
	bool Queue<T>::isEmpty()
	{
		return count == 0;
	}

	template <class T>
	void Queue<T>::add(T item)
	{
		items[++lastIndex] = item;
		++count;
	}

	template <class T>
	T Queue<T>::get()
	{
		checkForEmpty();
		return items[firstIndex];
	}

	template <class T>
	void Queue<T>::remove()
	{
		checkForEmpty();
		items[firstIndex++] = 0;
		--count;
	}

	template <class T>
	int Queue<T>::getCount()
	{
		return count;
	}

	template <class T>
	void Queue<T>::checkForEmpty()
	{
		if (isEmpty())
		{
			throw nullptr;
		}
	}

	template <class T>
	Queue<T>::Queue()
	{
		lastIndex = -1;
		firstIndex = 0;
		count = 0;
	}

	template <class T>
	Queue<T>::~Queue()
	{
	}

