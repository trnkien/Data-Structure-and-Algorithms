//Tên: Trần Trọng Kiên
//STT: 16
//Buổi 03 - Bài 03
#include <iostream>
#define MAX 100
using namespace std;
struct Stack
{
	int a[MAX];
	int sl;
};

int menu();
void CreateStak(Stack& s);
bool IsEmpty(Stack s);
bool IsFull(Stack s);
void Push(Stack& s, int x);
void Pop(Stack& s, int& x);
bool Kiemtra(Stack s, Stack z, Stack x);
int endgame();
void Xuat(Stack a, Stack b, Stack c);

int main()
{
	Stack A, B, C;
	int luachon = 1;
	int flag = true;
	int Buoc = 0;
	while (flag != false)
	{
		if (luachon == -1)
			luachon = 0;
		else
			luachon = menu();
		switch (luachon)
		{
		case 0:
		{
			CreateStak(A);
			CreateStak(B);
			CreateStak(C);
			Push(A, 3);
			Push(A, 2);
			Push(A, 1);
			Xuat(A, B, C);
			break;
		}
		case 1:
		{
			int temp;
			Pop(A, temp);
			Push(B, temp);
			if (Kiemtra(A, B, C) == false)
			{
				cout << "Sai!" << endl;
				int luachon1 = endgame();
				if (luachon1 == 1)
					luachon = -1;
				else
				{
					cout << "Xin chao! " << endl;
					flag = false;
				}
				break;
			}
			else
				Xuat(A, B, C);
			Buoc++;
			cout << endl;
			cout << "************************" << endl;
			cout << "* So buoc thuc hien: " << Buoc << " *" << endl;
			cout << "************************" << endl;
			break;
		}
		case 2:
		{
			int temp;
			Pop(A, temp);
			Push(C, temp);
			if (Kiemtra(A, B, C) == false)
			{
				cout << "Sai!" << endl;
				int luachon1 = endgame();
				if (luachon1 == 1)
					luachon = -1;
				else
				{
					cout << "Xin chao! " << endl;
					flag = false;
				}
				break;
			}
			else
				Xuat(A, B, C);
			Buoc++;
			cout << endl;
			cout << "************************" << endl;
			cout << "* So buoc thuc hien: " << Buoc << " *" << endl;
			cout << "************************" << endl;
			break;
		}
		case 3:
		{
			int temp;
			Pop(B, temp);
			Push(A, temp);
			if (Kiemtra(A, B, C) == false)
			{
				cout << "Sai!" << endl;
				int luachon1 = endgame();
				if (luachon1 == 1)
					luachon = -1;
				else
				{
					cout << "Xin chao! " << endl;
					flag = false;
				}
				break;
			}
			else
				Xuat(A, B, C);
			Buoc++;
			cout << endl;
			cout << "************************" << endl;
			cout << "* So buoc thuc hien: " << Buoc << " *" << endl;
			cout << "************************" << endl;
			break;
		}
		case 4:
		{
			int temp;
			Pop(B, temp);
			Push(C, temp);
			if (Kiemtra(A, B, C) == false)
			{
				cout << "Sai!" << endl;
				int luachon1 = endgame();
				if (luachon1 == 1)
					luachon = -1;
				else
				{
					cout << "Xin chao! " << endl;
					flag = false;
				}
				break;
			}
			else
				Xuat(A, B, C);
			Buoc++;
			cout << endl;
			cout << "************************" << endl;
			cout << "* So buoc thuc hien: " << Buoc << " *" << endl;
			cout << "************************" << endl;
			break;
		}
		case 5:
		{
			int temp;
			Pop(C, temp);
			Push(A, temp);
			if (Kiemtra(A, B, C) == false)
			{
				cout << "Sai!" << endl;
				int luachon1 = endgame();
				if (luachon1 == 1)
					luachon = -1;
				else
				{
					cout << "Xin chao! " << endl;
					flag = false;
				}
				break;
			}
			else
				Xuat(A, B, C);
			Buoc++;
			cout << endl;
			cout << "************************" << endl;
			cout << "* So buoc thuc hien: " << Buoc << " *" << endl;
			cout << "************************" << endl;
			break;
		}
		case 6:
		{
			int temp;
			Pop(C, temp);
			Push(B, temp);
			if (Kiemtra(A, B, C) == false)
			{
				cout << "Sai!" << endl;
				int luachon1 = endgame();
				if (luachon1 == 1)
					luachon = -1;
				else
				{
					cout << "Xin chao! " << endl;
					flag = false;
				}
				break;
			}
			else
				Xuat(A, B, C);
			Buoc++;
			cout << endl;
			cout << "************************" << endl;
			cout << "* So buoc thuc hien: " << Buoc << " *" << endl;
			cout << "************************" << endl;
			break;
		}
		case 7:
		{
			cout << "Xin chao!" << endl;
			flag = false;
			break;
		}
		default:
		{
			cout << "Chon sai! Chon lai." << endl;
			break;
		}
		}
	}
}

