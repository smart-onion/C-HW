#include <iostream>
#include <windows.h>
#include <ctime>
#include <math.h>
using namespace std;


bool CompareChar(char a, char b)
{
	if (a == b) return true;
	if ((int)a - 32 == (int)b) return true;
	if ((int)b - 32 == (int)a) return true;
	return false;
}

bool Palindrom(char* string)
{
	int length = 0;
	int i = 0;
	while (string[i] != 0)
	{
		if (string[i] != ' ')
		{
			length++;
		}
		i++;
	}

	char* buffer = new char[length + 1] {};

	for (int i = 0, j = 0; i < length; i++, j++)
	{
		if (string[j] == ' ') j++;
		buffer[i] = string[j];
	}

	for (int i = 0, j = length - 1; i < length; i++, j--)
	{
		if (!CompareChar(buffer[i],buffer[j]))
		{
			cout << "Not palindrom" << '\n';
			return false;
		}
	}

	cout << "palindrom" << '\n';
	return true;
}

void task4()
{
	int size = 100;
	char* string = new char[size];
	cout << "enter string: ";
	gets_s(string, size - 1);
	Palindrom(string);

}

void isSpam(char* string, char**restricted, int restrictSize)
{
	int size = 50;
	char* buffer = new char[size];

	int i = 0;
	int j = 0;
	while (string[i] != 0)
	{
		if (string[i] != ' ')
		{
			buffer[j] = string[i];
			buffer[j + 1] = 0;
			j++;
		}
		else
		{
			for (int i = 0; i < restrictSize; i++)
			{
				if (_strcmpi(buffer, restricted[i]) == 0)
				{
					cout << string << " => SPAM!";
					return;
				}
			}

			j = 0;
			buffer[j] = 0;
		}
		i++;
	}
	cout << string << " => NOT SPAM!";

	return;
}

void AllocateMemory(char*** ar, int size)
{
	int wordLength = 50;
	*ar = new char* [size];
	for (int i = 0; i < size; i++)
	{
		*ar[i] = new char[wordLength] {};
	}
}

void AddRestriction(char***ar, int*size, const char*word)
{
	int wordLength = 50;
	int index = 0;
	char** temp = new char* [*size + 1];
	for (int i = 0; i < *size + 1; i++)
	{
		temp[i] = new char[wordLength] {};
	}

	for (int i = 0; i < *size; i++)
	{
		for (int j = 0; j < wordLength; j++)
		{
			temp[i][j] = (*ar)[i][j];
		}
	}

	while (word[index] != 0)
	{
		temp[*size][index] = word[index];
		index++;

	}
	

	for (int i = 0; i < *size; i++)
	{
		delete[](*ar)[i];
	}
	delete[] * ar;

	(*size)++;

	*ar = new char* [*size];
	for (int i = 0; i < *size; i++)
	{
		(*ar)[i] = new char[wordLength];
		for (int j = 0; j < wordLength; j++)
		{
			(*ar)[i][j] = temp[i][j];
		}
	}

	for (int i = 0; i < *size; i++)
	{
		delete[] temp[i];
	}
	delete[] temp;
}

void task6()
{
	int size = 100;
	int restrictSize = 1;
	char* string = new char[size] {};
	char** restricted = nullptr;
	cout << "Enter string: ";
	gets_s(string, size - 1);

	AllocateMemory(&restricted, restrictSize);

	AddRestriction(&restricted, &restrictSize, "xxx");
	AddRestriction(&restricted, &restrictSize, "viagra");

	isSpam(string, restricted, restrictSize);
}

void GeneratePassword(char* pwd, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		pwd[i] = rand() % 93 + 33;
	}
	pwd[length - 1] = 0;
}

void task8()
{
	srand(time(0));
	int length = 10;
	char* password = new char[length - 1];
	GeneratePassword(password, length);

	cout << password;
}


double ToNumber(const char* string)
{
	double number = 0;
	int length = 0;

	while (string[length] != 0)
	{
		length++;
	}
	int power = length - 1;
	for (int i = 0; i < length; i++)
	{
		number += ((int)string[i] - 48) * pow(10, power--);

	}

	return number;
}


void task19()
{
	
	double sum = ToNumber("12344624") + ToNumber("19872452345");
	cout << sum << '\n';

}

int main()
{
	task4();
}
