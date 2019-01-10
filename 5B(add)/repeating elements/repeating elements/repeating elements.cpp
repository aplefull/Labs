//find number of different elements.
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int rows, cols, sum = 0, res = 0, x;
	bool getOut = false;

	cout << "rows: ";
	cin >> rows;
	cout << "cols: ";
	cin >> cols;

	char **a = new char*[rows];
	for (int i = 0; i < rows; i++)
	{
		a[i] = new char[cols];
	}

	//ввод
	cout << "Type in all elements: ";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin >> a[i][j];
		}
	}

	//вывод
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			x = j;
			for (int k = i; k < rows; k++)
			{
				for (int n = x; n < cols; n++)
				{
					if (a[i][j] == a[k][n])
					{
						sum++;
						if (sum == 2)
						{
							res++;
							sum = 0;
							getOut = true;
							break;
						}
					}
				}

				if (getOut == true)
				{
					getOut = false;
					break;
				}
				x = 0;
			}
			sum = 0;
		}
	}
	

	cout << "number of different elements: " << rows * cols - res << endl;

	for (int i = 0; i < rows; i++)
	{
		delete[] a[i];
	}
	delete a;

    return 0;
}

