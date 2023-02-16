// STT: 16
// Họ và tên: Trần Trọng Kiên
// Buổi 01 - Bài 02

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
using namespace std;
#define maxn 100

int luachonmenu();
void nhapmang(int mang[], int& soluong);
void nhaptudong(int mang[], int& soluong);
void xuatmang(int mang[], int soluong);
void swap(int& a, int& b);
void sort(int mang[], int soluong);
void thongke(int mang[], int soluong);

int main()
{
	int* arrayA = new int [maxn];
	int N;
	int luachon;
	int flag = true;
	while (flag != 0)
	{
		luachon = luachonmenu();
		switch (luachon)
		{
			case 1:
			{
				nhapmang(arrayA, N);
				break;
			}
			case 2:
			{
				nhaptudong(arrayA, N);
				break;
			}
			case 3:
			{
				xuatmang(arrayA, N);
				cout << endl;
				break;
			}
			case 4: 
			{
				thongke(arrayA, N);
				cout << endl;
				break;
			}
			case 5:
			{
				cout << "Xin chao! ";
				flag = false;
				break;
			}
			default:
			{
				cout << "Chon sai! Chon lai";
				break;
			}
		}
	}
	delete[] arrayA;
}

int luachonmenu()
{
	int luachon;
	cout << "==========MENU===========" << endl;
	cout << "1. Nhap gia tri cho day arrayA tu ban phim." << endl;
	cout << "2. Nhap tu dong cac gia tri cho day A." << endl;
	cout << "3. Xuat day arrayA." << endl;
	cout << "4. Thong ke so luong cac phan tu co trong day arrayA." << endl;
	cout << "5. Ket thuc !" << endl;
	cout << "=========================" << endl;
	cout << "Lua chon cua ban: ";
	cin >> luachon;
	return luachon; 
}
// Hàm nhập mảng
void nhapmang(int mang[], int& soluong)
{
	cout << "Nhap N: ";
	cin >> soluong;
	for (int i = 0; i < soluong; i++)
	{
		cout << "Nhap so thu " << i + 1 << ": ";
		cin >> mang[i];
	}
}
// Hàm nhập tự động
void nhaptudong(int mang[], int& soluong)
{
	srand(time(0));
	soluong = 10 + rand()% 50;
	for (int i = 0; i < soluong; i++)
		mang[i] = 100 + rand() % 120;
}
// Hàm xuất mảng
void xuatmang(int mang[], int soluong)
{
	for (int i = 0; i < soluong; i++)
	{
		cout << mang[i] << "     ";
	}
}
// Hàm thống kê
void thongke(int mang[], int soluong)
{
	sort(mang, soluong);
	int cnt = 1;
	for (int i = 1; i < soluong; i++)
	{
		if (mang[i] == mang[i - 1])
			cnt++;
		else
		{
			cout << "Phan tu " << mang[i - 1] << " xuat hien " << cnt << " lan!" << endl;
			cnt = 1;
		}
	}
	cout << "Phan tu " << mang[soluong - 1] << "xuat hien " << cnt << " lan!" << endl;
}
// Hàm sắp xếp
void sort(int mang[], int soluong)
{
	for (int i = 1; i < soluong; i++)
	{
		if (mang[i] > mang[i - 1])
			swap(mang[i], mang[i - 1]);
	}
}
// Hàm thay đổi vị trí
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}