int menu()
{
	cout << "========= Thap Ha Noi ===========" << endl;
	cout << "|| 0. Tao thap.                ||" << endl;
	cout << "|| Di chuyen cac thap:         || " << endl;
	cout << "|| 1. A -> B.                  ||" << endl;
	cout << "|| 2. A -> C.                  ||" << endl;
	cout << "|| 3. B -> A.                  ||" << endl;
	cout << "|| 4. B -> C.                  ||" << endl;
	cout << "|| 5. C -> A.                  ||" << endl;
	cout << "|| 6. C -> B.                  ||" << endl;
	cout << "|| 7. Thoat !                  ||" << endl;
	cout << "=================================" << endl;
	cout << "Lua chon: ";
	int luachon;
	cin >> luachon;
	return luachon;
}

void CreateStak(Stack& s)
{
	s.sl = -1;
}
bool IsEmpty(Stack s)
{
	if (s.sl == -1)
		return 1;
	return 0;
}
bool IsFull(Stack s)
{
	if (s.sl >= MAX)
		return 1;
	return 0;
}
void Push(Stack& s, int x)
{
	if (IsFull(s) == 1)
		cout << "Sai! Gioi han chi 3 tang trong 1 thap." << endl;
	else
		s.a[++s.sl] = x;
}
void Pop(Stack& s, int& x)
{
	if (IsEmpty(s) == 0)
		x = s.a[s.sl--];
}
bool Kiemtra(Stack s, Stack z, Stack x)
{
	int sld = 0;
	int sle = 0;
	int slf = 0;
	int* d = new int[sld];
	int* e = new int[sle];
	int* f = new int[slf];
	int g = s.sl;
	int k = z.sl;
	int l = x.sl;
	for (int i = 0; i <= g; i++)
	{
		Pop(s, d[i]);
		sld++;
	}
	if (sld >= 2)
		for (int i = 0; i < sld - 1; i++)
		{
			int j = i + 1;
			if (d[i] > d[j])
				return false;
		}
	for (int i = 0; i <= k; i++)
	{
		Pop(z, e[i]);
		sle++;
	}
	if (sle >= 2)
		for (int i = 0; i < sle - 1; i++)
		{
			int j = i + 1;
			if (e[i] > e[j])
				return false;
		}
	for (int i = 0; i <= l; i++)
	{
		Pop(x, f[i]);
		slf++;
	}
	if (slf >= 2)
		for (int i = 0; i < slf - 1; i++)
		{
			int j = i + 1;
			if (f[i] > f[j])
				return false;
		}
	return true;
}
int endgame()
{
	cout << "==== Game Over ======" << endl;
	cout << "|| 1. Choi lai.    ||" << endl;
	cout << "|| 2. Thoat.       ||" << endl;
	cout << "=====================" << endl;
	cout << "Lua chon: ";
	int luachon;
	cin >> luachon;
	return luachon;
}
void Xuat(Stack a, Stack b, Stack c)
{
	int sld = 0;
	int sle = 0;
	int slf = 0;
	int* d = new int[sld];
	int* e = new int[sle];
	int* f = new int[slf];
	int g = a.sl;
	int k = b.sl;
	int l = c.sl;
	for (int i = 0; i <= g; i++)
	{
		Pop(a, d[i]);
		sld++;
	}
	for (int i = 0; i <= k; i++)
	{
		Pop(b, e[i]);
		sle++;
	}
	for (int i = 0; i <= l; i++)
	{
		Pop(c, f[i]);
		slf++;
	}
	cout << endl;
	cout << "****        Thap A        ****" << endl << endl;
	cout << "  A: <    ";
	for (int i = 0; i < sld; i++)
		cout << d[i] << "     ";
	cout << "> " << endl;
	cout << "______________________________" << endl << endl;
	cout << "****        Thap B        ****" << endl << endl;
	cout << "  B: <    ";
	for (int i = 0; i < sle; i++)
		cout << e[i] << "    ";
	cout << ">." << endl;
	cout << "______________________________" << endl << endl;
	cout << "****        Thap C        ****" << endl << endl;
	cout << "  C: <    ";
	for (int i = 0; i < slf; i++)
		cout << f[i] << "    ";
	cout << ">." << endl;
	cout << "______________________________" << endl << endl;
}
