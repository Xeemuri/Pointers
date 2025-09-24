﻿//DynamicMemory
#include <iostream>
using namespace std;
using std::cout;
using std::cin;
#define DYNAMIC_MEMORY_2
//#define DYNAMIC_MEMORY_1
#define tab "\t";

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int ROWS, const int COLS);
void Print(int arr[], const int n);
void Print(int** arr, const int ROWS, const int COLS);
int* push_back(int arr[], int& n, int value);	//добавляет значение в конец массива
int* push_front(int arr[], int& n, int value);	//добавляет значение в начало массива

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);

int* insert(int arr[], int& n, int value, int index);
int* erase(int arr[], int& n, int value, int index);

void Allocate(int** arr, const int ROWS, const int COLS);
void Clear(int** arr, const int ROWS);

int** push_row_back(int** arr, int new_row[], int& ROWS, int& COLS);
int** push_row_front(int** arr, int new_row[], int& ROWS, int& COLS);
int** insert_row(int** arr, int new_row[], int& ROWS, int& COLS, int chosen_row);

int** pop_row_back(int** arr, int& ROWS, int COLS);
int** pop_row_front(int** arr, int& ROWS, int COLS);
int** erase_row(int** arr, int& ROWS, int COLS, int chosen_row);

int** push_col_back(int** arr, int new_col[], int& ROWS, int& COLS);
int** push_col_front(int** arr, int new_col[], int& ROWS, int& COLS);
int** insert_col(int** arr, int new_col[], int& ROWS, int& COLS, int chosen_col);

int** pop_col_back(int** arr, int ROWS, int& COLS);
int** pop_col_front(int** arr, int ROWS, int& COLS);
int** erase_col(int** arr, int ROWS, int& COLS, int chosen_col);
void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY1
	int n = 5;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	//добавление значения в конец массива:
	int value, index;

	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите индекс для добавляемого значения: "; cin >> index;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	cout << "Введите индекс для удаляемого значения: "; cin >> index;
	arr = erase(arr, n, value, index);
	Print(arr, n);

	delete[] arr;
}

int* push_back(int arr[], int& n, int value)
{

	int* buffer = new int[n + 1];

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[n] = value;

	delete[] arr;
	arr = buffer;

	n++;
	return arr;
}

int* push_front(int arr[], int& n, int value)
{
	cout << "Введите добавляемое значение: "; cin >> value;
	int* buffer = new int[n + 1];

	for (int i = n; i > 0; i--)
	{
		buffer[i] = arr[i - 1];
	}
	buffer[0] = value;

	delete[] arr;
	arr = buffer;

	n++;
	return arr;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];

	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];

	for (int i = n + 1; i > 0; i--)
	{
		buffer[i - 1] = arr[i];
	}

	delete[] arr;
	arr = buffer;

	n--;
	return arr;
}

int* insert(int arr[], int& n, int value, int index)
{
	if (index >= n) return arr;
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		if (i < index) buffer[i] = arr[i];
		else buffer[i + 1] = arr[i];
	}
	buffer[index] = value;

	delete[] arr;
	arr = buffer;

	n++;
	return arr;
}

int* erase(int arr[], int& n, int value, int index)
{
	if (index >= n) return arr;
	int* buffer = new int[--n];

	for (int i = 0; i < n - 1; i++)
	{
		/*if (i < index) buffer[i] = arr[i];
		else buffer[i] = arr[i + 1];*/
		buffer[i] = arr[i < index ? i : i + 1];
	}

	delete[] arr;
	return buffer;
}

#endif // DYNAMIC_MEMORY1
#ifdef DYNAMIC_MEMORY_2
int rows;
int cols;
cout << "Введите количество строк: "; cin >> rows;
cout << "Введите количество столбцов: "; cin >> cols;

int** arr = new int* [rows];
Allocate(arr, rows, cols);


FillRand(arr, rows, cols);
Print(arr, rows, cols);

int* new_row = new int[cols];
int* new_col = new int[rows];
FillRand(new_row, cols);
FillRand(new_col, rows);

Print(new_col, rows);
cout << endl;

arr = push_row_back(arr, new_row, rows, cols);
Print(arr, rows, cols);

arr = push_row_front(arr, new_row, rows, cols);
Print(arr, rows, cols);

int row_index;
cout << "Введите индекс строки для вставки: "; cin >> row_index;
arr = insert_row(arr, new_row, rows, cols, row_index);
Print(arr, rows, cols);

arr = pop_row_back(arr, rows, cols);
Print(arr, rows, cols);

arr = pop_row_front(arr, rows, cols);
Print(arr, rows, cols);

int col_index;
cout << "Введите индекс столбца для удаления: "; cin >> col_index;
arr = erase_row(arr, rows, cols, col_index);
Print(arr, rows, cols);


arr = push_col_back(arr, new_col, rows, cols);
Print(arr, rows, cols);

arr = push_col_front(arr, new_col, rows, cols);
Print(arr, rows, cols);

int col_index;
cout << "Введите индекс столбца для вставки: "; cin >> col_index;
arr = insert_col(arr, new_col, rows, cols, col_index);
Print(arr, rows, cols);

