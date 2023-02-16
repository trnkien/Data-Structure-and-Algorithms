//STT: 16
//Họ và tên: Trần Trọng Kiên
//Buổi 03 - Bài 02

#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
using namespace std;

struct Data
{
	string Name;
	float GPA;
};

struct DNode
{
	Data info;
	DNode* Next;
};

struct DList
{
	DNode* Head;
	DNode* Tail;
};

int menu();
DNode* CreateNode(Data& a);
void CreateEmptyList(DList& l);
void AddHead(DList& l, DNode* p);
void AddTail(DList& l, DNode* p);
int menucase1();
void EntryInfo(Data& a);
void InputList(DList& l);
void PrintInfo(Data a);
void OutputList(DList l);
void AutoInputList(DList& l);
void Sort(DList& l);
void Search(DList l, Data x);
int DeleteAfterQ(DList& l, DNode* q, Data& a);
int DeleteHead(DList& l, Data& a);
int Delete(DList& l);
int Update(DList& l);

int main()
{
	DList l;
	CreateEmptyList(l);
	int flag = true;
	int luachon;
	while (flag != false)
	{
		luachon = menu();
		switch (luachon)
		{
			case 1:
			{
				int flag = true;
				while (flag != false)
				{
					int luachon1 = menucase1();
					switch (luachon1)
					{
						case 1:
						{
							InputList(l);
							flag = false;
							break;
						}
						case 2:
						{
							AutoInputList(l);
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
				break;
			}
			case 2:
			{
				Sort(l);
				break;
			}
			case 3:
			{
				Data x;
				Search(l, x);
				break;
			}
			case 4:
			{
				int temp = Delete(l);
				if (temp == 1)
					cout << "Da xoa!" << endl;
				else
					cout << "Khong tim thay sinh vien can xoa." << endl;
				break;
			}
			case 5:
			{
				int temp = Update(l);
				if (temp == 1)
					cout << "Da cap nhat!" << endl;
				else
					cout << "Khong tim thay sinh vien can cap nhat." << endl;
				break;
			}
			case 6:
			{
				OutputList(l);
				break;
			}
			case 7:
			{
				cout << endl << "Xin chao!" << endl;
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
}

int menu()
{
	int luachon;
	cout << "* ==================  MENU  =================== *" << endl;
	cout << "* 1. Tao danh sach sinh vien.                   *" << endl;
	cout << "* 2. Sap xep danh sach sinh vien theo diem GPA. *" << endl;
	cout << "* 3. Tim kiem sinh vien theo ten, GPA.          *" << endl;
	cout << "* 4. Xoa sinh vien trong danh sach.             *" << endl;
	cout << "* 5. Cap nhat thong tin sinh vien.              *" << endl;
	cout << "* 6. In danh sach sinh vien len man hinh.       *" << endl;
	cout << "* 7. Ket thuc!                                  *" << endl;
	cout << "* ============================================= *" << endl;
	cout << "Lua chon cua ban: ";
	cin >> luachon;
	return luachon;
}
DNode* CreateNode(Data& a) // Hàm tạo 1 nốt trong danh sách.
{
	DNode* p = new DNode;
	if (p == NULL)
		return NULL;
	p->info = a;
	p->Next = NULL;
	return p;
}
void AddHead(DList& l, DNode* p) // Hàm thêm 1 nốt vào đầu danh sách.
{
	if (l.Head == NULL)
		l.Head = l.Tail = p;
	else
	{
		p->Next = l.Head;
		l.Head = p;
	}
}
void AddTail(DList& l, DNode* p) // Hàm thêm 1 nốt vào cuối danh sách.
{
	if (l.Head == NULL)
		l.Head = l.Tail = p;
	else
	{
		l.Tail->Next = p;
		l.Tail = p;
	}
}
//Câu 1
int menucase1()
{
	int luachon;
	cout << "CAC PHUONG THUC NHAP:" << endl;
	cout << "1. Nhap thu cong." << endl;
	cout << "2. Nhap tu dong." << endl;
	cout << "Lua chon: ";
	cin >> luachon;
	return luachon;
}
void CreateEmptyList(DList& l) // Hàm tạo danh sách.
{
	l.Head = NULL;
	l.Tail = NULL;
}
void EntryInfo(Data& a) // Hàm nhập thông tin sinh viên.
{
	cin.ignore();
	cout << "Nhap ho ten: ";
	getline(cin, a.Name);
	cout << "Nhap diem GPA: ";
	cin >> a.GPA;
}
void InputList(DList& l) // Hàm nhập danh sách sinh viên.
{
	int soluong;
	cout << "Nhap so luong sinh vien: ";
	cin >> soluong;
	while (soluong < 1)
	{
		cout << "So luong >= 1. Nhap lai: ";
		cin >> soluong;
	}
	for (int i = 0; i < soluong; i++)
	{
		cout << "Nhap thong tin sinh vien thu " << i + 1 << ": " << endl;
		Data x;
		EntryInfo(x);
		DNode* p = new DNode;
		p = CreateNode(x);
		AddHead(l,p);
	}
}
void AutoInputList(DList& l) // Hàm random thông tin sinh viên.
{
	srand(time(NULL));
	int soluong = 10 + rand() % +41;
	for (int i = 0; i < soluong; i++)
	{
		Data x;
		string ho[] = { "Nguyen","Tran","Ly","Le","Ho","Ngo","Phan" };
		string lot[] = { "Thanh","Trong","Nhat","Ngoc","Tan","Van","Thu" };
		string ten[] = { "Nguyen","Tuan","Khoa","Kien","My","Thanh","Anh" };
		x.Name.append(ho[rand() % +3]);
		x.Name.append(" ");
		x.Name.append(lot[rand() % +3]);
		x.Name.append(" ");
		x.Name.append(ten[rand() % +3]);
		x.GPA = 0 + rand() % +10;
		DNode* p = new DNode;
		p = CreateNode(x);
		AddHead(l, p);
	}
}
//Câu 2
void Sort(DList&l)
{
	for (DNode* p = l.Head; p != l.Tail; p = p->Next)
		for (DNode* k = l.Head; k != NULL; k = k->Next)
			if (p->info.GPA > k->info.GPA)
				swap(p->info, k->info);
}
//Câu 3
void Search(DList l, Data x) // Hàm tìm kiếm thông tin sinh viên.
{
	int luachon;
	cout << "CAC PHUONG THUC TIM KIEM: " << endl;
	cout << "1. Tim kiem theo ten." << endl;
	cout << "2. Tim kiem theo diem GPA." << endl;
	cout << "3. Tim kiem thoe ten va diem GPA." << endl;
	cout << "Lua chon: ";
	cin >> luachon;
	while (luachon != 1 && luachon != 2 && luachon != 3)
	{
		cout << "Chon sai! Chon lai: ";
		cin >> luachon;
	}
	switch (luachon)
	{
		case 1: // Tìm kiếm theo tên.
		{
			cout << "Nhap ten sinh vien can tim: ";
			cin.ignore();
			getline(cin, x.Name);
			for (DNode* p = l.Head; p != NULL; p = p->Next)
				if (p->info.Name == x.Name)
				{
					PrintInfo(p->info);
					cout << "* ============================= | ===== *" << endl << endl;
				}
			cout << "Khong tim thay!" << endl;
			break;
		}
		case 2: // Tìm kiếm theo điểm GPA.
		{
			cout << "Nhap diem GPA: ";
			cin >> x.GPA;
			for (DNode* p = l.Head; p != NULL; p = p->Next)
				if (p->info.GPA == x.GPA)
				{
					PrintInfo(p->info);
					cout << "* ============================= | ===== *" << endl << endl;
				}
			cout << "Khong tim thay!" << endl;
			break;
		}
		case 3: // Tìm kiếm theo tên và điểm GPA.
		{
			EntryInfo(x);
			for (DNode* p = l.Head; p != NULL; p = p->Next)
				if (p->info.Name == x.Name && p->info.GPA == x.GPA)
				{
					PrintInfo(p->info);
					cout << "* ============================= | ===== *" << endl << endl;
				}
			cout << "Khong tim thay!" << endl;
			break;
		}
	}
}
//Câu 4
int DeleteAfterQ(DList& l, DNode* q, Data& a)
{
	DNode* p;
	if (q != NULL)
	{
		p = q->Next;
		if (p != NULL)
		{
			if (p == l.Tail)
				l.Tail = q;
			q->Next = p->Next;
			a = p->info;
			delete p;
		}
		return 1;
	}
	else
		return 0;
}
int DeleteHead(DList& l, Data& a)
{
	DNode* p;
	if (l.Head != NULL)
	{
		p = l.Head;
		a = p->info;
		l.Head = l.Head->Next;
		delete p;
		if (l.Head == NULL)
			l.Tail = NULL;
		return 1;
	}
	return 0;
}
int Delete(DList& l)
{
	Data x;
	cout << "Nhap thong tin sinh vien can xoa: " << endl;
	EntryInfo(x);
	DNode* p, * q = NULL;
	p = l.Head;
	while ((p != NULL) && (p->info.Name != x.Name && x.GPA != p->info.GPA))
	{
		q = p;
		p = p->Next;
	}
	if (p == NULL)
		return 0;
	else
	{
		if (q != NULL)
			DeleteAfterQ(l, q, x);
		else
			DeleteHead(l, x);
	}
	return 1;
}
//Câu 5
int Update(DList& l)
{
	Data x;
	cout << "Nhap thong tin sinh vien can cap nhat: ";
	EntryInfo(x);
	for (DNode* p = l.Head; p != NULL; p = p->Next)
		if (x.Name == p->info.Name && x.GPA == p->info.GPA)
		{
			EntryInfo(p->info);
			return 1;
		}
	return 0;
}
//Câu 6
void PrintInfo(Data a) // Hàm in thông tin sinh viên.
{
	int size, space;
	cout << "* ============================= | ===== *" << endl;
	size = a.Name.size();
	if (size < 29)
	{
		space = 29 - size;
		cout << "* " << a.Name;
		for (int i = 0; i < space; i++)
			cout << " ";
		cout << " | ";
	}
	else
		cout << " | ";
	cout << "  " << a.GPA << "   *" << endl;
}
void OutputList(DList l) // Hàm in danh sách sinh viên.
{
	cout << "Danh sach sinh vien: " << endl;
	for (DNode* p = l.Head; p != NULL; p = p->Next)
		PrintInfo(p->info);
	cout << "* ============================= | ===== *" << endl << endl;
}
