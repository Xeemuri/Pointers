#include <iostream>
using namespace std;
#define DYNAMIC_MEMORY_2
//#define DYNAMIC_MEMORY_1
#define tab "\t";

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
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
template <typename T>void Clear(T** arr, const int rows);

template <typename T>T** push_row_back(T** arr, int& rows, const int cols);
template <typename T>T** push_row_front(T** arr, int& rows, const int cols);
template <typename T>T** insert_row(T** arr, int& rows, const int cols, int row_index);

template <typename T>T** pop_row_back(T** arr, int& rows, const int cols);
template <typename T>T** pop_row_front(T** arr, int& rows, const int cols);
template <typename T>T** erase_row(T** arr, int& rows, const int cols, int row_index);

template <typename T>void push_col_back(T** arr, const int rows, int& cols);
template <typename T>void push_col_front(T** arr, const int rows, int& cols);
template <typename T>void insert_col(T** arr, const int rows, int& cols, int col_index);

template <typename T>void pop_col_back(T** arr, const int rows, int& cols);
template <typename T>void pop_col_front(T** arr, const int rows, int& cols);
template <typename T>void erase_col(T** arr, const int rows, int& cols, int col_index);
void main()
{
	setlocale(LC_ALL, "");
	typedef double DataType;

#ifdef DYNAMIC_MEMORY_1
	cout << "DynamicMemory" << endl;
	int n = 5;
	cout << "Введите размер массива: "; cin >> n;

	DataType* arr = new DataType[n];

	FillRand(arr, n);
	Print(arr, n);

	DataType value;	//добавляемое значение
	cout << "Введите добавляемое значение: "; cin >> value;

	arr = push_back(arr, n, value);

	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	Print(arr = pop_back(arr, n), n);
	Print(arr = pop_front(arr, n), n);
	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	Print(arr = erase(arr, n, index), n);

	delete[] arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int rows;
	int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	double** arr = Allocate<double>(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);

	arr = push_row_front(arr, rows, cols);
	FillRand(arr[0], cols, 100, 1000);
	Print(arr, rows, cols);

	int index;
	cout << "Введите индекс добавляемой строки: "; cin >> index;
	arr = insert_row(arr, rows, cols,index);
	Print(arr, rows, cols);

	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	
	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите индекс добавляемого столбца: "; cin >> index;
	insert_col(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << "Введите индекс удаляемой строки: "; cin >> index;
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << "Введите индекс удаляемого столбца: "; cin >> index;
	erase_col(arr, rows, cols, index);
	Print(arr, rows, cols);

	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	Clear(arr, rows);

#endif // DYNAMIC_MEMORY_2
}


void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++) arr[i] = rand() % (maxRand - minRand) + minRand;
}
void FillRand(double arr[], const int n, int minRand, int maxRand)
{
	minRand, maxRand *= 100;
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
		arr[i] /= 100;
	}
}
void FillRand(char arr[], const int n)
{
	for (int i = 0; i < n; i++) arr[i] = rand();
}

void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) arr[i][j] = rand() % 100;
}
void FillRand(double** arr, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++) for (int j = 0; j < COLS; j++)arr[i][j] = double(rand() % 10000) / 100;
}
void FillRand(char** arr, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++) for (int j = 0; j < COLS; j++) arr[i][j] = rand();
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
	return buffer;
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
	for (int i = 0; i < n; i++) buffer[i] = arr[i < index ? i : i + 1];
	delete[] arr;
	return buffer;
}

template<typename T>T** Allocate(const int rows, const int cols)
{
	T** arr = new T * [rows];
	for (int i = 0; i < rows; i++) arr[i] = new T[cols];
	return arr;
}
template<typename T>void Clear(T** arr, const int rows)
{
	for (int i = 0; i < rows; i++) delete[] arr[i];
	delete[] arr;
}

template<typename T> T** push_row_back(T** arr, int& rows, const int cols)
{
	return push_back(arr, rows, new T[cols]{});
}
template<typename T>T** push_row_front(T** arr, int& rows, const int cols)
{
	return push_front(arr, rows, new T[cols]{});
}
template <typename T>T** insert_row(T** arr, int& rows, const int cols, int row_index)
{
	return insert(arr, rows, new T[cols]{}, row_index);
}

template<typename T> void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = push_back(arr[i], cols, T());
		cols--;
	}
	cols++; //T() - значение по уммолчанию для шаблоннго типа
}
template<typename T> void push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = push_front(arr[i], cols, T());
		cols--;
	}
	cols++;
}
template<typename T>void insert_col(T** arr, const int rows, int& cols, int col_index)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = insert(arr[i], cols, T(), col_index);
		cols--;
	}
	cols++;
}

template <typename T>T** pop_row_back(T** arr, int& rows, const int cols)
{
	return pop_back(arr, rows);
	delete[] arr[rows - 1];
}
template <typename T>T** pop_row_front(T** arr, int& rows, const int cols)
{
	return pop_front(arr,rows);
	delete[] arr[0];
}
template<typename T>T** erase_row(T** arr, int& rows, const int cols, int row_index)
{
	return erase(arr, rows, row_index);
	delete[] arr[row_index];
}
template<typename T>void pop_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = pop_back(arr[i], cols);
		cols++;
	}
	cols--;
}
template<typename T>void pop_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = pop_front(arr[i], cols);
		cols++;
	}
	cols--;
}
template<typename T>void erase_col(T** arr, const int rows, int& cols, int col_index)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = erase(arr[i], cols, col_index);
		cols++;
	}
	cols--;
}