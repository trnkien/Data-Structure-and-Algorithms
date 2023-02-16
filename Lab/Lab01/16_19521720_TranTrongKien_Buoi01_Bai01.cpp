// STT: 16
// Họ và tên: Trần Trọng Kiên
// Buổi 01 - Bài 01

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
using namespace std;

struct DonThuc
{
	float HeSo;
	int SoMu;
}; typedef struct DonThuc dt;

int luachonmenu();
void nhapmangDT(dt MangDT[], int& soluong);
void nhapDT(dt& DonThuc);
void xuatmangDT(dt MangDT[], int soluong);
void xuatDT(dt DonThuc);
void nhaptudong(dt MangDT[], int& soluong);
float giatriY(dt MangDT[], int soluong, float x);

int main()
{
	dt* MangDT = new dt[100];
	int soluong;
	int luachon;
	int flag = true;
	while (flag != false)
	{
		luachon = luachonmenu();
		switch (luachon)
		{
			case 1:
			{
				nhapmangDT(MangDT, soluong);
				break;
			}
			case 2:
			{
				nhaptudong(MangDT, soluong);
				break;
			}
			case 3:
			{
				xuatmangDT(MangDT, soluong);
				break;
			}
			case 4:
			{
				float x;
				cout << "Nhap x: ";
				cin >> x;
				nhapmangDT(MangDT, soluong);
				float y = giatriY(MangDT, soluong, x);
				cout << "y = f(x) = " << y << endl;
				break;
			}
			case 5:
			{
				cout << "Xin chao !";
				flag = false;
				break;
			}
			default:
			{
				cout << "Chon khong dung! Chon lai: " << endl;
				break;
			}
		}
	}
	delete[] MangDT;
}
// Menu
int luachonmenu()
{
	int luachon;
	cout << "=================MENU=================" << endl;
	cout << "1. Nhap cho gia tri da thuc tu ban phim." << endl;
	cout << "2. Nhap tu dong cho da thuc." << endl;
	cout << "3. xuat da thuc." << endl;
	cout << "4. Tinh gia tri y voi gia tri x duoc nhap tu ban phim." << endl;
	cout << "5. Ket thuc." << endl;
	cout << "======================================" << endl;
	cout << "Ban chon chuc nang: ";
	cin >> luachon;
	return luachon;
}
// Hàm nhập mảng
void nhapmangDT(dt MangDT[], int& soluong)
{
	cout << "Nhap so luong: ";
	cin >> soluong;
	for (int i = 0; i < soluong; i++)
	{
		cout << "Nhap don thuc thu " << i+1 << ": " << endl;
		nhapDT(MangDT[i]);
	}
}
// Hàm nhập đơn thức
void nhapDT(dt& DonThuc)
{
	cout << "Nhap he so: ";
	cin >> DonThuc.HeSo;
	cout << "Nhap so mu: ";
	cin >> DonThuc.SoMu;
}
// Hàm nhập tự động
void nhaptudong(dt MangDT[], int& soluong)
{
	cout << "Nhap so luong don thuc: ";
	cin >> soluong;
	srand(time(0));
	int SoMu = 5 + rand() % +9;
	for (int i = 0; i < soluong; i++)
	{
		MangDT[i].HeSo = 10 + rand() % 99;
		MangDT[i].SoMu = SoMu;
		SoMu--;
		if (SoMu < 0)
			SoMu = 0;
	}
}
// Hàm xuất mảng
void xuatmangDT(dt MangDT[], int soluong)
{
	cout << "y = f(x) = ";
	for (int i = 0; i < soluong; i++)
		xuatDT(MangDT[i]);
	cout << endl;
}
// Hàm xuất đơn thức
void xuatDT(dt DonThuc)
{
	if(DonThuc.HeSo < 0)
		cout << " - " << DonThuc.HeSo << "x^" << DonThuc.SoMu;
	if (DonThuc.HeSo == 0)
		return;
	if (DonThuc.HeSo > 0)
		cout << " + " << DonThuc.HeSo << "x^" << DonThuc.SoMu;
}
// Hàm tính giá trị y
float giatriY(dt MangDT[], int soluong, float x)
{
	float y = 0;
	for (int i = 0; i < soluong; i++)
	{
		if (MangDT[i].SoMu == 0)
			y += 1;
		else
		{
			if (MangDT[i].HeSo == 0)
				y += 0;
			else
				y = y + MangDT[i].HeSo * pow(x, MangDT[i].SoMu);
		}
		
	}
	return y;
}
