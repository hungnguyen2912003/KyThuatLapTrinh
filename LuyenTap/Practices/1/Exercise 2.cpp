#include <stdio.h>
#include <math.h>
#define Max 50

void NhapMang(int a[], int &n)
{
	printf("Nhap so luong phan tu cua mang: ");
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
	{
		printf("%d ", a[i]);
	}
}

int Check_SCP(int n)
{
	if((int)sqrt(n)*(int)sqrt(n)==n)
		return 1;
	return 0;
}

int maxSCP(int a[], int n, int x)
{
	if(n==0)
		return x;
	if(Check_SCP(a[n-1])==1 && x < a[n-1])
		return maxSCP(a,n-1,a[n-1]);	
	return maxSCP(a,n-1,x);
}

int ToanChuSoLe(int k)
{
	if(k%2==0 && k!=0)
		return 0;
	if(k%2==1)
		return ToanChuSoLe(k/10);
	return 1;
}

int CountPTLe(int a[], int n)
{
	if(n==0)
		return -1;
	if(ToanChuSoLe(a[n-1])==1)
		return 1 + CountPTLe(a,n-1);
	return CountPTLe(a,n-1);
}

int main()
{
	int a[Max], n;
	NhapMang(a,n);
	printf("Mang vua nhap la: ");
	InMang(a,n);
	if(maxSCP(a,n,-1)==-1)
		printf("\nMang khong co so chinh phuong!");
	else
		printf("\nMang co phan tu la so chinh phuong lon nhat: %d", maxSCP(a,n,-1));
	if(CountPTLe(a,n)!=n)
		printf("\nMang khong chua toan chu so le");
	else
		printf("\nMang chua toan chu so le");
}
