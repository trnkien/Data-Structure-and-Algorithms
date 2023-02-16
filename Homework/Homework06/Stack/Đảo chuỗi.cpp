#include<iostream>
#include<string>
#define MAX 100
using namespace std;

struct Node
{
    char info;
    Node* pNext;
};
typedef Node* pNode;

void init(pNode& s);
int isEmpty(pNode s);
void Push(pNode& s, char x);
char Pop(pNode& s);

int main()
{
    pNode s;
    init(s);
    string str;
    init(s);
    cout << " Nhap xau ki tu: ";
    getline(cin, str);
    cin.ignore();
    for (int i = 0; i < str.size(); i++)
        Push(s, str[i]);
    cout << " Xau da dao nguoc la: ";
    while (isEmpty(s) == 0)
        cout << Pop(s);
}

void init(pNode& s)
{
    s = NULL;
}
int isEmpty(pNode s)
{
    return (s == NULL);
}
void Push(pNode& s, char x)
{
    pNode p = new Node;
    p->info = x;
    p->pNext = s;
    s = p;
}
char Pop(pNode& s)
{
    int x;
    pNode p;
    x = s->info;
    p = s;
    s = s->pNext;
    delete p;
    return x;
}

