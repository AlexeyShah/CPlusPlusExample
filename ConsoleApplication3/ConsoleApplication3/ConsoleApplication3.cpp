#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int count = 0;
	for (int i = 100; i < 1000; i++) {
		string str = to_string(i);
		if (str[0] != str[1] && str[1] != str[2] && str[0] != str[2])
			count++;
	}

	cout << "Count numberic:" << count << endl;
	system("pause");

	return 0;
}