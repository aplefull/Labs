#include <iostream>
#include <math.h>

using namespace std;

int main() {
	double x, y, z, a, b;
		x = 17.421;
		y = 10.365E-3;
		z = 0.828E5;
		a = pow(y + pow(x - 1, 1 / 3.), 1 / 4.);
		b = fabs(x - y)*(sin(z)*sin(z) + tan(z));

		cout << a / b << endl;
	return 0;
}