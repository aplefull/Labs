#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int FindMax(int a[], int, int);

int main()
{
	cout << "size: ";
	int size, maxInd;
	cin >> size;

	int *a = new int[size];

	cout << "array: ";
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}

	//поиск максимального обычным циклом
	maxInd = 0;
	for (int i = 1; i < size; i++)
	{
		if (a[maxInd] < a[i])
		{
			maxInd = i;
		}
	}

	cout << a[maxInd] << " | " << FindMax(a, 1, size) << endl;

	delete[] a;
    return 0;
}

int FindMax(int a[], int beg, int end) {

	int max, max2;

	if (end == beg)
	{
		return a[beg - 1];
	}

	max = FindMax(a, beg, (2 * beg + end) / 3);
	max2 = FindMax(a,  (2 * beg + end) / 3 + 1, end);
	
	if (max > max2)
	{
		return max;
	}

	else
	{
		return max2;
	}

}

