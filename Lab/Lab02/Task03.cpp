//STT: 16
//Họ và tên: Trần Trọng Kiên
//Buổi 02 - Bài 03
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int menu();
void AutoEnterArray(int array[], int& soluong);
void PrintArray(int array[], int soluong);
void AutoEnterArrayIncrease(int array[], int& soluong);
int SearchBinary(int array[], int soluong, int x);
void SortAtoZ(int array[], int soluong);

int main()
{
	int array[100];
	int soluong;
	int luachon;
	int flag = true;
	while (flag != false)
	{
		luachon = menu();
		switch (luachon)
		{
			case 1:
			{
				AutoEnterArray(array, soluong);
				cout << endl;
				break;
			}
			case 2:
			{
				AutoEnterArrayIncrease(array, soluong);
				cout << endl;
				break;
			}
			case 3:
			{
				PrintArray(array, soluong);
				cout << endl;
				break;
			}
			case 4:
			{
				SortAtoZ(array, soluong);
				int x;
				cout << "Nhap phan tu can tim: ";
				cin >> x;
				int temp = SearchBinary(array, soluong, x);
				if (temp == -1)
					cout << "Khong tim thay!";
				else
					cout << temp;
				cout << endl;
				break;
			}
			case 5:
			{
				cout << "Xin chao!" << endl;
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
	return 0;
}

int menu()
{
	int luachon;
	cout << "==========MENU=========" << endl;
	cout << "1. Nhap gia tri tu dong cho array A, cac gia tri thuoc doan [555;999], so luong phan tu thuoc doan [15;30]." << endl;
	cout << "2. Nhap tu dong cac gia tri tang dan cho array A, gia tri thuoc doan [10;99]." << endl;
	cout << "3. Xuat mang array A." << endl;
	cout << "4. Tim mot phan tu X (Nhap tu ban phim)." << endl;
	cout << "5. Ket thuc !" << endl;
	cout << "=======================" << endl;
	cout << "Chon chuc nang: ";
	cin >> luachon;
	return luachon;
}
void AutoEnterArray(int array[], int& soluong)
{
	srand(time(0));
	soluong = 15 + rand() % +16;
	for (int i = 0; i < soluong; i++)
		array[i] = 555 + rand() % +445;
}
void PrintArray(int array[], int soluong)
{
	for (int i = 0; i < soluong; i++)
	{
		if (array[i] < 10 && array[i] > 99)
		{
			cout << "Mistake at arry[" << i + 1 << "] = " << array[i] << endl;
			return;
		}
		cout << "array[" << i + 1 << "] = " << array[i] << endl;
	}
}
void AutoEnterArrayIncrease(int array[], int& soluong)
{
	srand(time(0));
	soluong = 30 + rand()% + 21;
	int x = 10, y = 90;
	for (int i = 0; i < soluong && array[i] <= y ; i++)
		array[i] = rand() % x + y;
}
int SearchBinary(int array[], int soluong, int x)
{
	SortAtoZ(array, soluong);
	int left = 0, right = soluong - 1, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (x == array[mid])
			return mid;
		if (x < array[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}
void SortAtoZ(int array[], int soluong)
{
	for (int i = 0; i < soluong; i++)
		for (int j = i+1; j < soluong - 1; j++)
			if (array[i] > array[j])
				swap(array[i], array[j]);
}
