// 1A.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

		float x;
		cout << "Введите дюймы" << endl;
		cin >> x;
		x = x * 2.54;
		cout << x << "см" << endl;
	
    return 0;
	system("pause");
}

