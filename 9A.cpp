//вывести все элементы до минимального

#include "stdafx.h"
#include<iostream>
#include <io.h>
#include <stdio.h>

using namespace std;

void WriteToFile(FILE*);
void ReadFromFile(FILE*);

int main()
{
	FILE *fl = NULL;

	WriteToFile(fl);
	ReadFromFile(fl);

	return 0;
}

void WriteToFile(FILE* fl) {

	fl = fopen("C:\\Users\\User\\Desktop\\test.txt", "wb");
	if (fl == NULL)
	{
		cout << "error" << endl;
		return;
	}

	cout << "Type in 10 numbers: " << endl;
	int t;
	for (int i = 0; i < 10; i++)
	{
		cin >> t;
		fwrite(&t, sizeof(t), 1, fl);
	}

	fclose(fl);
}

void ReadFromFile(FILE* fl) {

	fl = fopen("C:\\Users\\User\\Desktop\\test.txt", "rb");
	if (fl == NULL)
	{
		cout << "error" << endl;
		return;
	}

	int n = _filelength(_fileno(fl)) / sizeof(int);

	//поиск минимального значения
	int min, temp, minIndex = 0;
	fread(&min, sizeof(int), 1, fl);

	for (int i = 0; i < 9; i++)
	{
		fread(&temp, sizeof(int), 1, fl);
		if (temp < min)
		{
			minIndex = i + 1;
			min = temp;
		}
	}

	rewind(fl);

	if (minIndex == 0)
	{
		cout << "First element is min.";
	}

	else
	{
		for (int i = 0; i < minIndex; i++)
		{
			fread(&temp, sizeof(int), 1, fl);
			cout << temp << " ";
		}
	}

	fclose(fl);
}
