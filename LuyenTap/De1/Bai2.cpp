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

void InMang(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

//int Check_SCP(int n)
//{
//	int m = sqrt(n);
//	if(n<1)	return 0;
//	if(m*m==n)
//		return 1;
//	return 0;
//}
//
//int MaxSCP(int a[], int n){
//	int count = 0;
//	if(n==0)
//		return 0;
//	if(Check_SCP(a[n-1])==0)
//		count = 0;
//	else{
//		count++;
//		if(MaxSCP(a,n-1)>a[n-1])
//			return MaxSCP(a,n-1);
//		else
//			return a[n-1];
//	}
//	if(count == 0)
//		return -1;
//	return 1;
//}

//int ToanChuSoLe(int k)
//{
//	if(k%2==1)
//		return 1;
//	return 0;
//}
//
//int DemPTSoLe(int a[], int n)
//{
//	int count = 0;
//	for(int i = 0; i < n; i++)
//		if(ToanChuSoLe(a[i])==1)
//			count++;
//	if(count == n)
//		return 1;
//	return 0;	
//}

int kt_square(int n){
    if((int)sqrt(n)*(int)sqrt(n)==n) return 1; else return 0;
}
int max_square_rc(int a[], int n, int x){
    if(n == 0) return x;
    if(kt_square(a[n-1]) == 1 && a[n-1] > x) return max_square_rc(a,n-1,a[n-1]);
    else
        return max_square_rc(a,n-1,x);
}

int main(){
	int a[Max], n;
	NhapMang(a,n);
	printf("Mang vua nhap la: ");
	InMang(a,n);
	printf("\nSo chinh phuong lon nhat trong mang: %d", max_square_rc(a,n,-1));
	max_square_rc(a,n,-1);
	return 1;
}

