//DynamicMemory
#include <iostream>
using namespace std;
using std::cout;
using std::cin;
#define DYNAMIC_MEMORY_2
//#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_1_FUNCS
#define tab "\t";

void FillRand(int arr[], const int n, int minRand = 0, int maxRand=100);
void FillRand(int** arr, const int rows, const int cols);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);
int* push_back(int arr[], int& n, int value);	//добавляет значение в конец массива
int* push_front(int arr[], int& n, int value);	//добавляет значение в начало массива

int* pop_back(int arr[], int& n); 
int* pop_front(int arr[], int& n);

int* insert(int arr[], int& n, int value, int index);
int* erase(int arr[], int& n, int value, int index);

int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);

int** push_row_back(int** arr, int& rows, const int cols);
int** push_row_front(int** arr, int& rows, const int cols);
int** insert_row(int** arr, int& rows, const int cols, int row_index);

int** pop_row_back(int** arr, int& rows, const int cols);
int** pop_row_front(int** arr, int& rows, const int cols);
int** erase_row(int** arr, int& rows, const int cols,int row_index);

void push_col_back(int** arr, const int rows, int& cols);
void push_col_front(int** arr, const int rows, int& cols);
void insert_col(int** arr, const int rows, int& cols, int col_index);

void pop_col_back(int** arr, const int rows, int& cols);
void pop_col_front(int** arr, const int rows, int& cols);
void erase_col(int** arr,const int rows, int& cols, int col_index);
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

#endif // DYNAMIC_MEMORY1
#ifdef DYNAMIC_MEMORY_2
	int rows;
	int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество столбцов: "; cin >> cols;

	int**arr = Allocate(rows, cols);


	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	
	cout << "Добавление строки в конец массива:" << endl;
	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows-1], cols);
	Print(arr, rows, cols);

	cout << "Добавление строки в начало массива:" << endl;
	arr = push_row_front(arr, rows, cols);
	FillRand(arr[0], cols);
	Print(arr, rows, cols);

	int row_index;
	cout << "Введите индекс строки для вставки: "; cin >> row_index;
	arr = insert_row(arr, rows, cols,row_index);
	FillRand(arr[row_index], cols);
	Print(arr, rows, cols);

	
	cout << "Удаление строки в конце массива:" << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Удаление строки в начале массива:" << endl;
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	int col_index;
	cout << "Введите индекс строки для удаления: "; cin >> col_index;
	arr = erase_row(arr, rows, cols, col_index);
	Print(arr, rows, cols);


	cout << "Добавление столбца в конец массива:" << endl;
	push_col_back(arr, rows, cols);
	for (int i = 0; i < rows; i++) arr[i][cols - 1] = rand() % 100;
	Print(arr, rows, cols);
	
	cout << "Добавление столбца в начало массива:" << endl;
	push_col_front(arr, rows, cols);
	for (int i = 0; i < rows; i++) arr[i][0] = rand() % 100;
	Print(arr, rows, cols);

	cout << "Введите индекс столбца для вставки: ";cin >> col_index;
	insert_col(arr, rows, cols, col_index);
	for (int i = 0; i < rows; i++) arr[i][col_index] = rand() % 100;
	Print(arr, rows, cols);

	cout << "Удаление столбца в конце массива:" << endl;
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Удаление столбца в начале массива:" << endl;
	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите индекс столбца для удаления: "; cin >> col_index;
	erase_col(arr, rows, cols, row_index);
	Print(arr, rows, cols);
	Clear(arr, rows);
#endif //DYNAMIC_MEMORY_2
}

#ifdef DYNAMIC_MEMORY_1_FUNCS

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
#endif  //DYNAMIC_MEMORY_1_FUNCS


void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand-minRand) + minRand;

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


void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
}

int** Allocate(const int rows, const int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}
void Clear(int** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

int** push_row_back(int** arr,int& rows,const int cols)
{
	//создаем новый массив указателей:
	int** buffer = new int* [rows + 1];

	// Копируем адреса строк из исходного массива
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];

	//Удаляем исходный массив указателей
	delete[] arr;

	buffer[rows] = new int[cols] {};
	rows++;
	return buffer;
}

int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];

	for (int i = 0; i < rows; i++) buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = new int[cols] {};
	rows++;
	return buffer;
}

int** insert_row(int** arr, int& rows, const int cols, int row_index)
{
	if (row_index > rows) row_index = rows;
	int** buffer = new int* [rows + 1] {};

	for (int i = 0; i < rows; i++) (i < row_index ? buffer[i] : buffer[i + 1]) = arr[i];
	delete[] arr;
	buffer[row_index] = new int[cols] {};
	rows++;
	return buffer;
}

void push_col_back(int** arr, const int rows, int& cols)
{

	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols+1] {};

		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

void push_col_front(int** arr, const int rows, int& cols)
{

	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int [cols + 1] {};

		for (int j = 0; j < cols; j++) buffer[j+1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void insert_col(int** arr, const int rows, int& cols, int col_index)
{
	if (col_index > cols) col_index = cols;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int [cols + 1] {};

		for (int j = 0; j < cols+1; j++) (j < col_index ? buffer[j] : buffer[j + 1]) = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

int** pop_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows];

	for (int i = 0; i < rows; i++)buffer[i] = arr[i];

	delete[] arr[rows];
	delete[] arr;
	return buffer;
}
int** pop_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows];

	for (int i = 0; i < rows; i++) buffer[i] = arr[i+1];
	delete[] arr;
	return buffer;
}
int** erase_row(int** arr, int& rows, const int cols, int row_index)
{
	if (row_index >= rows) return arr;

	int** buffer = new int* [--rows];

	for (int i = 0; i < rows; i++) buffer[i] = (i < row_index ? arr[i] : arr[i + 1]);
	delete[] arr;
	return buffer;
}

void pop_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int [cols-1];
		for (int j = 0; j < cols-1; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void pop_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols-1];
		for (int j = 0; j < cols-1; j++) buffer[j] = arr[i][j+1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void erase_col(int** arr, const int rows, int& cols, int col_index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols-1];
		for (int j = 0; j < cols-1; j++) buffer[j] = (j < col_index ? arr[i][j] : arr[i][j + 1]);
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}