// 2A.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b, c, d, sumPos, sumNeg;
	sumPos = 0;
	sumNeg = 0;
	cout << "Введите 4 числа через пробел" << endl;
	cin >> a >> b >> c >> d;
	a >= 0 ? sumPos += a : sumNeg += abs(a);
	b >= 0 ? sumPos += b : sumNeg += abs(b);
	c >= 0 ? sumPos += c : sumNeg += abs(c);
	d >= 0 ? sumPos += d : sumNeg += abs(d);
	cout << "Сумма положительных: " << sumPos << endl;
	cout << "Сумма отрицательных: " << sumNeg << endl;
	cout << sumPos - sumNeg << endl;

    return 0;
}

