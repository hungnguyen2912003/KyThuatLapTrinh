/*Viết các chương trình sau đây bằng cả phương pháp đệ quy và không đệ quy:

a. Tính tổng các phần tử của mảng.

b. Tính tổng các phần tử >0 của mảng.

c. Đếm số lượng phần tử là số nguyên tố của mảng.

d. Tìm phần tử lớn nhất của mảng.*/

#include <stdio.h>

void NhapMang(int a[],int &n){
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

void XuatMang(int a[], int n){
    for(int i = 0; i < n; i++)
    printf("%d ", a[i]);
}

int tongpt(int a[], int n){
    int s = 0;
    for(int i = 0; i < n; i++)
        s+=a[i];
    return s;
}

int tongpt_lon0(int a[],int n){
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]>0)
            s+=a[i];
    }
    return s;
}

int ktraSNT(int n){
    if(n<2) return 0;
    else
        for (int i = 2; i <= n/2; i++)
            if(n%i==0)  return 0;
    return 1;
}

int countSNT(int a[], int n){
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(ktraSNT(a[i])==1)
            count++;
    }
    return count;
}

int ptlonnhat(int a[], int n){
    int Max = a[0];
    for (int i = 0; i < n; i++)
    {
        if(Max<a[i])
            Max = a[i];
    }
    return Max;
}

int main(){
    int a[50], n;
    NhapMang(a,n);
    XuatMang(a,n);
    printf("\nTong cac phan tu cua mang: %d\n", tongpt(a,n));
    printf("Tong cac phan tu lon hon 0 cua mang: %d\n", tongpt_lon0(a,n));
    printf("Cac so nguyen to trong mang: %d\n",countSNT(a,n));
    printf("Phan tu lon nhat trong mang: %d", ptlonnhat(a,n));
}