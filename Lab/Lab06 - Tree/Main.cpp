//Trần Trọng Kiên
//STT: 16
//Tuần 8 - Bài 8
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

struct TNode
{
	int info;
	TNode* Right;
	TNode* Left;
	int Thongke;
};

struct TREE
{
	TNode* Root;
};

int menu();
void CreateTRee(TREE& a);
TNode* CreateTNode(int x);
void insertTNode(TREE& a, int x);
void InputTree(TREE& a, int x);
void AutoInput(TREE& a, int sl);
void Output(TNode* a);
void NLR(TNode* a);
void LNR(TNode* a);
void LRN(TNode* a);
TNode* SearchNode(TREE a, int x);
void DeleteNodeX1(TNode*& b, int x);
void ThayThe(TNode*& a, TNode*& b);
void DeletePerfectly(TNode*& b);
int DemNode(TNode* a);
void DemNodeLa(TNode* a, int& b);
void NLRx(TNode* a, int x);
void DemNodeBeX(TNode* a, int& dem, int x);
void DemNodeLonX(TNode* a, int& dem, int x);
void DemNodeXY(TNode* a, int& dem, int x, int y);
void SoSanh10v11(TNode* a, int x);
void TongNode(TNode* a, int& sum);
void DemNodeChan(TNode* a, int& dem);
void DemNodeChan(TNode* a, int& dem);
void SoSanhChanvLe(TNode* a);
void TongNodeChan(TNode* a, int& sum);
void TongNodeLe(TNode* a, int& sum);
void SoSanhTongChanvLe(TNode* a);
TNode* NodeMax(TNode* a);
TNode* NodeMin(TNode* a);

