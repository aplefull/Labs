#include "stdafx.h"
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int n, i;
	double b, a, sum, x, step;
	cout << "Введите верхнюю границу суммы: ";
	cin >> n;
	cout << "Введите a и b: ";
	cin >> a >> b;
	cout << endl;
	x = 0;
	step = (b - a) / 10.;
	while ((x + step/2) < b) {
			x = a;
		a += step;
		sum = 0;

		for (i = 1; i <= n; i++) {
			sum = sum + 3 * exp(i*x) + 1 / tan(x);
		}
		cout << "x=" << x << " | " << sum << endl;
	}
    return 0;
}

