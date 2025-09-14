#include <iostream>
using namespace std;


void Print(int arr[], const int  n);

void main() 
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int odd_nums = 0;
	int even_nums = 0;

	
	int arr[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		if (arr[i] % 2 == 0) even_nums++;
		else odd_nums++;
	}
	
	Print(arr, n);

	int* even = new int[even_nums];
	int* odd = new int[odd_nums];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0) *(even++) = arr[i];
		else *(odd++) = arr[i];
	}

	even -= even_nums;
	odd -= odd_nums;

	Print(even, even_nums);
	Print(odd, odd_nums);
	delete[] even;
	delete[] odd;
}


void Print(int arr[], const int  n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}