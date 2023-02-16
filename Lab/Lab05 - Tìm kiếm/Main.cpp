// Tên: Trần Trọng Kiên
// STT: 16
// Buổi 04 - Bài 04

#include <iostream>
#include <algorithm>
#include <time.h>
#include <cstdlib>
using namespace std;

int menu();
void Cau1(int* arr, int& sl);
void Cau2(int* arr, int& sl);
void Cau3(int arr[], int sl);
int Cau4(int arr[], int sl, int x);
int Cau5(int arr[], int sl, int x);
int Cau6(int arr[], int sl, int x);
int DemCau4(int arr[], int sl, int x);
int DemCau5(int arr[], int sl, int x);
int DemCau6(int arr[], int sl, int x);
void Cau7(int arr[], int sl, int x);
int Cau8(int arr[], int sl, int x);

int main()
{
	srand(time(NULL));
	int arrX[999];
	int slX;
	int arrY[999];
	int slY;
	int flag = true;
	while (flag != false)
	{
		int luachon = menu();
		switch (luachon)
		{
		case 1:
		{
			slX = 30 + rand() % +21;
			Cau1(arrX, slX);
			break;
		}
		case 2:
		{
			slY = 30 + rand() % +21;
			Cau2(arrY, slY);
			break;
		}
		case 3:
		{
			cout << "arrayX: ";
			Cau3(arrX, slX);
			cout << "arrayY: ";
			Cau3(arrY, slY);
			break;
		}
		case 4:
		{
			int x;
			cout << "Nhap gia tri can tim: ";
			cin >> x;
			int temp1 = Cau4(arrX, slX, x);
			if (temp1 == -1)
				cout << "Khong tim thay !" << endl;
			else
				cout << "arrayX: " << temp1 << endl;
			int temp2 = Cau4(arrY, slY, x);
			if (temp2 == -1)
				cout << "Khong tim thay !" << endl;
			else
				cout << "arrayY: " << temp2 << endl;
			break;
		}
		case 5:
		{
			int x;
			cout << "Nhap gia tri can tim: ";
			cin >> x;
			int temp1 = Cau5(arrX, slX, x);
			if (temp1 == -1)
				cout << "Khong tim thay !" << endl;
			else
				cout << "arrayX: " << temp1 << endl;
			int temp2 = Cau5(arrY, slY, x);
			if (temp2 == -1)
				cout << "Khong tim thay !" << endl;
			else
				cout << "arrayY: " << temp2 << endl;
			break;
		}
		case 6:
		{
			int x;
			cout << "Nhap gia tri can tim: ";
			cin >> x;
			int temp1 = Cau6(arrX, slX, x);
			if (temp1 == -1)
				cout << "arrayX: Khong tim thay !" << endl;
			else
				cout << "arrayX: " << temp1 << endl;
			int temp2 = Cau6(arrY, slY, x);
			if (temp2 == -1)
				cout << "arrayY: Khong tim thay !" << endl;
			else
				cout << "arrayY: " << temp2 << endl;
			break;
		}
		case 7:
		{
			int x;
			cout << "Nhap gia tri can tim: ";
			cin >> x;
			Cau7(arrY, slY, x);
			break;
		}
		case 8:
		{
			int x;
			cout << "Nhap gia tri can tim: ";
			cin >> x;
			int temp1 = Cau8(arrX, slX, x);
			if (temp1 == -1)
				cout << "arrayX: Khong tim thay!" << endl;
			else
				cout << "arrayX: " << temp1;
			int temp2 = Cau8(arrY, slY, x);
			if (temp2 == -1)
				cout << "arrayY: Khong tim thay !" << endl;
			else
				cout << "arrayY: " << temp2 << endl;
			break;
		}
		case 10:
		{
			cout << "Xin chao !";
			flag = false;
			break;
		}
		default:
		{
			cout << "Chon sai! Chon lai: ";
			break;
		}
		}
	}
}

