// QueueProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Queue.cpp"

int main()
{
	Queue<int> q = Queue<int>();
	q.add(1);
	std::cout << q.get() << std::endl;
	q.remove();
	q.add(2);
	std::cout << q.get() << std::endl;

	system("pause");
    return 0;
}

