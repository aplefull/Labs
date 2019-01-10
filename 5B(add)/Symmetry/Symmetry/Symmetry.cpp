//Является симметричной, относительно побочной диагонали?
#include "stdafx.h"
#include <iostream>

using namespace std;

void print(int **a, int rows, int columns) {

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
	int columns, rows;
	bool symetrical = true;

	cout << "Rows: ";
	cin >> rows;
	cout << "Columns: ";
	cin >> columns;

	int **a = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
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
	
	print(a, rows, columns);

	for (int i = 0; i < rows - 1; i++)
	{

		for (int j = 0; j < columns - 1 - i; j++)
		{
			if (a[i][j] != a[rows - j - 1][columns - i - 1]) {
				symetrical = false;
				break;
			}
		}

		if (symetrical == false)
		{
			break;
		}

	}

	if (symetrical == true)
	{
		cout << "Matrix is symetrical.";
	}

	else
	{
		cout << "Matrix is not symetrical.";
	}

	for (int i = 0; i < rows; i++)
	{
		delete[] a[i];
	}

	delete[] a;

    return 0;
}

