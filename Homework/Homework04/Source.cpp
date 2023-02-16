#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;


struct PHONG
{
	int SoPhong;
	string LoaiPhong;
	int TinhTrang;
};
struct Node
{
	int key;
	PHONG info;
	Node* pNext;
};
struct List
{
	Node* pHead;
	Node* pTail;
};
Node* getnode(int x)
{
	Node* t;
	t = new Node;
	if (t == NULL)
	{
		cout << "khong cap phat duoc";
		exit(0);
	}
	t->key = x;
	t->pNext = NULL;
	return t;
}
Node* CreateNode(PHONG& x);
void AddHead(List& l, PHONG x);
int menu();
void NhapPhongKhachSan(List& l, PHONG& x, int& n);
void XuatPhongKhachSan(List l);
void ThongKeTinhTrang(List l);
void ThongKeLoaiPhong(List l);
int DTKS(List l);
void sapxepphong(List& l);
int XoaSauQ(List& l, Node* q, int& x, PHONG a);
int XoaPtDauDs(List& l, int& x, PHONG a);
int XoaPhongX(List& l, PHONG a);
int main()
{
	List l;
	int n;
	PHONG x;
	int luachon;
	int flag = true;
	while (flag != false)
	{
		luachon = menu();
		switch (luachon)
		{
			case 1:
			{
			NhapPhongKhachSan(l, x, n);
			cout << endl;
			break;
		}
			case 2:
			{
			XuatPhongKhachSan(l);
			cout << endl;
			break;
		}
			case 3:
			{
			ThongKeTinhTrang(l);
			ThongKeLoaiPhong(l);
			cout << endl;
			break;
		}
			case 4:
			{
				cout << "Doanh thu khach san la: " << DTKS(l) << "000 vnd." << endl;
				break;
			}
			case 5:
			{
			sapxepphong(l);
			XuatPhongKhachSan(l);
			cout << endl;
			break;
		}
			case 6:
			{
			XoaPhongX(l, x);
			XuatPhongKhachSan(l);
			cout << endl;
			break;
		}
			case 7:
			{
				cout << "Xin chao!";
				flag = false;
				cout << endl;
				break;
			}
			default:
			{
				cout << "Chon sai! Chon lai: ";
				break;
			}
		}
	}
	system("pause");
	return 0;
}

int menu()
{
	int luachon;
	cout << "=============MENU=============" << endl;
	cout << "1. Nhap danh sach gom n phong." << endl;
	cout << "2. Xuat danh sach phong khach san." << endl;
	cout << "3. Thong ke so luong phong khach san." << endl;
	cout << "4. Tinh doanh thu phong khach san trong 1 ngay." << endl;
	cout << "5. Sap xep phong khach san theo thu tu tang dan." << endl;
	cout << "6. Xoa phong co so phong = x." << endl;
	cout << "7. Ket thuc! " << endl;
	cout << "===============================" << endl;
	cout << "Lua chon cua ban: " << endl;
	cin >> luachon;
	return luachon;
}
Node* CreateNode(PHONG& x)
{
	Node* p = new Node;
	if (p == NULL)
		exit(1);
	p->info = x;
	p->pNext = NULL;
	return p;
}
void CreateEmptyList(List& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
void AddHead(List& l, PHONG x)
{
	Node* p = CreateNode(x);
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = l.pHead;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void addtail(List& l, Node* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
//Câu 1
void NhapPhongKhachSan(List& l, PHONG& x, int& n)
{
	Node* p;
	l.pHead = l.pTail = NULL;
	cout << "So Phong can nhap la: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Phong " << i+1 << ": ";
		cout << "So phong: ";
		cin >> x.SoPhong;
		fflush(stdin);
		cout << "Loai Phong (A : Phong DON, B : Phong DOI): ";
		cin >> x.LoaiPhong;
		cout << "Tinh Trang (1: Da Co Khach, 0 : Trong): ";
		cin >> x.TinhTrang;
		p = CreateNode(x);
		AddHead(l, x);

	}
}
//Câu 2
void XuatPhongKhachSan(List l)
{
	int i = 1;
	Node* R = l.pHead;
	cout << "\n";
	if (R == NULL)
		cout << "\n\t Danh Sach Rong - Khong The Xuat !";
	else
	{
		cout << " Danh sach cac phong khac san la:";
		while (R != NULL)
		{
			cout << "\n ------------------------------------------";
			cout << "\n | phong khach san : " << i++;
			cout << "\n --------------";
			cout << "\n So phong la: " << R->info.SoPhong;
			cout << "\n Loai Phong: " << R->info.LoaiPhong;
			cout << "\n Tinh Trang (1: Da Co Khach, 0 : Trong): " << R->info.TinhTrang;

			R = R->pNext;
			cout << "\n ------------------------------------------";
		}
	}
}
//Câu 3
void ThongKeTinhTrang(List l)
{
	int PhongDaCoKhach = 0;
	int PhongTrong = 0;
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
	{
		if (p->info.TinhTrang == 1)
			PhongDaCoKhach++;
		else
			PhongTrong++;
	}
	cout << "\nSo phong da co khach: " << PhongDaCoKhach;
	cout << "\nSo phong trong: " << PhongTrong;
}
void ThongKeLoaiPhong(List l)
{

	int Doi = 0;
	int Don = 0;
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
	{
		if (p->info.LoaiPhong == "A")
			Don++;
		else
			Doi++;
	}
	cout << "\nSo phong don: " << Don;
	cout << "\nSo phong doi: " << Doi << endl;
}
//Câu 4
int DTKS(List l)
{
	int DoanhThu = 0;
	for (Node* i = l.pHead; i != NULL; i = i->pNext)
	{
		if (i->info.TinhTrang == 1)
		{
			if (i->info.LoaiPhong == "A")
				DoanhThu = DoanhThu + 200;
			else DoanhThu = DoanhThu + 350;
		}
	}
	return DoanhThu;
}
//Câu 5
void sapxepphong(List& l)
{
	for (Node* i = l.pHead; i != l.pTail; i = i->pNext)
		for (Node* j = i->pNext; j != NULL; j = j->pNext)
			if (i->info.SoPhong > j->info.SoPhong)
				swap(i->info, j->info);
}
//Câu 6
int XoaSauQ(List& l, Node* q, int& x, PHONG a)
{
	Node* p;
	if (q != NULL)
	{
		p = q->pNext;
		if (p != NULL)
		{
			if (p == l.pTail)
				l.pTail = q;
			q->pNext = p->pNext;
			x = p->info.SoPhong;
			delete p;
		}
		return 1;
	}
	else
		return 0;
}
int XoaPtDauDs(List& l, int& x, PHONG a)
{
	Node* p;
	if (l.pHead != NULL)
	{
		p = l.pHead;
		x = p->info.SoPhong;
		l.pHead = l.pHead->pNext;
		delete p;
		if (l.pHead == NULL)
			l.pTail = NULL;
		return 1;
	}
	return 0;
}
int XoaPhongX(List& l, PHONG a)
{
	int x;
	cout << "Nhap so phong can xoa: ";
	cin >> x;
	Node* p, * q = NULL;
	p = l.pHead;
	while ((p != NULL) && (p->info.SoPhong != x))
	{
		q = p;
		p = p->pNext;
	}
	if (p == NULL)
		return 0;
	else
	{
		if (q != NULL)
			XoaSauQ(l, q, x, a);
		else
			XoaPtDauDs(l, x, a);
	}
	return 1;
}