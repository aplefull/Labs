#include "stdafx.h"
#include <iostream>
#define if if

using namespace std;

int main()
{
	struct crops
	{
		char name[100];
		int monthPlant, monthPlant2, monthHarvest;
	};
	crops *seed;

	int size;
	cout << "Amount of different seeds: ";
	cin >> size;

	seed = new crops[size];

	for (int i = 0; i < size; i++)
	{
		cout << "Type in seed name, first month, 2nd month, harvest month: ";
			cin >> seed[i].name;
			cin >> seed[i].monthPlant;
			cin >> seed[i].monthPlant2;
			cin >> seed[i].monthHarvest;
	}

	crops t;

	for (int j = 0; j < size - 1; j++)
	{
		for (int i = 0; i < size - i; i++)
		{
			if (strcmp(seed[i].name, seed[i + 1].name) == 1) {
				t = seed[i];
				seed[i] = seed[i + 1];
				seed[i + 1] = t;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (seed[i].monthHarvest == 8) {
			cout << "Plants, which have to be harvested in August: " << seed[i].name << endl;
		}
	}

	delete[] seed;
    return 0;
}

