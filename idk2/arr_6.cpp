#include <stdio.h>

int main(){
    int arr[6] = {2,3,5,7,13,21};
    int *ptr;
    ptr = &arr[0];
    ptr = ptr + 2;
    printf("%d", *ptr);
}

//5