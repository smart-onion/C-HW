#include <iostream>
using namespace std;
void AllocateMemory(int*** ar, int size)
{
    *ar = new int* [size];

	for (int i = 0; i < size; i++)
	{
		(*ar)[i] = new int[size] {};
	}
}

void Delete2dArr(int** ar, int row)
{
	for (int i = 0; i < row; i++)
	{
		delete[] ar[i];
	}
	delete[](*ar);
}
void AddRow(int*** ar, int* row, int column)
{
	int** temp = new int* [*row + 1];
	for (int i = 0; i < *row + 1; i++)
	{
		temp[i] = new int[column] {};
	}

	for (int i = 0; i < *row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			temp[i][j] = (*ar)[i][j];
		}
	}


	for (int i = 0; i < *row; i++)
	{
		delete[](*ar)[i];
	}
	delete[](*ar);

	(*row)++;

	*ar = new int* [*row];
	for (int i = 0; i < *row; i++)
	{
		(*ar)[i] = new int[column] {};
		for (int j = 0; j < column; j++)
		{
			(*ar)[i][j] = temp[i][j];
		}
	}
	for (int i = 0; i < *row; i++)
	{
		delete[]temp[i];
	}
	delete[]temp;

}

void DeleteRow(int*** ar, int* row, int column)
{
	int** temp = new int* [*row -1];
	for (int i = 0; i < *row - 1; i++)
	{
		temp[i] = new int[column] {};
	}

	for (int i = 0; i < *row - 1; i++)
	{
		for (int j = 0; j < column; j++)
		{
			temp[i][j] = (*ar)[i][j];
		}
	}


	for (int i = 0; i < *row; i++)
	{
		delete[](*ar)[i];
	}
	delete[](*ar);

	(*row)--;

	*ar = new int* [*row];
	for (int i = 0; i < *row; i++)
	{
		(*ar)[i] = new int[column] {};
		for (int j = 0; j < column; j++)
		{
			(*ar)[i][j] = temp[i][j];
		}
	}
	for (int i = 0; i < *row; i++)
	{
		delete[]temp[i];
	}
	delete[]temp;
}


void AddColumn(int*** ar, int* column, int row)
{
	int** temp = new int* [row];
	for (int i = 0; i < row; i++)
	{
		temp[i] = new int[*column + 1] {};
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < *column; j++)
		{
			temp[i][j] = (*ar)[i][j];
		}
	}

	for (int i = 0; i < row; i++)
	{
		delete[] (*ar)[i];
	}
	delete[](*ar);

	(*column)++;

	*ar = new int*[row];
	for (int i = 0; i < row; i++)
	{
		(*ar)[i] = new int[*column];
		for (int j = 0; j < *column; j++)
		{
			(*ar)[i][j] = temp[i][j];
		}
	}

	for (int i = 0; i < row; i++)
	{
		delete[] temp[i];
	}
	delete[]temp;

}


void DeleteColumn(int*** ar, int* column, int row)
{
	int** temp = new int* [row];
	for (int i = 0; i < row; i++)
	{
		temp[i] = new int[*column - 1] {};
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < *column - 1; j++)
		{
			temp[i][j] = (*ar)[i][j];
		}
	}

	for (int i = 0; i < row; i++)
	{
		delete[](*ar)[i];
	}
	delete[](*ar);

	(*column)--;

	*ar = new int* [row];
	for (int i = 0; i < row; i++)
	{
		(*ar)[i] = new int[*column];
		for (int j = 0; j < *column; j++)
		{
			(*ar)[i][j] = temp[i][j];
		}
	}

	for (int i = 0; i < row; i++)
	{
		delete[] temp[i];
	}
	delete[]temp;
}


void PrintArr(int** ar, int column, int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << ar[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main()
{
	int column = 10;
	int row = 10;
	int** ar2d = nullptr;

	AllocateMemory(&ar2d, column);
	PrintArr(ar2d, column, row);
	cout << "\n\n\n";
	while (true)
	{
		AddRow(&ar2d, &row, column);
		DeleteRow(&ar2d, &row, column);

		DeleteColumn(&ar2d, &column, row);
		AddColumn(&ar2d, &column, row);

	}


	PrintArr(ar2d, column, row);


}