//Main
int main()
{
	TREE a;
	CreateTRee(a);
	int flag = true;
	while (flag != false)
	{
		int luachon = menu();
		switch (luachon)
		{
		case 1:
		{
			int sl;
			cout << "Nhap so luong: ";
			cin >> sl;
			InputTree(a, sl);
			break;
		}
		case 2:
		{
			srand(time(NULL));
			int sl = rand() % 10 + 11;
			AutoInput(a, sl);
			break;
		}
		case 3:
		{
			cout << "NLR: " << endl;
			NLR(a.Root);
			cout << endl;
			cout << "LNR: " << endl;
			LNR(a.Root);
			cout << endl;
			cout << "LRN: " << endl;
			LRN(a.Root);
			cout << endl;
			break;
		}
		case 4:
		{
			int x;
			cout << "Nhap gia tri can tim kiem: ";
			cin >> x;
			if (SearchNode(a, x) == NULL)
				cout << "Khong tim thay !" << endl;
			else
				Output(SearchNode(a, x));
			cout << endl;
			break;
		}
		case 5:
		{
			int y;
			cout << "Nhap gia tri can xoa: ";
			cin >> y;
			DeleteNodeX1(a.Root, y);
			break;
		}
		case 6:
		{
			DeletePerfectly(a.Root);
			break;
		}
		case 7:
		{
			cout << "So Node co trong cay: " << DemNode(a.Root) << endl;
			break;
		}
		case 8:
		{
			int dem = 0;
			DemNodeLa(a.Root, dem);
			cout << "So Node la trong cay: " << dem << endl;
			break;
		}
		case 9:
		{
			int j;
			cout << "Nhap gia tri: ";
			cin >> j;
			NLRx(a.Root, j);
			break;
		}
		case 10:
		{
			int k;
			cout << "Nhap gia tri x: ";
			cin >> k;
			int dem = 0;
			DemNodeBeX(a.Root, dem, k);
			cout << "So node nho hon x: " << dem << endl;
			break;
		}
		case 11:
		{
			int l;
			cout << "Nhap gia tri: ";
			cin >> l;
			int dem = 0;
			DemNodeLonX(a.Root, dem, l);
			cout << "So node lon hon x: " << dem << endl;
			break;
		}
		case 12:
		{
			int x, y;
			cout << "Nhap gia tri x: ";
			cin >> x;
			cout << "Nhap gia tri y: ";
			cin >> y;
			int dem = 0;
			DemNodeXY(a.Root, dem, x, y);
			cout << "x < node < y: " << dem << endl;
			break;
		}
		case 13:
		{
			int x;
			cout << "Nhap gia tri x: ";
			cin >> x;
			SoSanh10v11(a.Root, x);
			break;
		}
		case 14:
		{
			SoSanhChanvLe(a.Root);
			break;
		}
		case 15:
		{
			int sum = 0;
			TongNode(a.Root, sum);
			cout << "Tong cac node trong cay: " << sum << endl;
			break;
		}
		case 16:
		{
			int sum = 0;
			TongNodeChan(a.Root, sum);
			cout << "Tong cac node chan: " << sum << endl;
			break;
		}
		case 17:
		{
			int sum = 0;
			TongNodeLe(a.Root, sum);
			cout << "Tong cac node le: " << sum << endl;
			break;
		}
		case 18:
		{
			SoSanhTongChanvLe(a.Root);
			break;
		}
		case 19:
		{
			if (a.Root == NULL)
				cout << "Cay rong !" << endl;
			else
			{
				cout << "Node lon nhat: ";
				Output(NodeMax(a.Root));
				cout << "Node nho nhat: ";
				Output(NodeMin(a.Root));
			}
			break;
		}
		case 20:
		{
			cout << "Xin chao !";
			flag = false;
			break;
		}
		default:
		{
			cout << "Nhap sai ! Nhap lai: ";
			break;
		}
		}
	}
}
//Menu
int menu()
{
	int luachon;
	cout << endl;
	cout << "* ================MENU=============== *" << endl;
	cout << "* 1. Nhap gia tri.                    *" << endl;
	cout << "* 2. Nhap tu dong.                    *" << endl;
	cout << "* 3. Duyet cay.                       *" << endl;
	cout << "* 4. Tim kiem.                        *" << endl;
	cout << "* 5. Xoa X.                           *" << endl;
	cout << "* 6. Xoa toan bo node.                *" << endl;
	cout << "* 7. Dem so node.                     *" << endl;
	cout << "* 8. Dem so node la.                  *" << endl;
	cout << "* 9. In ra node nhanh.                *" << endl;
	cout << "* 10. dem so node < X.                *" << endl;
	cout << "* 11. Dem so node > X.                *" << endl;
	cout << "* 12. Dem so node > X va < Y.         *" << endl;
	cout << "* 13. So sanh cau 10 va cau 11.       *" << endl;
	cout << "* 14. Dem node chan va le -> So sanh. *" << endl;
	cout << "* 15. Tong cac node.                  *" << endl;
	cout << "* 16. Tong cac node chan.             *" << endl;
	cout << "* 17. Tong cac node le.               *" << endl;
	cout << "* 18. So sanh cau 16 va 17.           *" << endl;
	cout << "* 19. Node max va node min.           *" << endl;
	cout << "* 20. Ket thuc !                      *" << endl;
	cout << "* =================================== *" << endl;
	cout << "Lua chon: ";
	cin >> luachon;
	cout << endl;
	cout << "************ THUC HIEN ****************" << endl;
	cout << endl;
	return luachon;
}
//Create TREE
void CreateTRee(TREE& a)
{
	a.Root = NULL;
}
//Create Node
TNode* CreateTNode(int x)
{
	TNode* p = new TNode;
	if (p == NULL)
		exit(1);
	p->info = x;
	p->Left = NULL;
	p->Right = NULL;
	return p;
}

//Câu 1
//Chèn node.
void insertTNode(TREE& a, int x)
{
	TNode* p = CreateTNode(x);
	if (a.Root == NULL)
		a.Root = p;
	else
	{
		TNode* p_run = a.Root;
		TNode* p_yes = NULL;
		while (p_run != NULL)
		{
			p_yes = p_run;
			if (p_run->info > x)
				p_run = p_run->Left;
			else
			{
				if (p_run->info < x)
					p_run = p_run->Right;
				else
					if (p_run->info == x)
						break;
			}
		}
		if (p_yes->info > x)
			p_yes->Left = p;
		else
		{
			if (p_yes->info < x)
				p_yes->Right = p;
			else if (p_yes->info == x)
				p->Thongke++;
		}
	}
}
//Chèn node vào cây.
void InputTree(TREE& a, int sl)
{
	for (int i = 0; i < sl; i++)
	{
		int x;
		cout << "Nhap gia tri [" << i + 1 << "]: ";
		cin >> x;
		insertTNode(a, x);
	}
}

