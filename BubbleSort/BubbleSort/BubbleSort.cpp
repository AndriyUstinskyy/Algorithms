
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
	int bublemas[size];
	int val;

	cout << "Vvedit masyv dlya sortuvannya2" << endl;
	for (int i = 0; i < size; i++) {
		cin >> bublemas[i];
	}
	system("cls");
	cout << "Projody sortirovky " << endl;
	
	int x = 0;
	for (int i = size - 1; i >= x; i)
	{
		for (int j = size - 1; j >= x; j--) {
			if (bublemas[j] < bublemas[j - 1]) {
				val= bublemas[j];
				bublemas[j] = bublemas[j - 1];
				bublemas[j - 1] = val;
				PrintF(bublemas);
			}
		}
		x++;
	}
	system("pause");
  
	return 0;
}

