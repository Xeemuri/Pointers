//DynamicMemory
#include <iostream>
using namespace std;
#define tab "\t";

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* push_back(int arr[], int& n); //добавляет значение в конец массива

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
	
	arr = push_back(arr, n);
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

int* push_back(int arr[], int& n)
{
	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	int* buffer = new int[n+1];

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