//Câu 2
//Chèn node tự động.
void AutoInput(TREE& a, int sl)
{
	srand(time(NULL));
	for (int i = 0; i < sl; i++)
	{
		int x;
		x = rand() % 358 + 1001;
		insertTNode(a, x);
	}
}

//Câu 3
//Xuất giá trị của node.
void Output(TNode* a)
{
	cout << a->info << "\t" << a << "\t";
	cout << "pLeft: " << a->Left << "\t";
	cout << "pRight: " << a->Right << "\t" << endl;
}
//Duyệt NLR
void NLR(TNode* a)
{
	if (a != NULL)
	{
		Output(a);
		NLR(a->Left);
		NLR(a->Right);
	}
}
//Duyệt LNR
void LNR(TNode* a)
{
	if (a != NULL)
	{
		LNR(a->Left);
		Output(a);
		LNR(a->Right);
	}
}
//Duyệt LRN
void LRN(TNode* a)
{
	if (a != NULL)
	{
		LRN(a->Left);
		LRN(a->Right);
		Output(a);
	}
}

//Câu 4
//Tìm kiếm 
TNode* SearchNode(TREE a, int x)
{
	TNode* i = a.Root;
	while (i != NULL)
	{
		if (i->info == x)
			return i;
		if (x < i->info)
			i = i->Left;
		else if (x > i->info)
			i = i->Right;
	}
	return NULL;
}

//Câu 5
//Tìm phần tử thế mạng.
void ThayThe(TNode*& a, TNode*& b)
{
	if (b->Left != NULL)
		ThayThe(a, b->Left);
	else
	{
		a->info = b->info;
		a = b;
		b = b->Right;
	}
}
//Xóa 1 phần tử
void DeleteNodeX1(TNode*& b, int x)
{
	if (b != NULL)
	{
		if (b->info < x)
			DeleteNodeX1(b->Right, x);
		else
		{
			if (b->info > x)
				DeleteNodeX1(b->Left, x);
			else
			{
				TNode* p;
				p = b;
				if (b->Left == NULL)
					b = b->Right;
				else
				{
					if (b->Right == NULL)
						b = b->Left;
					else
						ThayThe(p, b->Right);
				}
				delete p;
			}
		}
	}
	else
		cout << "Khong tim thay phan tu can xoa." << endl;
}

//Câu 6
//Xóa toàn bộ node
void DeletePerfectly(TNode*& b)
{
	while (b != NULL)
	{
		TNode* p;
		p = b;
		if (b->Left == NULL)
			b = b->Right;
		else
		{
			if (b->Right == NULL)
				b = b->Left;
			else
				ThayThe(p, b->Right);
		}
		delete p;
	}
}

//Câu 7
//Đếm tất cả Node
int DemNode(TNode* a)
{
	if (a == NULL)
		return 0;
	else
		return 1 + DemNode(a->Left) + DemNode(a->Right);
}

//Câu 8
//Đếm Node lá của cây
void DemNodeLa(TNode* a, int& b)
{
	if (a == NULL)
		return;
	else
	{
		if (a->Left == NULL && a->Right == NULL)
			b++;
		DemNodeLa(a->Left, b);
		DemNodeLa(a->Right, b);
	}
}

//Câu 9
//NLR giá trị x
void NLRx(TNode* a, int x)
{
	if (a == NULL)
		return;
	else
	{
		if (a->info == x)
		{
			if (a != NULL)
			{
				Output(a);
				NLR(a->Left);
				NLR(a->Right);
			}
			return;
		}
		else
		{
			NLRx(a->Left, x);
			NLRx(a->Right, x);
		}
	}
}

//Câu 10
//Đếm số node nhỏ hơn x
void DemNodeBeX(TNode* a, int& dem, int x)
{
	if (a != NULL)
	{
		if (a->info < x)
			dem++;
		DemNodeBeX(a->Left, dem, x);
		DemNodeBeX(a->Right, dem, x);
	}
}

