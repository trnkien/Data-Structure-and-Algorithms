//STT: 16
//Họ và tên: Trần Trọng Kiên
//Buổi 02 - Bài 04
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int menu();
void AutoEnterRandomArray(int mang[], int& soluong);
void PrintArray(int mang[], int soluong);
int Product(int mang[], int soluong);
int MaxestProduct(int mang[], int soluong);

int main()
{
	int arrayC[100];
	int soluong;
	int flag = true;
	int luachon;
	while (flag != false)
	{
		luachon = menu();
		switch (luachon)
		{
			case 1:
			{
				for (int i = 0; i < 100; i++)
				{
					AutoEnterRandomArray(arrayC, soluong);
					PrintArray(arrayC, soluong);
					int temp = MaxestProduct(arrayC, soluong);
					cout << "Maxest product = " << temp << endl;
					if (temp == 0 || temp < 0)
					{
						cout << "break!";
						break;
					}
				}
				cout << endl;
				break;
			}
			case 2:
			{
				cout << "ArrayC: " << endl;
				PrintArray(arrayC, soluong);
				break;
			}
			case 3:
			{
				for (int i = 0; i < 100; i++)
				{
					int temp = MaxestProduct(arrayC, soluong);
					if (temp == 0 || temp < 0)
						break;
				}
				//cout << "Tich lon nhat cua tap con: " << MaxestProduct(arrayC, soluong);
				cout << endl;
				break;
			}
			case 4:
			{
				cout << "Xin chao !" << endl << endl;
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
	cout << "===========MENU===========" << endl;
	cout << "1. Nhap gia tri tu dong cho arrayC, cac gia tri thuoc doan [-99;99], so luong phan tu thuoc doan [15;30]." << endl;
	cout << "2. Xuat mang arrayC." << endl;
	cout << "3. Tinh tich lon nhat cua tap con trong mang arrayC." << endl;
	cout << "4. Ket thuc !" << endl;
	cout << "==========================" << endl;
	cout << "Lua chon cua ban: ";
	cin >> luachon;
	return luachon;
}
void AutoEnterRandomArray(int mang[], int& soluong)
{
	srand(time(0));
	soluong = 15 + rand() % + 16;
	for (int i = 0; i < soluong; i++)
		mang[i] = -99 + rand() % + 199;
}
void PrintArray(int mang[], int soluong)
{
	int Negative = 0;
	for (int i = 0; i < soluong; i++)
		if (mang[i] < 0)
			Negative++;
	cout << Negative << endl;
	//
	long long int product = 1;
	for (int i = 0; i < soluong; i++)
	{
		cout << "arrayC[" << i + 1 << "] = " << mang[i] << endl;
		product *= mang[i];
		cout << "product = " << product << endl;
	}	
	cout << endl;
}
int Product(int mang[], int soluong) //Tích tất cả các phần tử khác 0.
{
	long long int product = 1;
	for (int i = 0; i < soluong; i++)
	{
		if (mang[i] != 0)
			product *= mang[i];
	}
	return product;
} //Tính tích tất cả các phần tử của mảng.
int MaxestProduct(int mang[], int soluong) //Tích lớn nhất.
{
	int Zero = 0, Negative = 0, Negativemaxx;
	for (int i = 0; i < soluong; i++)
	{
		if (mang[i] == 0)
			Zero++;
		if (mang[i] < 0)
		{
			Negative++;
			Negativemaxx = mang[i];
		}
	}
	for (int i = 0; i < soluong; i++) // Tìm số âm lớn nhấy
		if (mang[i] < 0 && mang[i] > Negativemaxx)
			Negativemaxx = mang[i];
	if (Zero == 0 && Negative % 2 == 0)
		return Product(mang, soluong);
	else
	{
		if (Zero == soluong || (Negative == 1 && Zero == soluong - 1))
			return 0;
		else if (Negative % 2 == 1)
		{
			cout << 3 << ", Negativemaxx = " << Negativemaxx << endl;
			int product = Product(mang, soluong);
			cout << "product = " << product << endl;
			product /= Negativemaxx;
			return product;
		}
	}
}