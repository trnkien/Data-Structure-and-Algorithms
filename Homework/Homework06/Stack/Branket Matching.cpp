#include <iostream>
#include <string>
#define MAX 100
using namespace std;

struct Stack
{
	int a[MAX];
	int t;
};

void CreateStack(Stack& s);
bool isempty(Stack s);
bool isfull(Stack s);
void Push(Stack& s, char x);
int Pop(Stack& s);

int main()
{
	Stack s;
	CreateStack(s);
	char a[100];
	cout << "Nhap bieu thuc: ";
	cin.ignore();
	gets_s(a);
	for (int i = 0; i < 100; i++)
	{
		if (a[i] == '(')
			Push(s, a[i]);
		if (a[i] == ')')
		{
			Pop(s);
			if (isempty(s) == 0)
			{
				cout << "Khong hop le !";
				return 0;
			}
		}
	}
	cout << "Hop le!";
	return 0;
}

void CreateStack(Stack& s)
{
	s.t = -1;
}
bool isempty(Stack s)
{
	if (s.t == -1)
		return 1;
	return 0;
}
bool isfull(Stack s)
{
	if (s.t >= MAX)
		return 1;
	return 0;
}
void Push(Stack& s, char x)
{
	if (isfull(s))
		cout << " Ngan xep day.";
	else
	{
		s.t++;
		s.a[s.t] = x;
	}
}
int Pop(Stack& s)
{
	if (isempty(s))
	{
		cout << "Ngan xep rong.";
		return -1;
	}
	else
		return s.a[s.t--];
}
