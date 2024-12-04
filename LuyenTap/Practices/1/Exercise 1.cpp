#include <stdio.h>

float S(float n)
{
	if(n==1)
		return 0.5;
	else
		return S(n-1) + 1/(2*n);
}

int main(){
	float n;
	printf("Nhap so nguyen n: ");
	scanf("%f", &n);
	printf("\nGia tri bieu thuc S = %.2f", S(n)+1);
	return 1;
}
