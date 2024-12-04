#include <stdio.h>
#include <math.h>
#define Max 50

void NhapMang(int a[], int &n)
{
	printf("Nhap so luong phan tu trong mang: ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}
 
void InMang(int a[], int n)
{
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
}

int CountPTLe(int a[], int n)
{
	if(n==0)
		return 0;
	else
	{
		if(n%2==1)
			return 1 + CountPTLe(a,n-1);
		return CountPTLe(a,n-1);
	}
}

int Check_SNT(int n)
{
	if(n<1)
		return 0;
	else
		for(int i = 2; i <= sqrt(n); i++)
			if(n%i==0)
				return 0;
	return 1;	
}

int maxSNT(int a[], int n, int x)
{
	if(n==0)
		return x;
	if(Check_SNT(a[n-1])==1)
		if(x < a[n-1])
			return maxSNT(a,n-1,a[n-1]);
	return maxSNT(a,n-1,x);
}

int main()
{
	int a[Max], n;
	NhapMang(a,n);
	printf("Mang vua nhap la: ");
	InMang(a,n);
	printf("\nSo luong phan tu le trong mang: %d", CountPTLe(a,n));
	if(maxSNT(a,n,0)==0)
		printf("\nMang khong co so nguyen to nao!");
	else
		printf("\nMang co phan tu la so nguyen to lon nhat la: %d", maxSNT(a,n,0));
	return 1;
}
