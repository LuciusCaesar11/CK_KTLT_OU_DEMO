#include<iostream>
using namespace std;
#include<iomanip>

void xoanoc(int **a, int n)
{
	int maxc = n - 1, minc = 0, maxr = n - 1, minr = 0;
	int value = n*n;
	while (value > 0)
	{
		for (int i = maxc; i >= minc; i--)
			a[minr][i] = value--;
		minr++;
		for (int i = minr; i <= maxr; i++)
			a[i][minc] = value--;
		minc++;
		for (int i = minc; i <= maxc; i++)
			a[maxr][i] = value--;
		maxr--;
		for (int i = maxr; i >= minr; i--)
			a[i][maxc] = value--;
		maxc--;
	}
}

void xuat(int **a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout <<a[i][j]<<" "<<left<<setw(2);
		cout << endl;
	}
}

int main()
{
	int n;
	do
	{
		cout << "nhap n: ";
		cin >> n;
		if (n < 1 && n>10)
			cout << "nhap lai";
	} while (n < 1 && n>10);
	int **a = new int*[n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	xoanoc(a, n);
	xuat(a, n);
	system("pause");
	return 0;
}