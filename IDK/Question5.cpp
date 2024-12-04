#include <stdio.h>


int main(){
    int num = test(5);
    printf("%d\n", num--);
    return 0;
}

int test(int num){
    return (num++);
}
