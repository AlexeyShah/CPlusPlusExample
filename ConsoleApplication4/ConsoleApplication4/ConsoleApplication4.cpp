#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int reqCalcInclude(string str);

int main()
{
	string str;
	cout << "input sequence ASCII symbol:" << endl;
	getline(cin, str);

	if (str.length() == 0) {
		cout << "incorrect sequence" << endl;
		return 0;
	}

	int count = reqCalcInclude(str);
	cout << "number of entries: " << count << endl;
	return 0;
}

int reqCalcInclude(string str) {
	string::size_type loc = str.find("a", 0);
	if (loc != string::npos) {
		str = str.substr(loc + 1, str.length() - loc + 1);
		return reqCalcInclude(str) + 1;
	}
	return 0;
}