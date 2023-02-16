#include <iostream>
using namespace std;

struct Node {
	int info;
	Node* pNext;
};
struct List {
	Node* pHead;
	Node* pTail;
};

Node* CreateNode(int x);
int SearchNode(List l);
void CreateEmptyList(List& l);
void AddHead(List& l, Node* p);
void InsertAfterQ(List& l, Node* p, Node* q);
void AddTail(List& l, Node* p);
void InputList(List& l);
void Printlist(List l);

int main()
{
	List l;
	CreateEmptyList(l);
	InputList(l);
	Printlist(l);
	if (SearchNode(l) == 0)
		cout << "Khong tim thay";
	else
		cout << "Tim thay";
}
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
void AddHead(List& l, Node* p)
{
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
void InsertAfterQ(List& l, Node* p, Node* q)
{
	if (q != NULL)
	{
		p->pNext = q-> pNext;
		q->pNext = p;
		if (l.pTail == q)
			l.pTail = q;
	}
	else AddHead(l, q);
}
void Printlist(List l)
{
	for(Node * p = l.pHead; p != NULL; p = p -> pNext)
	{
		cout << p->info << "\t";
	}
}

int SearchNode(List l)
{
	int x;
	cout << "Nhap x: ";
	cin >> x;
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
	{
		if (p->info == x)
			return 1;
	}
	return 0;
}
void AddTail(List& l, Node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail -> pNext = p;
		l.pTail = p;
	}
}
void InputList(List& l)
{
	int n;
	cout << "nhap n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		Node* p = new Node;
		p = CreateNode(x);
		AddHead(l, p);
	}
}