#include <stdio.h>
#include <math.h>
#define Max 50

void NhapMang(int a[], int &n)
{
	printf("Nhap so luong phan tu trong mang: ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		printf("a[%d] = ",i);
		scanf("%d", &a[i]);
	}
}

void InMang(int a[], int n)
{
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);	
}

int KTSNT(int n)
{
	if(n<2)
		return 0;
	else
		for(int i = 2; i <= sqrt(n); i++)
			if(n%i==0)
				return 0;
	return 1;			
}

int CountSNT(int a[], int n)
{
	if(n==0)
		return 0;
	if(KTSNT(a[n-1])==1)
		return 1 + CountSNT(a,n-1);
	return CountSNT(a,n-1);
}

int Sum(int a[], int n)
{
	if(n==0)
		return 0;
	if(a[n-1]%2==0)
		return a[n-1] + Sum(a,n-1);
	return Sum(a,n-1);
}

int main()
{
	int a[Max], n;
	NhapMang(a,n);
	printf("Mang vua nhap la: ");
	InMang(a,n);
	printf("\nSo luong phan tu la so nguyen to trong mang: %d", CountSNT(a,n));
	printf("\nTong cac phan tu chan trong mang: %d", Sum(a,n));
	return 1;
}
