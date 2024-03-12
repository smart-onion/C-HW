#include <iostream>

using namespace std;

int pwd(int* a, int* b)
{
	int result = *a;

	if (*b == 0)
	{
		return 1;
	}

	for (int i = 0; i < *b - 1; i++)
	{
		result *= *a;
	}

	return result;
}
int main()
{
	int a;
	int b;
	cout << "Input a: ";
	cin >> a;
	cout << "Input b: ";
	cin >> b;

	int result = pwd(&a, &b);

	cout << result;
}

