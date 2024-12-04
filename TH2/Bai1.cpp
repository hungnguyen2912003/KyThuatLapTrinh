#include <stdio.h>
#include <math.h>

/*
a. f(x, n) = x^n, với x là số thực, n là số nguyên.
*/
//Khong de quy
float LuyThua(float x, int n){
    return pow(x,n);
}
//De Quy
float LuyThua_DQ(float x, int n){
    if(n==1)
        return x;
    else
        return LuyThua_DQ(x,n-1)*n;
}

/*
b. f(n) = n!, với n ≥ 0.
*/
//Khong de quy
int GiaiThua(int n){
    int giaithua =1;
    for (int i = 1; i <= n; i++)
    {
        giaithua *= i;
    }
    return giaithua;
}
//De Quy
int GiaiThua_DQ(int n){
    if(n==1)
        return 1;
    else
        return (n*GiaiThua_DQ(n-1));
}

/*
c. s(n) = 1 + 2 + ... + n, với n ≥ 0. 
*/
//Khong de quy
int Tong(int n){
    int s = 0;
    for(int i = 0; i<=n; i++){
        s += i;
    }
    return s;
}

/*

d. s(n) =  1 + 3 + 5 + ... + (2n - 1), với n ≥ 0.
*/
//Khong de quy
int TongSoLe(int n){
    int s = 0;
    for(int i = 1; i<=n; i+=2)
        s+=i;
    return s;
}

/*
e. s(n) =  2 + 4 + 6 + ... + (2n), với n ≥ 0.
*/
//Khong de quy
int TongSoChan(int n){
    int s = 0;
    for(int i = 2; i<=n; i+=2)
        s+=i;
    return s;
}

/*
f. Tính tổng các số nguyên tố <= n, với n là số nguyên dương.
*/
bool KT_SNT(int n){
    if(n<2) return false;
    else{
        for(int i = 2; i<=sqrt(n); i++)
            if(n%i == 0)
                return false;
        return true;
    }
}

int Sum_SNT(int n){
    int sum = 0;
    for(int i=0; i<=n; i++)
        if(KT_SNT(i)==true)
            sum += i;
    return sum;
}

/*
g. Đếm số nguyên tố <= n, với n là số nguyên dương.
*/
int DemSNT(int n){
    int dem = 0;
    for(int i = 0; i<=n; i++)
        if(KT_SNT(i)==true)
            dem++;
    return dem;
}

void InSNT(int n){
    printf("Cac so nguyen to do la: ");
    for(int i = 0; i<=n; i++)
        if(KT_SNT(i)==true)
            printf("%d ", i);
}

int main(){
    float x; 
    int n;
    printf("Nhap so x: ");  scanf("%f", &x);
    printf("Nhap so n: ");  scanf("%d", &n);
    printf("f(%.1f,%d) = %.1f^%d = %.1f", x, n, x, n, LuyThua(x,n));
    printf("\nf(%d) = %d! = %d", n, n, GiaiThua(n));
    printf("\ns(%d) = 1 + 2 + ... + %d = %d", n, n, Tong(n));
    printf("\ns(%d) = 1 + 3 + 5 + ... + (2*%d - 1) = %d", n, n, TongSoLe(n));
    printf("\ns(%d) = 2 + 4 + 6 + ... + (2*%d) = %d", n, n, TongSoChan(n));
    printf("\nTong cac so nguyen to: %d", Sum_SNT(n));
    printf("\nCac so nguyen to la: %d\n", DemSNT(n));
    InSNT(n);
}