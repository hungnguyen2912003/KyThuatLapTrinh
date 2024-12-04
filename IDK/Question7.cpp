#include <stdio.h>

int function(int x, int y){
    return (x-(x==y));
}
//x==y là toán tử quan hệ để so sánh
// Nếu so sánh đúng trả về true có giá trị là 1, còn sai trả về false

int main(){
    int a = 10, b = 10, c;
    printf("%d", function(a,b));
    return 0;
}