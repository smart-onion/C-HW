#include <iostream>


using namespace std;

void task1()
{
	// Task number 1;

	int a = 10;

	int* pa = &a;
	int** pa2 = &pa;
	int*** pa3 = &pa2;
	int**** pa4 = &pa3;
	int***** pa5 = &pa4;

	cout << "&a = " << &a << '\n';
	cout << "&pa = " << &pa << '\n';
	cout << "&pa2 = " << &pa2 << '\n';
	cout << "&pa3 = " << &pa3 << '\n';
	cout << "&pa4 = " << &pa4 << '\n';
	cout << "&pa5 = " << &pa5 << '\n';

	cout << "Using only pa5\n";
	cout << "&pa5 = " << &pa5 << '\n';
	cout << "&pa4 = " << &(*pa5) << '\n';
	cout << "&pa3 = " << &(*(*pa5)) << '\n';
	cout << "&pa2 = " << &(*(*(*pa5))) << '\n';
	cout << "&pa = " << &(*(*(*(*pa5)))) << '\n';
	cout << "&a = " << &(*(*(*(*(*pa5))))) << '\n';
}


void AllocateMemory(int** ar, unsigned int count)
{ 
	if (count > 100000) count = 100000;
	(*ar) = new int[count]; 
}

void RandomFillArray(int* ar, unsigned int count) {
	if (ar == nullptr) {
		return;
	}
	for (int i = 0; i < count; i++)
	{
		ar[i] = rand() % 100;
	}
}

void PrintArray(int* ar, unsigned int count) {
	if (ar == nullptr) {
		return;
	}
	for (int i = 0; i < count; i++)
	{
		cout << ar[i] << ", ";
	}
	cout << '\n';
}

void Append(int** ar, unsigned int* count, int value)
{
	int* temp = new int[*count + 1] {};

	for (int i = 0; i < *count; i++)
	{
		temp[i] = (*ar)[i];
	}


	temp[*count] = value;

	(*count)++;

	delete[] * ar;

	*ar = new int[*count] {};

	for (int i = 0; i < *count; i++)
	{
		(*ar)[i] = temp[i];
	}

	delete[] temp;
}

void Pop(int** ar, unsigned int* count)
{
	if (*count <= 0)
	{
		return;
	}
	int* temp = new int[*count - 1] {};

	for (int i = 0; i < *count - 1; i++)
	{
		temp[i] = (*ar)[i];
	}

	(*count)--;
	
	delete[] *ar;
	*ar = new int[*count] {};

	for (int i = 0; i < *count; i++)
	{
		(*ar)[i] = temp[i];
	}

	delete[] temp;
}

void FreeMemory(int* ar)
{
	delete[] ar;
}

int main()
{
	unsigned int size =3 ;
	int* arr = nullptr;

	AllocateMemory(&arr, size);
	RandomFillArray(arr, size);
	PrintArray(arr, size);

	Append(&arr, &size, 10);
	Append(&arr, &size, 10);
	Append(&arr, &size, 10);
	Append(&arr, &size, 10);
	Append(&arr, &size, 10);
	Pop(&arr, &size);
	Pop(&arr, &size);
	Pop(&arr, &size);
	Pop(&arr, &size);
	Pop(&arr, &size);
	Pop(&arr, &size);
	Pop(&arr, &size);

	while (true)
	{
		Append(&arr, &size, 10);
		Pop(&arr, &size);
	}
	PrintArray(arr, size);

}
