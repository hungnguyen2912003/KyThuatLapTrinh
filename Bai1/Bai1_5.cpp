/*
Viết hàm trộn 2 mảng một chiều các số nguyên đã được sắp xếp tăng dần thành một mảng cũng tăng dần 
mà không cần thực hiện sắp xếp mảng.
*/

#include <stdio.h>
#define Max 50

void HoanVi(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

void SapXepMang(int a[], int n){
    for(int i=0;i<n-1;i++){
        for(int j = i+1; j<n;j++)
            if(a[i]>a[j])
                HoanVi(a[i],a[j]);
    }    
}

void GopMang(int a[], int na, int b[], int nb, int c[], int &nc){
    nc = 0;
    for(int i = 0; i < na; i++){
        c[nc] = a[i];
        nc++;
    }
    for(int i = 0; i < nb; i++){
        c[nc] = b[i];
        nc++;
    }
    SapXepMang(c,nc);
}

int main(){
    int a[Max], b[Max], c[Max];
    int na, nb, nc;
    printf("Mang A\n");
    printf("Nhap so luong phan tu cua mang A: ");
    scanf("%d", &na);
    for(int i=0;i<na;i++){
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    printf("Mang A vua nhap: ");
    for(int i=0;i<na;i++)
        printf("%d ", a[i]);
    SapXepMang(a,na);
    printf("\nMang A sau khi sap xep cac phan tu tang dan: ");
    for(int i=0;i<na;i++)
        printf("%d ", a[i]);
    printf("\n--------------------------------------------------\n");
    printf("Mang B\n");
    printf("Nhap so luong phan tu cua mang B: ");
    scanf("%d", &nb);
    for(int i=0;i<nb;i++){
        printf("b[%d] = ", i);
        scanf("%d", &b[i]);
    }
    printf("Mang B vua nhap: ");
    for(int i=0;i<nb;i++)
        printf("%d ", b[i]);
    SapXepMang(b,nb);
    printf("\nMang B sau khi sap xep cac phan tu tang dan: ");
    for(int i=0;i<nb;i++)
        printf("%d ", b[i]);
    printf("\n-------------------------------------------------\n");
    printf("Mang C sau khi tron: ");
    GopMang(a,na,b,nb,c,nc);
    for(int i=0;i<nc;i++)
        printf("%d ", c[i]);
}