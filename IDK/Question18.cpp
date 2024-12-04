#include <stdio.h>

int GiaiThua(int n){
    int i;
    long kq = 1;
    for (i = 1; i <= n; i++)    kq*=i;
        return kq;    
}

int main(){
    int n;
    printf("Nhap n: "); scanf("%d", &n);\
    printf("Giai thua cua n: %d", GiaiThua(n));
}