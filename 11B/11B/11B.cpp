/*
test1 7 2
test2 8 11
test3 8 46
test4 8 1
test5 8 10
test6 8 0
test7 8 10
test8 8 5
*/

#include "stdafx.h"
#include <iostream>
#include <io.h>
#include <stdio.h>
#include <array>

using namespace std;

void CreateFile(FILE*);
int Menu();
void WriteToFile(FILE*);
void ReadFromFile(FILE*);
void Display(FILE*);
void ExportFile(FILE*);

struct seeds
{
	char name[100];
	int plantingMonth;
	int harvestingMonth;
};

seeds ToFile, *FromFile;

void SelectionSort(FILE*, seeds []);
void QuickSort(seeds[], int, int);

int main()
{
	FILE *fl = NULL;

	while (true)
	{
		switch (Menu())
		{
		case 1: WriteToFile(fl); break;
		case 2: ReadFromFile(fl); break;
		case 3: Display(fl); break;
		case 4: ExportFile(fl); break;

		default: cout << "Type number from 1 to 4"; break;
		}

		break;
	}

	return 0;
}

void CreateFile(FILE* fl)
{
	fl = fopen("C:\\Users\\User\\Desktop\\test.txt", "wb");

	if (fl == NULL)
	{
		cout << "error" << endl;
		return;
	}

	fclose(fl);
}

int Menu() {
	int x;
	cout << "Select what to do: \n 1: Write to the file \n 2: Read from file \n 3: Display data \n 4: Export file" << endl;
	cin >> x;
	return x;
}

void WriteToFile(FILE* fl) {

	fl = fopen("C:\\Users\\User\\Desktop\\test.txt", "wb");
	if (fl == NULL)
	{
		cout << "error" << endl;
		return;
	}

	int n;
	cout << "number of seeds: ";
	cin >> n;

	cout << "name, planting month, harvesting month: " << endl;

	for (int i = 0; i < n; i++)
	{
		cin >> ToFile.name >> ToFile.plantingMonth >> ToFile.harvestingMonth;
		fwrite(&ToFile, sizeof(seeds), 1, fl);
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

	fseek(fl, 0, SEEK_END);
	int size = ftell(fl);
	rewind(fl);

	int n = _filelength(_fileno(fl)) / sizeof(seeds);
	FromFile = new seeds[n];
	fread(FromFile, sizeof(seeds), n, fl);

	delete FromFile;
	fclose(fl);
}

void Display(FILE* fl) {

	fl = fopen("C:\\Users\\User\\Desktop\\test.txt", "rb");
	if (fl == NULL)
	{
		cout << "error" << endl;
		return;
	}

	int n = _filelength(_fileno(fl)) / sizeof(seeds);
	FromFile = new seeds[n];
	fread(FromFile, sizeof(seeds), n, fl);

	for (int i = 0; i < n; i++)
	{
		cout << "name: " << FromFile[i].name << endl << "planting month: " << FromFile[i].plantingMonth << endl << "harvesting month:" << FromFile[i].harvestingMonth << endl << endl;
	}

	delete FromFile;
	fclose(fl);
}

void ExportFile(FILE* fl) {

	fl = fopen("C:\\Users\\User\\Desktop\\test.txt", "rb");
	if (fl == NULL)
	{
		cout << "error" << endl;
		return;
	}

	int n = _filelength(_fileno(fl)) / sizeof(seeds);
	FromFile = new seeds[n];
	fread(FromFile, sizeof(seeds), n, fl);

	//сортировка 
	//SelectionSort(fl, FromFile);
	QuickSort(FromFile, 0, n - 1);
	fclose(fl);


	FILE* Export = fopen("C:\\Users\\User\\Desktop\\export.txt", "wb");
	if (Export == NULL)
	{
		cout << "error" << endl;
		return;
	}

	//экспорт
	for (int i = 0; i < n; i++)
	{

		if (FromFile[i].plantingMonth == 8)
		{
			fprintf(Export, "name: %s | planting month: %d | harvesting month: %d\n", FromFile[i].name, FromFile[i].plantingMonth, FromFile[i].harvestingMonth);
		}
	}

	delete FromFile;
	fclose(Export);
}

void SelectionSort(FILE* fl, seeds FromFile[]) {

	int size = _filelength(_fileno(fl)) / sizeof(seeds);
	seeds temp;

	for (int i = 0; i < size - 1; i++)
	{
		int min_index = i;

		for (int k = i; k < size; k++) {

			if (FromFile[k].harvestingMonth < FromFile[min_index].harvestingMonth) {
				min_index = k;
			}

		}

		//swap
		temp = FromFile[i];
		FromFile[i] = FromFile[min_index];
		FromFile[min_index] = temp;
	}
}

void QuickSort(seeds a[], int left, int right) {

	int i, j, pivot = a[(left + right) / 2].harvestingMonth;
	seeds temp;

	for (i = left, j = right; i <= j; )
	{

		while (a[i].harvestingMonth < pivot && i < right)
		{
			i++;
		}
		while (a[j].harvestingMonth > pivot && j > left)
		{
			j--;
		}
		
		if(i <= j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}

	if (left < j)
	{
		QuickSort(a, left, j);
	}

	if (right > i)
	{
		QuickSort(a, i, right);
	}
}