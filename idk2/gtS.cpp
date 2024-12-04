#include <stdio.h>
int main(){
    int i = 1;
    int S = 0;
    do
    {
        S += i;
        i++;
    } while (i>5);
    printf("%d", S);
}

//1