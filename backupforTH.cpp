#include <stdio.h>
#include <math.h>
#define Max 50

void NhapMang(int a[], int &n){
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

void Xuatmang(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}

void xoaPhanTu(int a[], int &n, int vt){
    if(vt>=0 && vt<n)
    {
        for(int i = vt; i < n - 1; i++)
            a[i] = a[i+1];
        n--;
    }
}

void gopMang(int a[], int na, int b[], int nb, int c[], int &nc){
    nc = 0;
    for(int i = 0; i < na; i++)
    {
        c[nc] = a[i];
        nc++;
    }
    for(int i = 0; i < nb; i++)
    {
        c[nc] = a[i];
        nc++;
    }
}