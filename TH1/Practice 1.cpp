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

void Xuatmang(int a[], int n)
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
	else
	{
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
	if(count==0)
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
	int maxpos = 0;
	for(int i = 0; i < n; i++)
		if(a[maxpos] < a[i])
			maxpos = i;
	chenPhanTu(a,n,k,maxpos+1);		
}

void tachMang(int a[], int n, int mangDuong[], int &nchan, int mangam[], int &nLe)
{
	nchan = 0;
	nLe = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i]	> 0)
		{
			mangDuong[nchan] = a[i];
			nchan++;
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(a[i] < 0)
		{
			mangam[nLe] = a[i];
			nLe++;
		}
	}	
}

int main()
{
	int a[Max], n;
	NhapMang(a,n);
	printf("Mang vua nhap la: ");
	Xuatmang(a,n);
	if(maxSCP(a,n)==-1)
		printf("\nMang khong co so chinh phuong!\n");
	else
		printf("\nMang co so chinh phuong lon nhat la: %d\n", maxSCP(a,n));
	int x, i;
	printf("\nNhap so x can chen: ");
	scanf("%d", &x);
	printf("Nhap vi tri i can chen (0->%d): ", n-1);
	scanf("%d", &i);
	chenPhanTu(a,n,x,i);
	printf("Mang sau khi chen la: ");
	Xuatmang(a,n);
	int k;
	printf("\n\nNhap so k can chen vao ngay sau phan tu lon nhat trong mang: ");
	scanf("%d", &k);
	chenMax(a,n,k);
	printf("Mang sau khi chen vao ngay sau phan tu lon nhat trong mang: ");
	Xuatmang(a,n);
	int b[Max], c[Max], nb, nc;
	tachMang(a,n,b,nb,c,nc);
	printf("\n\nMang thu nhat gom cac phan tu khong am: ");
	Xuatmang(b,nb);
	printf("\nMang thu hai gom cac phan tu am: ");
	Xuatmang(c,nc);
	return 1;
}
