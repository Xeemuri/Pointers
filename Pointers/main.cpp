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
	int a = 2;			//���������� � ������������� ���������� '�';
	int* pa = &a;		//���������� � ������������� ���������� '�';
	cout << a << endl;	//����� �������� ���������� 'a' �� �����;
	cout << &a << endl;	//������ ������ ���������� 'a' ����� ��� ������;
	cout << pa << endl; //����� �� ����� ������� ���������� 'a'
	cout << *pa << endl;

	int* pb;
	int b = 3;
	pb = &b;
	cout << pb << endl;
	cout << *pb << endl;

	//int - 'int';
	//int* - ��������� �� int;
#endif // POINTER_BASICS

	const int n = 5;
	int arr[n] = { 3, 5, 8, 13, 21 };
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i)<< tab;
	}
	cout << endl;
}