#include <stdio.h>

int main(){
    int x = 5, y = x++;
    char c = '*';
    switch(c){
        case '+':   x +=y;
        case '-':   x-=y;
        default:    x+=1;
    }
    printf("%d %d", x, y);
}