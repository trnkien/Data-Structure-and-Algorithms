#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node* pNext;
};
typedef Node* pNode;

void init(pNode& s);
int isEmpty(pNode s);
void Push(pNode& s, int x);
int Pop(pNode& s);

int main()
{
    int n, x;
    pNode s;
    init(s);
    cout << "Nhap so node can dao: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap gia tri thu " << i + 1 << ": ";
        cin >> x;
        Push(s, x);
    }
    cout << "Day dao nguoc lai la: ";
    while (isEmpty(s) == 0)
        cout << Pop(s) << " ";
}

void init(pNode& s)
{
    s = NULL;
}
int isEmpty(pNode s)
{
    return (s == NULL);
}
void Push(pNode& s, int x)
{
    pNode p = new Node;
    p->info = x;
    p->pNext = s;
    s = p;
}
int Pop(pNode& s)
{
    int x;
    pNode p;
    x = s->info;
    p = s;
    s = s->pNext;
    delete p;
    return x;
}
