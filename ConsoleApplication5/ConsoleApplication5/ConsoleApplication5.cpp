#include "pch.h"
#include <iostream>
#include <cmath>
using namespace std;

int calcfact(int a, int powM, int m);

int main()
{
	int m, a;
	cout << "input numberic M:" << endl;
	cin >> m;
	cout << "input numberic A:" << endl;
	cin >> a;
	
	if (m < 1) {
		cout << "Incorrect numberic" << endl;
		return 0;
	}

	int count = calcfact(a, 0, m);
	cout << "Summ: " << count << endl;
	system("pause");
	return 0;
}

int calcfact(int a, int powM, int m) {
	if (powM > m)
		return 0;
	return pow(a, powM) + calcfact(a, ++powM, m);
}