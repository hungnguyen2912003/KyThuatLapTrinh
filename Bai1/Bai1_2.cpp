/*
Viết chương trình xử lý mảng 1 chiều các số nguyên

a) Viết các hàm sau:

- Nhập mảng;

- Xuất mảng;

- Hàm in các các phần tử là số nguyên tố;

- Hàm in ra các phần tử là số chính phương;

- Hàm in ra các phần tử > giá trị trung bình của mảng;

- Hàm trả về phần tử lớn nhất của mảng;

- Hàm boolean kiểm tra mảng đã được sắp xếp tăng dần chưa;

- Hàm sắp xếp mảng tăng dần;

- Hàm sắp xếp mảng giảm dần.

b) Chương trình chính:

Minh họa các hàm trên.
*/

#include <stdio.h>
#include <math.h>
#define Max 50
void NhapMang(int a[], int &n){
    printf("Nhap so luong mang: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}
void XuatMang(int a[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int KTSCP(int n){
	int m = (int)sqrt(n);

	if(n<0)
		return 0;
    if(n==m*m)
        return 1;
    return 0;
}

int maxSCP(int a[], int n){
    int max = a[0];
    int dem = 0;
    for(int i = 0; i<=n; i++)
        if(KTSCP(a[i])==1){
            dem++;
            if(max<a[i])
                max = a[i];
        }
    if(dem==0)
        return -1;
    return max;
}
int main(){
    int a[Max], n;
    NhapMang(a,n);
    XuatMang(a,n);
    if(maxSCP(a,n)==-1)
        printf("\nMang khong co so chinh phuong");
    else
        printf("\nSo chinh phuong lon nhat la: %d", maxSCP(a,n));
}