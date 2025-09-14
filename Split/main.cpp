#include <iostream>
using namespace std;


void Print(int arr[], const int  n);

int main() 
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int odd_count = 0;
	int even_count = 0;

	
	int arr[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		if (arr[i] % 2 == 0) even_count++;
		else odd_count++;
	}
	
	Print(arr, n);

	int* even = new int[even_count];
	int* odd = new int[odd_count];

	even_count = odd_count = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0) even[even_count++] = arr[i];
		else odd[odd_count++] = arr[i];
	}

	cout << "Четные числа в массиве: ";
	Print(even, even_count);
	cout << "Нечетные числа в массиве: ";
	Print(odd, odd_count);

	delete[] even;
	delete[] odd;

	return 0;
}


void Print(int arr[], const int  n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}