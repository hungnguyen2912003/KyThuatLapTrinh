#include <stdio.h>

int TinhTong(int a, int b){
    int Max;
    if(a<b)
        Max = b;
    else
        Max = a;
    return Max;
}

int main(){
    printf("%d", TinhTong(5,10));
    return 0;
}  