//Câu 11
//Đếm số node lớn hơn x
void DemNodeLonX(TNode* a, int& dem, int x)
{
	if (a != NULL)
	{
		if (a->info > x)
			dem++;
		DemNodeLonX(a->Left, dem, x);
		DemNodeLonX(a->Right, dem, x);
	}
}

//Câu 12
//Đếm số node nhỏ hơn x, lớn hơn y
void DemNodeXY(TNode* a, int& dem, int x, int y)
{
	if (a != NULL)
	{
		if (a->info > x && a->info < y)
			dem++;
		DemNodeXY(a->Left, dem, x, y);
		DemNodeXY(a->Right, dem, x, y);
	}
}

//Câu 13
//So sánh câu 10 và câu 11
void SoSanh10v11(TNode* a, int x)
{
	int dem1;
	DemNodeBeX(a, dem1, x);
	int dem2;
	DemNodeLonX(a, dem2, x);
	if (dem1 > dem2)
		cout << "dem cau 10 > dem cau 11." << endl;
	else
	{
		if (dem1 < dem2)
			cout << "dem cau 10 < dem cau 11." << endl;
		else
			cout << "dem cau 10 = dem cau 11." << endl;
	}
}

//Câu 14
//Đếm node lẻ 
void DemNodeLe(TNode* a, int& dem)
{
	if (a != NULL)
	{
		if(a->info % 2 != 0)
			dem++;
		DemNodeLe(a->Left, dem);
		DemNodeLe(a->Right, dem);
	}
}
//Đếm node chẵn
void DemNodeChan(TNode* a, int& dem)
{
	if (a != NULL)
	{
		if (a->info % 2 == 0)
			dem++;
		DemNodeChan(a->Left, dem);
		DemNodeChan(a->Left, dem);
	}
}
//So sánh số node chẵn và node lẻ
void SoSanhChanvLe(TNode* a)
{
	int dem1 = 0;
	int dem2 = 0;
	DemNodeLe(a, dem1);
	DemNodeChan(a, dem2);
	if (dem1 < dem2)
		cout << "So node le < So node chan." << endl;
	else
	{
		if (dem1 > dem2)
			cout << "So node le > So node chan." << endl;
		else
			cout << "So node le = So node chan." << endl;
	}
}

//Câu 15
//Tính tổng các node trong cây.
void TongNode(TNode* a, int& sum)
{
	if (a != NULL)
	{
		sum += a->info;
		TongNode(a->Left, sum);
		TongNode(a->Right, sum);
	}
}

//Câu 16
//Tính tổng các node chẵn trong cây
void TongNodeChan(TNode* a, int& sum)
{
	if (a != NULL)
	{
		if (a->info % 2 == 0)
			sum += a->info;
		TongNodeChan(a->Left, sum);
		TongNodeChan(a->Right, sum);
	}
}

//Câu 17
//Tính tổng các node lẻ trong cây.
void TongNodeLe(TNode* a, int& sum)
{
	if (a != NULL)
	{
		if (a->info % 2 != 0)
			sum += a->info;
		TongNodeLe(a->Left, sum);
		TongNodeLe(a->Right, sum);
	}
}

//Câu 18
//So sánh tổng node chẵn và tổng node lẻ
void SoSanhTongChanvLe(TNode* a)
{
	int sum1;
	TongNodeLe(a, sum1);
	int sum2;
	TongNodeChan(a, sum2);
	if (sum1 > sum2)
		cout << "Tong cac node le > tong cac node chan." << endl;
	else
	{
		if (sum1 < sum2)
			cout << "Tong cac node le < tong cac node chan." << endl;
		else
			cout << "Tong cac node le = tong cac node chan." << endl;
	}
}

//Câu 19
//Hàm tìm kiếm node có giá trị lớn nhất
TNode* NodeMax(TNode* a)
{
	TNode* max = a;
	a = a->Right;
	while (a != NULL)
	{
		if (a->info > max->info)
			max = a;
		a = a->Right;
	}
	return max;
}
//Hàm tìm kiếm node có giá trị bé nhất
TNode* NodeMin(TNode* a)
{
	TNode* min = a;
	a = a->Left;
	while (a != NULL)
	{
		if (a->info < min->info)
			min = a;
		a = a->Left;
	}
	return min;
}