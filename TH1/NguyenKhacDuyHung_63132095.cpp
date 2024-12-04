#include <stdio.h>
#include <vector>
#include <math.h>
#define Max 50

void NhapMang(int a[], int &n)
{
	do{
	printf("Nhap so luong phan tu trong mang: ");
	scanf("%d", &n);
	}while(!(n>=3 && n<=100));
	for(int i = 0; i < n; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void XuatMang(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

int laSCP(int n)
{
	int m = sqrt(n);
	if(m*m==n)
		return 1;
	return 0;
}

int maxSCP(int a[], int n)
{
	int count = 0;
	int max = a[0];
	for(int i = 0; i < n; i++)
	{
		if(laSCP(a[i])==0)
			count = 0;
		else{
			count++;
			if(a[i]>max)
				max = a[i];
		}
	}
	if(count == 0)
		return -1;
	return max;
}

void chenPhanTu(int a[], int &n, int x, int i)
{
	if(i>=0 && i<=n)
	{
		for(int j = n; j > i; j--)
				a[j] = a[j-1];
		a[i] = x;
		n++;
	}
}

void chenMax(int a[], int &n, int k)
{
	int max = 0;
		for(int i = 0; i < n; i++)
			if(a[max] < a[i])
				max = i;
		chenPhanTu(a,n,k,max+1);	
}

int timMax(int a[], int n)
{
	int max = a[0];
	for(int i = 0; i < n; i++){
		if(a[i] > max)
			max = a[i];
	}
	return max;
}


int main()
{
	int a[Max], n;
	NhapMang(a,n);
	printf("Mang vua nhap la: ");
	XuatMang(a,n);
	if(maxSCP(a,n)==-1)
		printf("\nMang khong co so chinh phuong!");
	else
		printf("\nSo chinh phuong lon nhat trong mang: %d",maxSCP(a,n));
	int x, i;
	printf("\n\nNhap so x can chen: ");
	scanf("%d", &x);
	printf("Nhap vi tri i can chen (0->%d): ", n-1);
	scanf("%d", &i);
	chenPhanTu(a,n,x,i);
	printf("Mang sau khi chen %d vao vi tri %d la: ", x, i);
	XuatMang(a,n);
	int k;
	printf("\n\nNhap so k can chen vao ngay sau phan tu lon nhat cua mang: ");
	scanf("%d", &k);
	chenMax(a,n,k);
	printf("Mang sau khi chen %d vao ngay sau phan tu lon nhat cua mang: ", k);
	XuatMang(a,n);
	return 1;
}
