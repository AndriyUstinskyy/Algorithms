﻿
#include "stdafx.h"
#include <iostream>

using namespace std;

void PrintF(int *mas ) {
	for (int i = sizeof(mas) ; i >=0 ; i--) {
		cout << mas[i] << " ";

	}
	cout << endl;
}
int main()
{
	const int size = 5;
	int buble_mas[size];
	int val;

	cout << "Input array for sort" << endl;
	for (int i = 0; i < size; i++) {
		cin >> buble_mas[i];
	}
	system("cls");
	cout << "sort iteration " << endl;
	
	int x = 0;
	for (int i = size - 1; i >= x; i)
	{
		for (int j = size - 1; j >= x; j--) {
			if (buble_mas[j] < buble_mas[j - 1]) {
				val= buble_mas[j];
				buble_mas[j] = buble_mas[j - 1];
				buble_mas[j - 1] = val;
				PrintF(buble_mas);
			}
		}
		x++;
	}
	system("pause");
  
	return 0;
}

