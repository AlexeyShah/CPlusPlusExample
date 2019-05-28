#define _CRT_SECURE_NO_WARNINGS
#pragma warning(suppress : 4996)

#include "pch.h"
#include <ctime>
#include <iostream>
#include <string>
using namespace std;
 
bool checkDate(int month, int day, int year);

int main()
{
	time_t t = time(NULL);
	struct tm *aTime = localtime(&t);
	string birthDay;
	int mm, dd, yy;

	cout << "input you birthday by format dd.mm.yyyy" << endl;
	getline(cin, birthDay);

	if (birthDay.length() == 0) {
		cout << "format date birthday incorrect";
		return 0;
	}

	dd = atoi(birthDay.substr(0, 2).c_str());
	mm = atoi(birthDay.substr(3, 2).c_str());
	yy = atoi(birthDay.substr(6, 4).c_str());

	if (!checkDate(dd, mm, yy)) {
		cout << "format date birthday incorrect";
		return 0;
	}

	int currYear = 0;
	
	currYear = (aTime->tm_year + 1900) - yy;
	if (currYear > 0 && (aTime->tm_mon + 1) == mm && aTime->tm_mday < dd ||
		currYear > 0 && (aTime->tm_mon + 1) < mm)
		currYear--;

	cout << "You age: " << currYear;

	getline(cin, birthDay);
	   
	return 0;
}

bool checkDate(int month, int day, int year)
{
	time_t t = time(NULL);
	struct tm *aTime = localtime(&t);
	bool valid = true;
	if ((month = 1) || (month = 3) || (month = 5) || (month = 7) ||
		(month = 8) || (month = 10) || (month = 12))
	{
		valid &= day <= 31;
	}
	else if ((month = 4) || (month = 6) || (month = 9) || (month = 11))
	{
		valid &= day <= 30;
	}
	else if ((month = 2) && (year % 4 == 0))
	{
		valid &= day <= 29;
	}
	else if ((month = 2) && (year % 4 != 0))
	{
		valid &= day <= 28;
	};

	if (year > (aTime->tm_year + 1900))
	{
		valid &= false;
	}

	if ((month < 1) || (month > 12))
	{
		valid &= false;
	}
	return valid;
};