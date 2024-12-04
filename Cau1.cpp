#include <stdio.h>

long giaiThua(int n){
	if(n==1) return 1;
	return giaiThua(n-1) * n;
}

double S(float n)
{
	if(n==0 || n==1)
		return 1;
	return S(n-1) + 1.0/giaiThua(n);
}

int main()
{
	int n;
	printf("Nhap so nguyen n: ");
	scanf("%d", &n);
	printf("Gia tri bieu thuc S = %lf", S(n));
	return 1;
}
