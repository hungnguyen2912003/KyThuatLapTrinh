#include <stdio.h>
#include <math.h>
int S(int n)
{
	if(n==0)
		return 0;
	return S(n-1) + pow(-1,n) * n; 
}

int main()
{
	int n; 
	printf("Nhap so nguyen n (n>0): ");
	scanf("%d", &n);
	printf("Gia tri bieu thuc S = %d", S(n));
}
