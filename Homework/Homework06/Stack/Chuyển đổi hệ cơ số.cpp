#include <iostream>
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
void Push(Stack& s, int x);
int Pop(Stack& s);

int main()
{
	Stack s;
	CreateStack(s);
	int n, k;
	do
	{
		cout << "Nhap so thap phan can chuyen: ";
		cin >> n;
	} while (n <= 0);
	while (n != 0)
	{
		k = n % 2;
		n = n / 2;
		Push(s, k);
	}
	cout << "So nhi phan la: ";
	while (isempty(s) == 0)
		cout << Pop(s);
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
void Push(Stack& s, int x)
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
