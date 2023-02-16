#include <iostream>
#include<string>
#include<stdlib.h>
using namespace std;
struct Node
{
    int info;
    Node* pNext;
};
struct Queue
{
    Node* pHead;
    Node* pTail;
};
struct Stack
{
    Node* pHead;
    Node* pTail;
};
void DeQueue(Queue& l, char& x);
void EnQueue(Queue& l, Node* p);
Node* CreateNode(int x);
void CreateEmptyQueue(Queue& l);
void Pop(Stack& l, char& x);
void Push(Stack& l, Node* p);

int main()
{
    string s;
    cout << " nhap chuoi de check Palindrome word" << endl;
    getline(cin, s);
    Queue l;
    Stack L;
    CreateEmptyQueue(l);
    for (size_t i = 0; i < s.size(); i++)
    {
        Node* p = CreateNode(s[i]);
        EnQueue(l, p);
    }
    for (size_t i = 0; i < s.size(); i++)
    {
        Node* p = CreateNode(s[i]);
        Push(L, p);
    }
    while (l.pHead != NULL && L.pHead != NULL)
    {
        Node* p = l.pHead;
        Node* p1 = l.pHead;
        char x;
        DeQueue(l, x);
        char k;
        Pop(L, k);
        if (x != k)
        {
            cout << " khong phai a Palindrome word " << endl;
            return 0;
        }
        p = p->pNext;
        p1 = p1->pNext;
    }
    cout << " day la Palindrome word" << endl;
    return 0;
}

void DeQueue(Queue& l, char& x)
{
    {
        Node* p;
        if (l.pHead != NULL)
        {
            p = l.pHead;
            x = l.pHead->info;
            l.pHead = l.pHead->pNext;
            delete p;
            if (l.pHead == NULL)
                l.pTail = NULL;
        }
    }
}
void EnQueue(Queue& l, Node* p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
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
void CreateEmptyQueue(Queue& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}
void Push(Stack& l, Node* p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void Pop(Stack& l, char& x)
{
    Node* p;
    if (l.pHead != NULL)
    {
        p = l.pHead;
        x = l.pHead->info;
        l.pHead = l.pHead->pNext;
        delete p;
        if (l.pHead == NULL)
            l.pTail = NULL;
    }
}