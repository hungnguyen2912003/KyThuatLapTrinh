#include <stdio.h>
#include <conio.h>

float TinhTong(float n){
	if(n==1)	return 0.5;
	return 1/(2*n) + TinhTong(n-1);
}

int main(){
	float n;
	printf("Nhap n: ");
	scanf("%f", &n);
	printf("Ket qua bieu thuc la: %.2f", TinhTong(n));
	return 1;
}
