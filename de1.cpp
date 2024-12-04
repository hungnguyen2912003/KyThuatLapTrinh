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

int laSCP(int n){
    int m = (int)sqrt(n);
    if(n<1) 
        return 0;
    else{
        if(n == m*m) 
            return 1;
        return 0;
    }
}
int maxSCP(int a[], int n){
    int max = a[0];
    int count = 0;
    for(int i = 0; i <= n; i++){
        if(laSCP(a[i])==1){
            count++;
            if(max < a[i])
                max = a[i];
        }
    }
    if(count==0)
        return -1;
    return max;
}

void chenPhanTu(int a[],int &n,int x,int i){
    if(i>=0 && i<=n){
        for(int j=n;j>i;j--)
            a[j]=a[j-1];
        a[i]=x;
        n++;
    }
}

void chenPTLonNhat(int a[], int &n, int x){
    int max = 0;
    for(int i = 1; i < n; i++)
        if(a[i] > a[max])
            max = i;
    chenPhanTu(a,n,x,max+1);
}

void tachMang(int a[], int n, int mangDuong[], int &nchan, int mangam[] , int &nLe){
    nchan = 0;
    nLe = 0;
    for(int i = 0; i < n; i++)
        if(a[i]>0)
        {
            mangDuong[nchan] = a[i];
            nchan++;
        }
        else
        {
            mangam[nLe] = a[i];
            nLe++;
        }
}

int main(){
    int a[Max], n;
    int mangDuong[Max], nchan;
    int mangam[Max], nLe;
    NhapMang(a,n);
    printf("Mang vua nhap la: ");
    Xuatmang(a,n);
    if(maxSCP(a,n)==-1)
        printf("\nMang khong co so chinh phuong");
    else
        printf("\nSo chinh phuong lon nhat trong mang la: %d", maxSCP(a,n));
    int x,i;
    printf("\nNhap phan tu can chen: "); 
    scanf("%d",&x);
    printf("Nhap vi tri can chen: ");   
    scanf("%d",&i);
    chenPhanTu(a,n,x,i);
    printf("Mang sau khi chen la: ");
    Xuatmang(a,n);
    printf("\nNhap so can chen sau phan tu lon nhat: ");
    scanf("%d",&x);
    chenPTLonNhat(a,n,x);
    printf("Mang sau khi chen phan tu vao sau phan tu lon nhat: ");
    Xuatmang(a,n);
    tachMang(a,n,mangDuong,nchan,mangam,nLe);
    printf("\nMang chi co phan tu duong duoc tach ra tu mang chinh: ");
    Xuatmang(mangDuong,nchan);
    printf("\nMang chi co phan tu am duoc tach ra tu mang chinh: ");
    Xuatmang(mangam,nLe);
}
