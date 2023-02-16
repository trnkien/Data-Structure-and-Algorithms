#include <iostream>
using namespace std;
struct DNode
{
    int info;
    DNode* next;
    DNode* pre;
};

struct DList
{
    DNode* Head;
    DNode* Tail;
};

void CreateEmptyDList(DList& l);
DNode* CreateDNode(int x);
void AddHead(DList& l, DNode* p);
void AddTail(DList& l, DNode* p);
void AddAfterQ(DList& l, DNode* q, DNode* p);
void AddBeforeQ(DList& l, DNode* temp, DNode* q);
void DeleteHead(DList& l);
void DeleteTail(DList& l);
void DeleteAfterQ(DList& l, DNode* q);
void DeleteBeforeQ(DList& l, DNode* q);
int DeleteX(DList& l, int x);
void InputDList(DList& l);
void PrintDList(DList l);

int main()
{

}

void CreateEmptyDList(DList& l)
{
    l.Head = NULL;
    l.Tail = NULL;
}
DNode* CreateDNode(int x)
{
    DNode* p = new DNode;
    if (p == NULL)
        exit(1);
    p->info = x;
    p->next = NULL;
    p->pre = NULL;
    return p;
}
void AddHead(DList& l, DNode* p)
{
    if (l.Head == NULL)
        l.Head = l.Tail = p;
    else
    {
        p->next = l.Head;
        l.Head->pre = p;
        l.Head = p;
    }
}
void AddTail(DList& l, DNode* p)
{
    if (l.Head == NULL)
        l.Head = l.Tail = p;
    else
    {
        p->pre = l.Tail;
        l.Tail->next = p;
        l.Tail = p;
    }
}
void AddAfterQ(DList& l, DNode* q, DNode* p)
{
    if (q != NULL)
    {
        p->next = q->next;
        q->next->pre = p;
        q->next = p;
        p->pre = q;
        if (l.Tail == q)
            l.Tail = p;
    }
    else
        AddHead(l, p);
}
void AddBeforeQ(DList& l, DNode* temp, DNode* q)
{
    DNode* p;
    p = q->pre;
    if (q != NULL)
    {
        temp->next = q;
        q->pre = temp;
        temp->pre = p;
        if (p != NULL)
            p->next = temp;
        if (q == l.Head)
            l.Head = temp;
    }
    AddTail(l, temp);
}
void DeleteHead(DList& l)
{
    DNode* p;
    if (l.Head != NULL)
    {
        p = l.Head;
        l.Head = l.Head->next;
        l.Head->pre = NULL;
        delete p;
        if (l.Head == NULL)
            l.Tail = NULL;
    }
}
void DeleteTail(DList& l)
{
    DNode* p;
    if (l.Head != NULL)
    {
        p = l.Tail;
        l.Tail = l.Tail->pre;
        l.Tail->next = NULL;
        delete p;
        if (l.Tail == NULL)
            l.Head = NULL;
    }
}
void DeleteAfterQ(DList& l, DNode* q)
{
    DNode* p;
    if (q != NULL)
    {
        p = q->next;
        if (p != NULL)
        {
            q->next = p->next;
            if (p == l.Tail)
                l.Tail = q;
            else
                p->next->pre = q;
            delete p;
        }
    }
    DeleteHead(l);
}
void DeleteBeforeQ(DList& l, DNode* q)
{
    DNode* p;
    if (q != NULL)
    {
        p = q->pre;
        if (p != NULL)
            q->pre = p->pre;
        if (p == l.Head)
            l.Head = q;
        else
            p->pre->next = q;
        delete p;
    }
    DeleteTail(l);
}
int DeleteX(DList&l,int x)
{
    DNode* p;
    DNode* q;
    q = NULL;
    p = l.Head;
    while (p != NULL)
    {
        if (p->info == x)
            break;
        q = p;
        p = p->next;
    }
    if (q == NULL)
        return 0;
    if (q != NULL)
        DeleteAfterQ(l, q);
    else
        DeleteHead(l);
    return 1;
}
void InputDList(DList& l)
{
    int soluong;
    cout << "So phan tu can nhap la: ";
    cin >> soluong;
    for (int i = 0; i < soluong; i++)
    {
        int x;
        cout << "Phan tu thu " << i + 1 << ": ";
        cin >> x;
        DNode* p = new DNode;
        p = CreateDNode(x);
        AddHead(l, p);
    }
}
void PrintDList(DList l)
{
    cout << "Duyet danh sach: " << endl;
    for (DNode* p = l.Head; p != NULL; p = p->next)
        cout << p->info << "\t";
    cout << endl;
}