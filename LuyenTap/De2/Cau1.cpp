#include <stdio.h>
#include <math.h>
int Tinh(int n){
	if(n==0)
		return 0;
	return Tinh(n-1)+pow(-1,n)*n;
}

int main(){
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	printf("\nS = -1 + 2 - 3 + 4 + ... + (-1)^%d * %d = %d", n, n, Tinh(n));
	return 1;
}