int menu()
{
	int luachon;
	cout << "|| ================================================= MENU ===================================================== ||" << endl;
	cout << "|| 1. Nhap gia tri tu dong cho arrayX.                                                                          ||" << endl;
	cout << "|| 2. Nhap gia tri tu dong tang dan cho arrayY.                                                                 ||" << endl;
	cout << "|| 3. Xuat mang.                                                                                                ||" << endl;
	cout << "|| 4. Tim kiem phan tu X theo tiep can tim kiem tuyen tinh cho mang arrayX, arrayY.                             ||" << endl;
	cout << "|| 5. Tim kiem phan tu X theo tiep can tim kiem nhi phan cho mang arrayX, arrayY.                               ||" << endl;
	cout << "|| 6. Tim kiem phan tu X theo tiep can tim kiem noi suy cho mang arrayX, arrayY.                                ||" << endl;
	cout << "|| 7. So sanh so lan thuc hien tim kiem cung 1 gia tri tai cau 4,5,6 ap dung cho mang arrayY.                   ||" << endl;
	cout << "|| 8. Su dung ham tim kiem da duoc xay dung san trong C/C++.                                                    ||" << endl;
	cout << "|| 9. Su dung them cac thu vien dung trong C/C++ co ho tro ham tim kiem.                                        ||" << endl;
	cout << "|| 10.Thoat.                                                                                                    ||" << endl;
	cout << "|| ============================================================================================================ ||" << endl;
	cout << "Lua chon cua ban: ";
	cin >> luachon;
	return luachon;
}

void Cau1(int arr[], int& sl)
{
	srand(time(NULL));
	for (int i = 0; i < sl; i++)
		arr[i] = 100 + rand() % +900;
}
void Cau2(int arr[], int& sl)
{
	srand(time(NULL));
	int y;
	arr[0] = 100 + rand() % +31;
	y = arr[0];
	for (int i = 1; i < sl; i++)
	{
		arr[i] = y + rand() % +16;
		y = arr[i];
		y++;
	}
}
void Cau3(int arr[], int sl)
{
	cout << endl << "Xuat mang: " << endl;
	for (int i = 0; i < sl; i++)
		cout << "[" << i << "]: " << arr[i] << "   ";
	cout << endl;
}
int Cau4(int arr[], int sl, int x)
{
	for (int i = 0; i < sl; i++)
		if (arr[i] == x)
			return i;
	return -1;
}
int Cau5(int arr[], int sl, int x)
{
	int left = 0, right = sl - 1, mid;
	while (left <= right)
	{
		mid = (right + left) / 2;
		if (x == arr[mid])
			return mid;
		if (x < arr[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}
int Cau6(int arr[], int sl, int x)
{
	int left = 0, right = sl - 1, mid;
	while (left <= right)
	{
		mid = left + ((right - left) * (x - arr[left])) / (arr[right] - arr[left]);
		if (x == arr[mid])
			return mid;
		if (x < arr[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}
void Cau7(int arr[], int sl, int x)
{
	int minn, maxx;
	int k = DemCau4(arr, sl, x);
	int l = DemCau5(arr, sl, x);
	int g = DemCau6(arr, sl, x);
	maxx = max(max(k, l), g);
	minn = min(min(k, l), g);
	if (minn == k)
		cout << "Tim kiem tuyen tinh co so buoc it nhat: " << minn << endl;
	else
	{
		if (minn == l)
			cout << "Tim kiem nhi phan co so buoc thuc hien it nhat: " << minn << endl;
		else
			if (minn == g)
				cout << "Tim kiem noi suy co so buoc thuc hien it nhat: " << minn << endl;
	}
	if (maxx == k)
		cout << "Tim kiem tuyen tinh co so buoc nhieu nhat: " << maxx << endl;
	else
	{
		if (maxx == l)
			cout << "Tim kiem nhi phan co so buoc nhieu nhat: " << maxx << endl;
		else
			if (maxx == g)
				cout << "Tim kiem noi suy co so buoc nhieu nhat: " << maxx << endl;
	}
}
int DemCau4(int arr[], int sl, int x)
{
	int dem = 0;
	for (int i = 0; i < sl; i++)
	{
		dem++;
		if (arr[i] == x)
			return dem;
	}
	return dem;
}
int DemCau5(int arr[], int sl, int x)
{
	int dem = 0;
	int left = 0, right = sl - 1, mid;
	while (left <= right)
	{
		dem++;
		mid = (right + left) / 2;
		if (x == arr[mid])
			return dem;
		if (x < arr[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return dem;
}
int DemCau6(int arr[], int sl, int x)
{
	int dem = 0;
	int left = 0, right = sl - 1, mid;
	while (left <= right)
	{
		dem++;
		mid = left + ((right - left) * (x - arr[left])) / (arr[right] - arr[left]);
		if (x == arr[mid])
			return dem;
		if (x < arr[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return dem;
}
int Cau8(int arr[], int sl, int x)
{
	int y;
	int* p = &y;
	int temp = sl - 1;
	int* kq;
	kq = find(arr, arr + temp, x);
	if (kq != arr + temp)
		return *kq;
	else
		return -1;
}