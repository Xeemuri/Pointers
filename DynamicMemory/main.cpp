#include <iostream>
using namespace std;
//#define DYNAMIC_MEMORY_2
#define DYNAMIC_MEMORY_1_FUNCS
#define tab "\t";

void FillRand(int arr[], const int n, int minRand = 0, int maxRand=100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand=100);
void FillRand(char arr[], const int n);

void FillRand(int** arr, const int rows, const int cols);
void FillRand(double** arr, const int ROWS, const int COLS);
void FillRand(char** arr, const int ROWS, const int COLS);

template<typename T>void Print(T arr[], const int n);
template<typename T>void Print(T** arr, const int rows, const int cols);

template<typename T>T* push_back(T arr[], int& n, T value);	//добавляет значение в конец массива
template<typename T>T* push_front(T arr[], int& n, T value);	//добавляет значение в начало массива
template<typename T>T* pop_back(T arr[], int& n);
template<typename T>T* pop_front(T arr[], int& n);

template<typename T>T* insert(T arr[], int& n, T value, int index);
template <typename T>T* erase(T arr[], int& n, int index);

template <typename T>T** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);

int** push_row_back(int** arr, int& rows, const int cols);
template <typename T>T** push_row_front(T** arr, int& rows, const int cols);
template <typename T>T** insert_row(T** arr, int& rows, const int cols, int row_index);

template <typename T>T** pop_row_back(T** arr, int& rows, const int cols);
template <typename T>T**pop_row_front(T** arr, int& rows, const int cols);
template <typename T>T** erase_row(T** arr, int& rows, const int cols,int row_index);

template <typename T>void push_col_back(T** arr, const int rows, int& cols);
template <typename T>void push_col_front(T** arr, const int rows, int& cols);
template <typename T>void insert_col(T** arr, const int rows, int& cols, int col_index);

template <typename T>void pop_col_back(T** arr, const int rows, int& cols);
template <typename T>void pop_col_front(T** arr, const int rows, int& cols);
template <typename T>void erase_col(T** arr,const int rows, int& cols, int col_index);
void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_2
	int rows;
	int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество столбцов: "; cin >> cols;

	int** arr = Allocate<int>(rows, cols);


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
	int n = 5;
	cout << "Введите размер массива: "; cin >> n;

	typedef double DataType;
	DataType* arr = new DataType[n];

	FillRand(arr, n);
	Print(arr, n);

	arr = push_back(arr, n, 3.14);
	Print(arr, n);

	arr = push_front(arr, n, 2.7);
	Print(arr, n);

	arr = insert(arr, n, 9.11, 3);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);
	
	arr = erase(arr, n, 3);
	delete[] arr;
}


