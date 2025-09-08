#include <iostream>
using namespace std;
//#define POINTERS_BASICS
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS_BASICS
	cout << "Hello Pointers!\n";
	int a = 2;			//Объявление и инициализация переменной 'а';
	int* pa = &a;		//Объявление и инициализация переменной 'а';
	cout << a << endl;	//Вывод значения переменной 'a' на экран;
	cout << &a << endl;	//Взятие адреса переменной 'a' прямо при выводе;
	cout << pa << endl; //Вывод на экран адреска переменной 'a'
	cout << *pa << endl;

	int* pb;
	int b = 3;
	pb = &b;
	cout << pb << endl;
	cout << *pb << endl;

	//int - 'int';
	//int* - Указатель на int;
#endif // POINTER_BASICS

	const int n = 5;
	int arr[n] = { 3, 5, 8, 13, 21 };
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i)<< tab;
	}
	cout << endl;
}