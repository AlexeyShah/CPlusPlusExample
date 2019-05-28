#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double x;
    cout << "enter x: ";
	cin >> x;

	const double eps = 1e-6;
	const double lnln = 0.693147180559945309417;
	int k = 0;

	while (x > 2.0)
	{
		x /= 2.0;
		k++;
	}

	x -= 1.;

	double s = 0;
	int n = 1;
	double an = x;

	while (fabs(an) > eps)
	{
		s += an;
		++n;
		an *= -x * (n - 1) / n;
	}

	s += k * lnln;
	
	cout << "result = " << s << endl;

	return 0;
}