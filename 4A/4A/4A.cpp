#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int x, product = 1, k = 0;
	int a[10];
	srand(time(NULL));
	
	for (int i = 0; i < 10; i++) {
		x = 6 - (rand() % 11);	// заполнение рандомными числами  
		a[i] = x;
		cout << a[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < 10; i++) {
		if (a[i] < 0 && a[i] % 2 != 0) {
			product *= a[i];
			k++;
		}
	}
	if (k == 0) {
		cout << "В массиве нет отрицательных нечётных элементов." << endl;
	}
	else {
		cout << "Произведение отрицательных нечётных: " << product << endl << "Кол-во отрицательных нечётных: " << k << endl;
	}

    return 0;
}

