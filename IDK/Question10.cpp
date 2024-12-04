#include <stdio.h>

int main(){
    int x;
    for(x=0;x<20;x++)
        if(x>10)
            break;
    printf("%d", x);
}