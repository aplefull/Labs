
#include "stdafx.h"
#include<iostream>
#include <io.h>
#include <stdio.h>
#include <ctime>
#include <string.h>

using namespace std;

FILE* CreateFile() {
	FILE *fl = fopen("D:\\test.txt", "wb");
	return fl;
}

void WriteToFile(char* name, int plantingMonth, int harvestingMonth, FILE* fl);

void ReadFromFile(FILE* fl);

void Display(char a[]) {
	int len = strlen(a);
	for (int i = 0; i < len; i++)
	{
		cout << a[i];
	}
}

int main()
{
	int n;
	struct Seeds
	{
		char name[100];
		int plantingMonth;
		int harvestingMonth;
	};

	cout << "number of seeds: ";
	cin >> n;

	Seeds *data = new Seeds[n];

	cout << "name, planting month, harvesting month" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> data[i].name >> data[i].plantingMonth >> data[i].harvestingMonth;
	}

	FILE *fl = CreateFile();
	for (int i = 0; i < n; i++)
	{
		WriteToFile(data[i].name, data[i].plantingMonth, data[i].harvestingMonth, fl);
	}


	ReadFromFile(fl);

	return 0;
}

void WriteToFile(char* name, int plantingMonth, int harvestingMonth, FILE* fl) {
	char temp[100] = "";
	fputs(" | Crop name: ", fl);
	fputs(name, fl);
	fputs(" | Planting Month: ", fl);
	fputs(_itoa(plantingMonth, temp, 10), fl);
	fputs(" | Harvesting Month: ", fl);
	fputs(_itoa(harvestingMonth, temp, 10), fl);
	//fputc('\n',fl);
}

void ReadFromFile(FILE* fl) {
	fopen("D:\\test.txt", "wb");
	fseek(fl, 0, SEEK_END);
	int size = ftell(fl);
	rewind(fl);
	char * temp = (char*)malloc(sizeof(char) * size);
	fread(temp, 1, size, fl);
	Display(temp);
}