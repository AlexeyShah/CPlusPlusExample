#include "pch.h"
#include <iostream>
#include <cmath>
using namespace std;

int reqIncrement(double y, double x, int m);

int main()
{
	double x, y;
	cout << "input numberic X" << endl;
	cin >> x;
	cout << "input numberic Y" << endl;
	cin >> y;

	if (x <= 0 || y <= 1) {
		cout << "valid input data: x > 0 and y > 1";
		return 0;
	}

	int m = reqIncrement(x, y, 1);

	cout << "numberic m = " << m << endl;
	system("pause");

	return 0;
}

int reqIncrement(double x, double y, int m) {
	if (pow(y, m - 1) <= x && x < pow(y, m))
		return m;
	return reqIncrement(x, y, ++m);
}