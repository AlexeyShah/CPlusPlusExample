#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int arr[1000];
	int m;

	cout << "enter M:" << endl;
	cin >> m;
	cout << "enter numbers separated by spaces:" << endl;

	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}
	
	for (int i = 1; i < m; ++i)
	{
		for (int j = 0; j < m - i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}