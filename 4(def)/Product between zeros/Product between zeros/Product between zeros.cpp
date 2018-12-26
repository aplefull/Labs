// Произведение чётных элементов массива, между двумя первыми нулями.
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int size, firstZero = -1, secondZero = -1, product = 1, k = 0, i;

	cout << "Type in size of an array: ";
	cin >> size;

	int *a = new int[size];

	//ввод
	cout << "Type in all elements: ";
	for (i = 0; i < size; i++){
		cin >> a[i];
	}

	//первый 0
	for (i = 0; i < size; i++) {
		if (a[i] == 0) {
			firstZero = i;
			break;
		}
	}

	//проверка на присутствие первого 0
	if (firstZero == -1) {
		cout << "There are less than 2 zeros in an array" << endl;
		delete[] a;
		return 1;
	}

	//второй 0
	for (i = firstZero + 1; i < size; i++) {
		if (a[i] == 0) {
			secondZero = i;
			break;
		}
	}

	//проверка на присутствие второго 0
	if (secondZero == -1) {
		cout << "There are less than 2 zeros in an array" << endl;
		delete[] a;
		return 1;
	}

	//если первый 0 на чётной позиции
	if ((firstZero + 1) % 2 == 0) {

		if (secondZero - firstZero > 2)
		{
			for (i = firstZero + 2; i < secondZero; i += 2) {
				product *= a[i];
			}
		}

		else
		{
			cout << "There are not enought elements between zeros" << endl;
			delete[] a;
			return 1;
		}

	}

	//если первый 0 на нечётной позиции
	else{

		if (secondZero - firstZero > 1)
		{
			for (i = firstZero + 1; i < secondZero; i += 2) {
				product *= a[i];
			}
		}

		else
		{
			cout << "There are no elements between zeros" << endl;
			delete[] a;
			return 1;
		}
	}

	cout << "product: " << product << endl;

	delete[] a;
	return 0;
}

