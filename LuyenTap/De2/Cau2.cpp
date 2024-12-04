#include <stdio.h>
#include <math.h>
#define Max 50

void NhapMang(int a[], int &n)
{
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void InMang(int a[], int n){
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
}

int PTLe(int a[], int n)
{
	if(n==0)
		return 0;
	if(n%2==1)
		return 1 + PTLe(a,n-1);
	else
		return PTLe(a,n-1);
}

int KTSNT(int n){
	int count = 0;
	if(n<2)	return 0;
	for(int i = 2; i < n; i++){
		if(n%i==0)
			count++;
	}
	if(count==1)
		return 1;
	return 0;
}

int Max_SNT(int a[], int n)
{
	if(n==0)
		return 0;
	if(KTSNT(a[n-1]))
		if(a[n-1]>Max_SNT(a,n-1))
			return a[n-1];	
	return Max_SNT(a,n-1);
}

int main(){
	int a[Max], n;
	NhapMang(a,n);
	printf("\nMang vua nhap la: ");
	InMang(a,n);
	printf("\nSo luong cac phan tu le trong mang: %d", PTLe(a,n-1));
	if(Max_SNT(a,n)==0)
		printf("\nMang khong co so nguyen to nao!");
	else
		printf("\nPhan tu la so nguyen to lon nhat trong mang: %d", Max_SNT(a,n));
}
