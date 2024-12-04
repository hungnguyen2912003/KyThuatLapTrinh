/*
Viết chương trình xử lý ma trận m×n các số nguyên

a) Viết các hàm

- Nhập ma trận;

- Xuất ma trận;

- Tính trung bình cộng của ma trận;

- Tìm phần tử lớn nhất trong ma trận;

- Tìm phần tử lớn nhất trên dòng i của ma trận (0 <=  i < m);

- Tìm phần tử lớn nhất trên cột j của ma trận (0<= j < n);

- Đếm số phần tử là số nguyên tố của ma trận;

- Sắp xếp ma trận sao cho trên mỗi hàng các phần tử có thứ tự tăng dần (sắp xếp các phần tử của mỗi hàng).
*/

#include <stdio.h>
#include <math.h>
#define Maxc 50
#define Maxd 50

void NhapMang(int a[][Maxc], int &m, int &n){
    printf("Nhap so dong cua mang: ");   scanf("%d", &m);
    printf("Nhap so cot cua mang: ");    scanf("%d", &n);
    for(int i = 0; i<m; i++)
        for(int j = 0; j<n; j++){
            printf("a[%d][%d] = ", i,j);
            scanf("%d", &a[i][j]);
        }
}
//Xuất ma trận;
void XuatMang(int a[][Maxc], int m, int n){
    for(int i = 0; i<m; i++){
        printf("\n");
        for(int j = 0; j<n; j++)
            printf("\t%d", a[i][j]);
    printf("\n");
    }
}
//Tính trung bình cộng của ma trận;
float TBC(int a[][Maxc], int m, int n){
    int sum = 0;
    int dem = 0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            sum+=a[i][j];
            dem++;
        }
    float tbc = (float)sum/dem;
    return tbc;
}
//Tìm phần tử lớn nhất trong ma trận;
int PTLN(int a[][Maxc], int m, int n){
    int Max = a[0][0];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(Max<a[i][j])
                Max = a[i][j];
    return Max;
}
//Tìm phần tử lớn nhất trên dòng i của ma trận (0 <=  i < m);
int PTLN_Dongi(int a[][Maxc], int n, int k){
    int Max = a[0][0];
    for(int i=0;i<n;i++)
        if(Max<a[k][i])
            Max = a[k][i];
    return Max;   
}
//Tìm phần tử lớn nhất trên cột j của ma trận (0<= j < n);
int PTLN_Cotj(int a[][Maxc], int m, int h){
    int Max = a[0][0];
    for(int j=0;j<m;j++)
        if(Max<a[j][h])
            Max = a[j][h];
    return Max;   
}
//Đếm số phần tử là số nguyên tố của ma trận;
bool KTSNT(int n){
    if(n<2) return false;
    else
        for(int i=2; i<=sqrt(n); i++)
            if(n%i==0)  return false;
        return true;
}

int Count_SNT(int a[][Maxc], int m, int n){
    int dem = 0;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            if(KTSNT(a[i][j])==true)
                dem++;
    return dem;
}

void InSNT(int a[][Maxc], int m, int n){
    printf("Cac so nguyen to trong mang: ");
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            if(KTSNT(a[i][j])==true)
                printf("%d ", a[i][j]);
}
//Sắp xếp ma trận sao cho trên mỗi hàng các phần tử có thứ tự tăng dần (sắp xếp các phần tử của mỗi hàng).
void SapXepMangTangDan(int a[][Maxc], int m, int n){
    int i, j, k = 0;
    int b[Maxd*Maxc];
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            b[k] = a[i][j];
            k++;
        }
    }
    int temp;
    for(int t = 0; t < k-1; t++){
        for(int r = t+1; r < k; r++)
            if(b[t]>b[r]){
                temp = b[t];
                b[t] = b[r];
                b[r] = temp;
            }
    }
    k = 0;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            a[i][j] = b[k];
            k++;
        }
    }
}


int main(){
    int a[Maxd][Maxc], m,n;
    int i, j;
    NhapMang(a,m,n);
    XuatMang(a,m,n);
    printf("\nTrung binh cong cua ma tran: %.2f", TBC(a,m,n));
    printf("\nPhan tu lon nhat cua ma tran: %d", PTLN(a,m,n));
    printf("\n----------------------------------------\n");
    do{
    printf("Nhap dong i cua ma tran (0 <= i < %d): ", m);    scanf("%d", &i);
    }while(!(i>=0 && i<m));
    printf("Phan tu lon nhat tren dong %d cua ma tran: %d", i, PTLN_Dongi(a,n,i));
    printf("\n----------------------------------------\n");
    do{
    printf("Nhap cot j cua ma tran (0 <= j < %d): ",n);    scanf("%d", &j);
    }while(!(j>=0 && j<n));
    printf("Phan tu lon nhat tren cot %d cua ma tran: %d", j, PTLN_Cotj(a,m,j));
    printf("\n----------------------------------------\n");
    printf("So phan tu la so nguyen to trong mang: %d\n", Count_SNT(a,m,n));
    InSNT(a,m,n);
    printf("\n----------------------------------------\n");
    printf("Ma Tran truoc khi sap xep\n");
    XuatMang(a,m,n);
    SapXepMangTangDan(a,m,n);
    printf("\nMa Tran sau khi sap xep\n");
    XuatMang(a,m,n);
    return 1;
}