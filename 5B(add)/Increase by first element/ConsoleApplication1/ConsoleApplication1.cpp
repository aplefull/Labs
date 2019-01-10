//строки по возрастанию первых элементов
#include "stdafx.h"
#include <iostream>

using namespace std;

void arrSwap(int **a, int i) {
	int *t;
	t = a[i + 1];
	a[i + 1] = a[i];
	a[i] = t;
}

void print(int rows, int columns, int **a) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

}

int main()
{
	int rows, columns;

	cout << "Type in rows: ";
	cin >> rows;
	cout << "Type in columns: ";
	cin >> columns;

	int **a = new int *[rows];
	for (int i = 0; i < rows; i++){
		a[i] = new int [columns];
	}

	//ввод
	cout << "Type in all elements: ";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> a[i][j];
		}
	}

	//вывод
	print(rows, columns, a);

	//bubble sort
	for (int k = 0; k < rows - 1; k++)
	{
		for (int i = 0; i < rows - k - 1; i++)
		{
			if (a[i][0] > a[i + 1][0])
			{
				arrSwap(a, i);
			}
		}
	}

	cout << endl;

	//вывод
	print(rows, columns, a);

	for (int i = 0; i < columns; i++)
	{
		delete[] a[i];
	}
	delete[] a;

    return 0;
}