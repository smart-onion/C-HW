#include <iostream>

using namespace std;


int main()
{
	double a = 10;
	double b = 15;

	double* pa = &a;
	double* pb = &b;

	double different = abs(pa - pb);
	double size = sizeof(double);

	cout << different << " variables of type double\n";
	cout << different * size << " bytes\n";
}
