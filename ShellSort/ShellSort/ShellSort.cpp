// ShellSort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
void PrintF(int *mas , int size) {
	for (int i = 0; i <= size; i++) {
		cout << mas[i] << " ";

	}
	cout << endl;
}

//void ShellSort(int n, int mass[])
//{
//	int i, j, step;
//	int tmp;
//	for (step = n / 2; step > 0; step /= 2)
//		for (i = step; i < n; i++)
//		{
//			tmp = mass[i];
//			for (j = i; j >= step; j -= step)
//			{
//				if (tmp < mass[j - step])
//					mass[j] = mass[j - step];
//				else
//					break;
//			}
//			mass[j] = tmp;
//		}
//}
int main()
{
	const int size = 10;
	int bublemas[size];
	int val;

	cout << "Vvedit masyv dlya sortuvannya2" << endl;
	for (int i = 0; i < size; i++) {
		cin >> bublemas[i];
	}
	system("cls");
	cout << "Projody sortirovky " << endl;
	//int a;
	//for (int k = size / 2; k > 0; k /= 2) {
	//	for (int i = k; i < size; i++)
	//	{
	//		val = bublemas[i];
	//		for (int j = i; j >= k; j -= k)
	//		{
	//			a = j;
	//			if (val < bublemas[j - k])
	//				bublemas[j] = bublemas[j - k];
	//			else
	//				break;
	//
	//
	//		}
	//		bublemas[a] = val;
	//	}
	//	PrintF(bublemas);
	//
	//}
	int step = size / 2;
	while (step > 0)//пока шаг не 0
	{
		for (int i = 0; i < (size - step); i++)
		{
			int j = i;
			//будем идти начиная с i-го элемента
			while (j >= 0 && bublemas[j] > bublemas[j + step])
				//пока не пришли к началу массива
				//и пока рассматриваемый элемент больше
				//чем элемент находящийся на расстоянии шага
			{
				//меняем их местами
				int temp = bublemas[j];
				bublemas[j] = bublemas[j + step];
				bublemas[j + step] = temp;
				j--;
				PrintF(bublemas , size);
			}
		}
		step = step / 2;//уменьшаем шаг
	}

	system("pause");
    return 0;
}

