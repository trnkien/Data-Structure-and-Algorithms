//STT: 16
//Họ và tên: Trần Trọng Kiên
//Buổi 03 - Bài 01

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
 
struct Node
{
    int info;
    Node* Next;
};
struct List
{
    Node* Head;
    Node* Tail;
    int soluong;
};

int menu();
int luachoncase1();
void CreateEmptyList(List& l);
void AddHead(List& l, Node* p);
Node* CreateNode(int x);
void InputList(List& l);
void AutoInputList(List& l);
void case1(int n, List& l);
void AddTail(List& l, Node* p);
void OutputList(List l);
void OutputValueandAdress(List l);
int SearchList(List l);
int DeleteAfterQ(List& l, Node* q, int& x);
int DeleteHead(List& l, int& x);
int DeleteX(List& l);
int Update(List& l);

int main()
{
    List l;
    CreateEmptyList(l);
    int flag = true;
    while (flag != false)
    {
        int luachon = menu();
        switch (luachon)
        {
            case 1:
            {
                int luachon = luachoncase1();
                case1(luachon, l);
                cout << endl;
                break;
            }
            case 2:
            {
                Node* p = new Node;
                int x;
                cout << "Nhap gia tri: ";
                cin >> x;
                p = CreateNode(x);
                AddHead(l, p);
                cout << endl;
                break;
            }
            case 3:
            {
                Node* p = new Node;
                int x;
                cout << "Nhap gia tri: ";
                cin >> x;
                p = CreateNode(x);
                AddTail(l, p);
                cout << endl;
                break;
            }
            case 4:
            {
                OutputList(l);
                cout << endl;
                break;
            }
            case 5:
            {
                OutputValueandAdress(l);
                cout << endl;
                break;
            }
            case 6:
            {
                int temp = SearchList(l);
                if (temp == -1)
                    cout << "Khong tim thay!" << endl;
                else
                    cout << "Tim thay o vi tri: " << temp << endl;
                break;
            }
            case 7:
            {
                int temp = DeleteX(l);
                if (temp == 1)
                    cout << "Da xoa!" << endl;
                else
                    cout << "Khong tim thay gia tri can xoa!" << endl;
                break;
            }
            case 8:
            {
                int temp = Update(l);
                if (temp == 1)
                    cout << "Da cap nhat!" << endl;
                else
                    cout << "Khong tim thay gia tri can cap nhat." << endl;
                break;
            }
            case 9:
            {
                cout << "Xin chao!" << endl;
                flag = false;
                break;
            }
            default:
            {
                cout << "Nhap khong dung! Nhap lai: ";
                break;
            }
        }
    }
}
//Menu
int menu() 
{
    int luachon;
    cout << "|                           MENU                          |" << endl;
    cout << "1. Tao danh sach lien ket don luu tru cac so nguyen." << endl;
    cout << "2. Chen dau danh sach." << endl;
    cout << "3. Chen cuoi danh sach." << endl;
    cout << "4. In gia tri danh sach da nhap." << endl;
    cout << "5. In gia tri kem dia chi cua tung node trong danh sach." << endl;
    cout << "6. Tim kiem 1 gia tri trong danh sach." << endl;
    cout << "7. Xoa 1 gia tri X trong danh sach." << endl;
    cout << "8. Cap nhat 1 gia tri X cho phan tu bat ky trong danh sach." << endl;
    cout << "9. Ket thuc." << endl;
    cout << "| =======================================================  |" << endl;
    cout << "Lua chon: ";
    cin >> luachon;
    return luachon;
}  
//Khởi tạo
Node* CreateNode(int x)
{
    Node* p = new Node;
    if (p == NULL)
        exit(1);
    p->info = x;
    p->Next = NULL;
    return p;
}
void CreateEmptyList(List& l)
{
    l.Head = NULL;
    l.Tail = NULL;
}
//Câu 1
int luachoncase1()
{
    int luachon;
    cout << "Phuong thuc nhap danh sach:" << endl;
    cout << "1. Nhap thu cong tu ban phim." << endl;
    cout << "2. Nhap tu dong." << endl;
    cout << "Luachon: ";
    cin >> luachon;
    return luachon;
} //  
void case1(int n, List& l)
{
    if (n == 1)
        InputList(l);
    else
    {
        if (n == 2)
            AutoInputList(l);
        else
            cout << "Chon khong dung";
    }
}
void InputList(List& l)
{
    cout << "Nhap so luong: ";
    cin >> l.soluong;
    while (l.soluong <= 0)
    {
        cout << "Nhap sai! Nhap lai: ";
        cin >> l.soluong;
    }
    for (int i = 0; i < l.soluong; i++)
    {
        cout << "Nhap node thu " << i + 1 << ": ";
        int x;
        cin >> x;
        Node* p = new Node;
        p = CreateNode(x);
        AddHead(l, p);
    }
}
void AutoInputList(List& l)
{
    srand(time(NULL));
    l.soluong = 39 + rand() % +21;
    for (int i = 0; i < l.soluong; i++)
    {
        int x = -99 + rand() % +99;
        Node* p = new Node;
        p = CreateNode(x);
        AddHead(l, p);
    }
}
//Câu 2
void AddHead(List& l, Node* p)
{
    if (l.Head == NULL)
        l.Head = l.Tail = p;
    else
    {
        p->Next = l.Head;
        l.Head = p;
    }
}
//Câu 3
void AddTail(List& l, Node* p)
{
    if (l.Head == NULL)
        l.Head = l.Tail = p;
    else
    {
        l.Tail->Next = p;
        l.Tail = p;
    }
}
//Câu 4
void OutputList(List l)
{
    for (Node* p = l.Head; p != NULL; p = p->Next)
        cout << p->info << endl;
}
//Câu 5
void OutputValueandAdress(List l)
{
    for (Node* p = l.Head; p != NULL; p = p->Next)
        cout << p << "," << p->info << endl;
}
//Câu 6
int SearchList(List l)
{
    int x, y = 1;
    cout << "Nhap gia tri can tim kiem: ";
    cin >> x;
    for (Node* p = l.Head; p != NULL; p = p->Next)
    {
        if (x == p->info)
            return y;
        y++;
    }
    return -1;
}
//Câu 7
int DeleteAfterQ(List& l, Node* q, int& x)
{
    Node* p;
    if (q != NULL)
    {
        p = q->Next;
        if (p != NULL)
        {
            if (p == l.Tail)
                l.Tail = q;
            q->Next = p->Next;
            x = p->info;
            delete p;
        }
        return 1;
    }
    else
        return 0;
}
int DeleteHead(List& l, int& x)
{
    Node* p;
    if (l.Head != NULL)
    {
        p = l.Head;
        x = p->info;
        l.Head = l.Head->Next;
        delete p;
        if (l.Head == NULL)
            l.Tail = NULL;
        return 1;
    }
    return 0;
}
int DeleteX(List& l)
{
    int x;
    cout << "Nhap gia tri can xoa: ";
    cin >> x;
    Node* p, * q = NULL;
    p = l.Head;
    while ((p != NULL) && (p->info != x))
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
//Câu 8
int Update(List& l)
{
    int x;
    cout << "Nhap gia tri can cap nhat: ";
    cin >> x;
    for (Node* p = l.Head; p != NULL; p = p->Next)
    {
        if (x == p->info)
        {
            int y;
            cout << "Nhap gia tri moi: ";
            cin >> y;
            p->info = y;
            return 1;
        }
    }
    return 0;
}