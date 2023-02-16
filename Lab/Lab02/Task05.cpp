//STT: 16
//Họ và tên: Trần Trọng Kiên
//Buổi 02 - Bài 05
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int menu();
int fibonacci(int n);
void EnterArrayFibo(int arr[], int soluong);
void PrintFibonacci(int arr[], int n);
int ValueFibonacci(int arr[], int soluong, int x);

int main()
{
	int soluong;
	int finacci[50];
	int flag = true;
	int luachon;
	while (flag != false)
	{
		luachon = menu();
		switch (luachon)
		{
			case 1:
			{
				srand(time(NULL));
				soluong = 10 + rand() % +41;
				EnterArrayFibo(finacci, soluong);
				break;
			}
			case 2:
			{
				PrintFibonacci(finacci, soluong);
				cout << endl;
				break;
			}
			case 3:
			{
				int x;
				cout << "Nhap vi tri can xuat: ";
				cin >> x;
				int temp = ValueFibonacci(finacci, soluong, x);
				if (temp == -1)
					cout << "Khong tim thay!" << endl;
				else
					cout << "f(" << x << ") = " << temp << endl;
				break;
			}
			case 4:
			{
				cout << "Xin chao! " << endl;
				flag = false;
				break;
			}
			default:
			{
				cout << "Chon sai! Chon lai: ";
				break;
			}
		}
	}
}

int menu()
{
	int luachon;
	cout << "=========MENU===========" << endl;
	cout << "1. Nhap tu dong cac gia tri cho day so Fibonancci." << endl;
	cout << "2. Xuat day Finaci." << endl;
	cout << "3. Xuat gia tri tu 1 vi tri trong day finaci." << endl;
	cout << "4. Ket thuc !" << endl;
	cout << "========================" << endl;
	cout << "Lua chon cua ban: ";
	cin >> luachon;
	return luachon;
}
int fibonacci(int n)
{
	int Fn, Fn1, Fn2;
	Fn = Fn1 = Fn2 = 1;
	if (n < 0)
		return -1;
	else if (n == 0 || n == 1)
		return n;
	else
		for (int i = 2; i < n; i++)
		{
			Fn = Fn1 + Fn2;
			Fn2 = Fn1;
			Fn1 = Fn;
		}
	return Fn;
}
void EnterArrayFibo(int arr[], int soluong)
{
	for (int i = 0; i < soluong; i++)
		arr[i] = fibonacci(i);
}
void PrintFibonacci(int arr[], int n)
{
	cout << "Fibonacci: " << endl;
	for (int i = 0; i < n; i++)
		cout << "f(" << i + 1 << ") = " << fibonacci(i) << endl;
}
int ValueFibonacci(int arr[], int soluong, int x)
{
	for (int i = 0; i < soluong; i++)
		if (x == i)
			return fibonacci(x-1);
	return -1;
}