template<typename T>T* push_back(T arr[], int& n, T value)
{
	T* buffer = new T[n + 1];

	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	buffer[n] = value;

	delete[] arr;
	arr = buffer;

	n++;
	return arr;
}
template<typename T>T* push_front(T arr[], int& n, T value)
{
	T* buffer = new T[n + 1];

	for (int i = n; i > 0; i--) buffer[i] = arr[i - 1];
	buffer[0] = value;

	delete[] arr;
	arr = buffer;

	n++;
	return arr;
}
template<typename T>T* pop_back(T arr[], int& n)
{
	T* buffer = new T[--n];

	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
template <typename T>T* pop_front(T arr[], int& n)
{
	T* buffer = new T[--n];

	for (int i = n + 1; i > 0; i--) buffer[i - 1] = arr[i];

	delete[] arr;
	arr = buffer;

	n--;
	return arr;
}
template<typename T>T* insert(T arr[], int& n, T value, int index)
{
	if (index >= n) return arr;
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++) (i < index ? buffer[i] : buffer[i + 1]) = arr[i];
	buffer[index] = value;

	delete[] arr;
	arr = buffer;

	n++;
	return arr;
}
template <typename T>T* erase(T arr[], int& n, int index)
{
	if (index >= n) return arr;
	T* buffer = new T[--n];

	for (int i = 0; i < n - 1; i++) buffer[i] = arr[i < index ? i : i + 1];

	delete[] arr;
	return buffer;
}
void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++) arr[i] = rand() % (maxRand-minRand) + minRand;
}
void FillRand(char arr[], const int n)
{
	for (int i = 0; i < n; i++) arr[i] = rand();
}
void FillRand(double arr[], const int n, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand-minRand) + minRand;
		arr[i] /= 100;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) arr[i][j] = rand() % 100;
	}
}
void FillRand(double** arr, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)arr[i][j] = double(rand() % 10000) / 100;
	}
}
void FillRand(char** arr, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++) arr[i][j] = rand();
	}
}
template<typename T>void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++) cout << *(arr + i) << tab;
	cout << endl;
}
template<typename T>void Print(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) cout << arr[i][j] << tab;
		cout << endl;
	}
	cout << endl;
}
template<typename T>T** Allocate(const int rows, const int cols)
{
	T** arr = new T* [rows];
	for (int i = 0; i < rows; i++) arr[i] = new T[cols];
	return arr;
}
template<typename T>void Clear(T** arr, const int rows)
{
	for (int i = 0; i < rows; i++) delete[] arr[i];
	delete[] arr;
}
template<typename T> T** push_row_back(T** arr,int& rows,const int cols)
{
	//создаем новый массив указателей:
	T** buffer = new T* [rows + 1];

	// Копируем адреса строк из исходного массива
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];

	//Удаляем исходный массив указателей
	delete[] arr;

	buffer[rows] = new int[cols] {};
	rows++;
	return buffer;
}
template<typename T>T** push_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1];

	for (int i = 0; i < rows; i++) buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = new int[cols] {};
	rows++;
	return buffer;
}
template <typename T>T** insert_row(T** arr, int& rows, const int cols, int row_index)
{
	if (row_index > rows) row_index = rows;
	T** buffer = new T* [rows + 1] {};

	for (int i = 0; i < rows; i++) (i < row_index ? buffer[i] : buffer[i + 1]) = arr[i];
	delete[] arr;
	buffer[row_index] = new int[cols] {};
	rows++;
	return buffer;
}
template<typename T> void push_col_back(int** arr, const int rows, int& cols)
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
template<typename T> void push_col_front(T** arr, const int rows, int& cols)
{

	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T [cols + 1] {};

		for (int j = 0; j < cols; j++) buffer[j+1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>void insert_col(T** arr, const int rows, int& cols, int col_index)
{
	if (col_index > cols) col_index = cols;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T [cols + 1] {};

		for (int j = 0; j < cols+1; j++) (j < col_index ? buffer[j] : buffer[j + 1]) = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template <typename T>T** pop_row_back(int** arr, int& rows, const int cols)
{
	T** buffer = new T* [--rows];

	for (int i = 0; i < rows; i++)buffer[i] = arr[i];

	delete[] arr[rows];
	delete[] arr;
	return buffer;
}
template <typename T>T** pop_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [--rows];

	for (int i = 0; i < rows; i++) buffer[i] = arr[i+1];
	delete[] arr;
	return buffer;
}
template<typename T>T** erase_row(T** arr, int& rows, const int cols, int row_index)
{
	if (row_index >= rows) return arr;

	T** buffer = new T* [--rows];

	for (int i = 0; i < rows; i++) buffer[i] = (i < row_index ? arr[i] : arr[i + 1]);
	delete[] arr;
	return buffer;
}
template<typename T>void pop_col_back(T** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T [cols];
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
}
template<typename T>void pop_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new int[cols-1];
		for (int j = 0; j < cols-1; j++) buffer[j] = arr[i][j+1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template<typename T>void erase_col(T** arr, const int rows, int& cols, int col_index)
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