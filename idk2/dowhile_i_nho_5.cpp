#include <stdio.h>

int main(){
    int i = 1;
    int S = 0;
    do
    {
        i++;
        S+=i;
    } while (i<5);
    printf("%d", S);
}

//14