arr = pop_col_back(arr, rows, cols);
Print(arr, rows, cols);

arr = pop_col_front(arr, rows, cols);
Print(arr, rows, cols);

cout << "Введите индекс столбца для удаления: "; cin >> col_index;
arr = erase_col(arr, rows, cols, row_index);
Print(arr, rows, cols);
Clear(arr, rows);
#endif //DYNAMIC_MEMORY_2
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;

	}
}

void FillRand(int** arr, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << tab;
	}
	cout << endl;
}

void Print(int** arr, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
}

void Allocate(int** arr, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		arr[i] = new int[COLS];
	}
}
void Clear(int** arr, const int ROWS)
{
	for (int i = 0; i < ROWS; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

int** push_row_back(int** arr, int new_row[], int& ROWS, int& COLS)
{
	int** buffer = new int* [ROWS + 1];
	Allocate(buffer, ROWS + 1, COLS);

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < COLS; i++)
	{
		buffer[ROWS][i] = new_row[i];
	}

	ROWS++;
	delete[] arr;
	return buffer;
}

int** push_row_front(int** arr, int new_row[], int& ROWS, int& COLS)
{
	int** buffer = new int* [ROWS + 1];
	Allocate(buffer, ROWS + 1, COLS);

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			buffer[i + 1][j] = arr[i][j];
		}
	}

	for (int i = 0; i < COLS; i++)
	{
		buffer[0][i] = new_row[i];
	}

	ROWS++;
	delete[] arr;
	return buffer;
}

int** insert_row(int** arr, int new_row[], int& ROWS, int& COLS, int chosen_row)
{
	int** buffer = new int* [ROWS + 1];
	Allocate(buffer, ROWS + 1, COLS);

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (i < chosen_row) buffer[i][j] = arr[i][j];
			else buffer[i + 1][j] = arr[i][j];
		}
	}

	for (int i = 0; i < COLS; i++)
	{
		buffer[chosen_row][i] = new_row[i];
	}

	ROWS++;
	delete[] arr;
	return buffer;
}

int** push_col_back(int** arr, int new_col[], int& ROWS, int& COLS)
{
	int** buffer = new int* [ROWS];
	Allocate(buffer, ROWS, COLS + 1);

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < ROWS; i++)
	{
		buffer[i][COLS] = new_col[i];
	}

	COLS++;
	delete[] arr;
	return buffer;
}

int** push_col_front(int** arr, int new_col[], int& ROWS, int& COLS)
{
	int** buffer = new int* [ROWS];
	Allocate(buffer, ROWS, COLS + 1);

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			buffer[i][j + 1] = arr[i][j];
		}
	}

	for (int i = 0; i < ROWS; i++)
	{
		buffer[i][0] = new_col[i];
	}

	COLS++;
	delete[] arr;
	return buffer;
}
int** insert_col(int** arr, int new_col[], int& ROWS, int& COLS, int chosen_col)
{
	int** buffer = new int* [ROWS];
	Allocate(buffer, ROWS, COLS + 1);

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (j < chosen_col)buffer[i][j] = arr[i][j];
			else buffer[i][j + 1] = arr[i][j];
		}
	}

	for (int i = 0; i < ROWS; i++)
	{
		buffer[i][chosen_col] = new_col[i];
	}

	COLS++;
	delete[] arr;
	return buffer;
}

int** pop_row_back(int** arr, int& ROWS, int COLS)
{
	int** buffer = new int* [--ROWS];
	Allocate(buffer, ROWS, COLS);

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}

	delete[] arr;
	return buffer;
}
int** pop_row_front(int** arr, int& ROWS, int COLS)
{
	int** buffer = new int* [--ROWS];
	Allocate(buffer, ROWS, COLS);

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			buffer[i][j] = arr[i + 1][j];
		}
	}

	delete[] arr;
	return buffer;
}
int** erase_row(int** arr, int& ROWS, int COLS, int chosen_row)
{
	if (chosen_row >= ROWS) return arr;
	int** buffer = new int* [--ROWS];
	Allocate(buffer, ROWS, COLS);

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (i < chosen_row) buffer[i][j] = arr[i][j];
			else buffer[i][j] = arr[i + 1][j];
		}
	}

	delete[] arr;
	return buffer;
}

int** pop_col_back(int** arr, int ROWS, int& COLS)
{
	int** buffer = new int* [ROWS];
	Allocate(buffer, ROWS, --COLS);

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}

	delete[] arr;
	return buffer;
}
int** pop_col_front(int** arr, int ROWS, int& COLS)
{
	int** buffer = new int* [ROWS];
	Allocate(buffer, ROWS, --COLS);

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			buffer[i][j] = arr[i][j + 1];
		}
	}
	delete[] arr;
	return buffer;
}
int** erase_col(int** arr, int ROWS, int& COLS, int chosen_col)
{
	int** buffer = new int* [ROWS];
	Allocate(buffer, ROWS, --COLS);

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (j < chosen_col) buffer[i][j] = arr[i][j];
			else buffer[i][j] = arr[i][j + 1];

		}
	}
	delete[] arr;
	return buffer;
}