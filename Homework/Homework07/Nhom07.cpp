#include <iostream>

struct Node
{
	int info;
	Node* pNext;
};
struct List
{
	Node* pHead;
	Node* pTail;
};

using namespace std;

Node* CreateNode(int x);
void CreateEmptyList(List& l);
void AddHead(List& l, int x);
void AddTail(List& l, Node* p);
void InputList(List& l);
void Outputlist(List l);

int menu();
void Nhap_Mang(int a[], int& n);
void Xuat_Mang(int a[], int n);
int LinearSearch(int a[], int n, int x);
int linearSearch(List l, int x);
int LinearSearchAdvanced(int A[], int n, int x);
Node* linearSearchAdvanced(List A, int x);
int nhiphan(int a[], int left, int right, int x);
int NoiSuy(int A[], int n, int x);

int main()
{

	int flag = true;
	while(flag != false)
	{
		int luachon = menu();
		switch (luachon)
		{
			case 1:
			{
				int option;
				cout << "LUA CHON: " << endl;
				cout << "1. mang." << endl;
				cout << "2. Danh sach lien ket don." << endl;
				cin >> option;
				switch (option)
				{
					case 1:
					{
						int a[100];
						int n, x;
						Nhap_Mang(a, n);
						cout << "Mang 1 chieu la: ";
						Xuat_Mang(a, n);
						cout << "Nhap gia tri can tim: ";
						cin >> x;
						cout << "Vi tri gia tri can tim: ";
						cout << "a[" << LinearSearch(a, n, x) + 1 << "]" << endl;
						break;
					}
					case 2:
					{
						List l;
						int x;
						CreateEmptyList(l);
						InputList(l);
						cout << "Danh sach lien ket la: ";
						Outputlist(l);
						cout << "\nNhap gia tri X can tim: ";
						cin >> x;
						cout << linearSearch(l, x) << endl;
						break;
					}
				}
				break;
			}
			case 2:
			{
				int option;
				cout << "LUA CHON: " << endl;
				cout << "1. mang." << endl;
				cout << "2. Danh sach lien ket don." << endl;
				cin >> option;
				switch (option)
				{
					case 1:
					{
						int a[100];
						int n, x;
						Nhap_Mang(a, n);
						cout << "Mang mot chieu la: ";
						Xuat_Mang(a, n);
						cout << "Nhap gia tri can tim: ";
						cin >> x;
						cout << "Vi tri gia tri can tim: ";
						cout << "a[" << LinearSearchAdvanced(a, n, x) + 1 << "]";
						break;
					}
					case 2:
					{
						List l;
						int x;
						CreateEmptyList(l);
						InputList(l);
						cout << "Danh sach lien ket la: ";
						Outputlist(l);
						cout << "\nNhap gia tri X can tim: ";
						cin >> x;
						Node* p;
						p = linearSearchAdvanced(l, x);
						if (p == NULL)
							cout << "Khong tim thay!" << endl;
						else
							cout << "Dia chi gia tri can tim: " << p << endl;
						break;
					}
				}
				break;
			}
			case 3:
			{
				int a[100];
				int n;
				Nhap_Mang(a, n);
				cout << "Mang: " << endl;
				Xuat_Mang(a, n);
				int x;
				cout << "Nhap so can tim: ";
				cin >> x;
				if (int vitri = nhiphan(a, a[0], a[n-1], x))
					cout << "Tim thay tai vi tri: " << vitri + 1 << endl;
				else cout << "Khong tim thay" << endl;
				break;
			}
			case 4:
			{
				int a[100];
				int n;
				Nhap_Mang(a, n);
				cout << "Mang: " << endl;
				Xuat_Mang(a, n);
				int x;
				cout << "Nhap so can tim: ";
				cin >> x;
				int temp = NoiSuy(a, n, x);
				if (temp == -1)
					cout << "Khong tim thay!" << endl;
				else
					cout << "Tim thay o vi tri " << temp + 1 << endl;
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
	cout << "============ MENU =============" << endl;
	cout << "1. Tim kiem tuyen tinh." << endl;
	cout << "2. Tim kiem tuyen tinh cai tien." << endl;
	cout << "3. Tim kiem nhi phan." << endl;
	cout << "4. Tim kiem noi suy." << endl;
	cout << "5. Ket thuc !" << endl;
	cout << "===============================" << endl;
	cout << "Lua chon cua ban: ";
	cin >> luachon;
	return luachon;
}

//Tạo dslk đơn.
Node* CreateNode(int x)
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
int Empty(List& l)
{
	if (l.pHead == NULL)
		return 1;
	return 0;
}
void AddHead(List& l, int x)
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
void AddTail(List& l, Node* p)
{
	if (l.pHead == NULL)
	{

		l.pHead = p;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void InputList(List& l)
{
	int n;
	cout << "Nhap so luong node trong danh sach: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cout << "Node thu " << i + 1 << ": ";
		cin >> x;
		Node* p = new Node;
		p = CreateNode(x);
		AddHead(l, x);
	}
}
void Outputlist(List l)
{
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
	{
		cout << p->info << "\t";
	}
}

//Tìm kiếm tuyến tính.
//Mảng.
void Nhap_Mang(int a[], int& n)
{
	do {
		cout << "Nhap vao so phan tu cua mang: ";
		cin >> n;
	} while ((n < 0) || (n > 100));
	for (int i = 0; i < n; i++)
	{
		cout << "Phan tu thu " << i + 1 << " a[" << i << "]: ";
		cin >> a[i];
	}
}
void Xuat_Mang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
}
int LinearSearch(int a[], int n, int x)
{
	int i = 0;
	while (i < n)
	{
		if (a[i] == x)
			return i;
		i++;
	}
	return -1;
}
//Danh sách liên kết đơn.
int linearSearch(List l, int x)
{
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
	{
		if (p->info == x)
			cout << "\nGia tri can tim co trong danh sach lien ket, dia chi node: " << p;
	}
	return 0;
}

//Tìm kiếm tuyến tính cải tiến.
//Mảng.
int LinearSearchAdvanced(int A[], int n, int x)
{
	int i = 0; A[n] = x;//A có hơn n phần tử
	while (A[i] != x)
		i++;
	if (i < n)
		return i;
	else
		return -1;
}
//Danh sách liên kết đơn.
Node* linearSearchAdvanced(List A, int x)
{
	Node* p = A.pHead, * t = new Node;
	t = CreateNode(x);
	if (!t) throw "out of memory";
	AddTail(A, t);
	while (p->info != x)
	{
		p = p->pNext;
	}
	if (p == A.pTail)
		return NULL;
	else
		return p;
}

//Tìm kiếm nhị phân.
int nhiphan(int a[], int left, int right, int x)
{
	int m;
	if (left > right)
		return 0;
	m = (left + right) / 2;
	if (a[m] == x)
		return m;
	if (x < a[m])
		return nhiphan(a, left, m - 1, x);
	return nhiphan(a, m + 1, right, x);
}
//Tìm kiếm nội suy.
int NoiSuy(int A[], int n, int x)
{
	int l = 0, r = n - 1;
	while (l <= r)
	{
		int m = l + (r - l) * (x - A[l]) / (A[r] - A[l]);
		if (x == A[m])
			return m;
		if (x < A[m])
			r = m - 1;
		else
			l = m + 1;
	}
	return -1;
}