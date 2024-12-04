#include <stdio.h>
#include <math.h>
#define Max 50

void NhapMang(int a[], int &n)
{
	printf("Nhap so luong phan tu mang: ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void xuatmang(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

int laSCP(int n)
{
	if(n<1)
		return 0;
	else{
		if(sqrt(n)*sqrt(n)==n)
			return 1;
		return 0;
	}
}

int maxSCP(int a[], int n)
{
	int count = 0;
	int max = a[0];
	for(int i = 0; i < n; i++)
	{
		if(laSCP(a[i])==0)
			count = 0;
		else
		{
			count++;
			if(a[i]>max)
				max = a[i];
		}
	}
	if(count == 0)
		return -1;
	return max;
}

void xoaPhanTu_Vitri(int a[], int &n, int i)
{
	if(i>=0 && i<=n)
		for(int j = i; j < n-1; j++)
			a[i] = a[i+1];
	n--;
}

void xoaphantu(int a[], int &n, int x){
	for(int i = 0; i < n; i++)
		if(a[i]==x)
			xoaPhanTu_Vitri(a,n,i);
}


int main()
{
	int a[Max], n;
	NhapMang(a,n);
	printf("Mang vua nhap la: ");
	xuatmang(a,n);
	printf("\n%d",maxSCP(a,n));
	int x;
	printf("Nhap phan tu x can xoa vao mang: ");
	scanf("%d", &x);
	xoaphantu(a,n,x);
	printf("Mang sau khi xoa %d trong mang: ", x);
	xuatmang(a,n);
	return 1;
}
