//DynamicMemory
#include <iostream>
using namespace std;
#define tab "\t";

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void AddValue(int*& arr, int& n, int value);

void main()
{
	setlocale(LC_ALL, "");
	int n = 5;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	//добавление значения в конец массива:
	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	AddValue(arr, n, value);
	Print(arr, n);
	delete[] arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;

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

void AddValue(int*& arr, int& n, int value)
{
	n++;
	int* new_arr = new int[n];

	for (int i = 0; i < n-1; i++)
	{
		new_arr[i] = arr[i];
	}
	new_arr[n-1] = value;

	arr = new_arr;
}