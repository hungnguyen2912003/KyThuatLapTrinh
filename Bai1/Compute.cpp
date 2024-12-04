/*
Sử dụng cách truyền đối số cho hàm main viết & biên dịch chương trình có tên Compute.exe sao cho khi gọi chương trình từ dòng lệnh:

Compute a <op> b 

sẽ hiện ra kết quả của phép toán <op> tương ứng trên a và b (<op> = {'+', '-', '*', '/'}. 

Ví dụ:

Compute 7 * 3 cho kết quả là 7 * 3 = 21

Compute 7 - 3 cho kết quả là 7 - 3 = 4
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc == 4){
        int a = atoi(argv[1]);
        int b = atoi(argv[3]);
        char* op = argv[2];
        switch(*op)
            case '+':
                printf("%d + %d = %d", a, b, a+b);
            case '-':
            printf("%d - %d = %d", a, b, a-b);
        if(*op == '*')
            printf("%d * %d = %d", a, b, a*b);
        if(*op == '/'){
            if(b==0)
                printf("Loi chia het cho 0");
            else
                printf("%d / %d = %.1f", a, b, (float)a/b);
        }
        if(*op != '+' && *op != '-' && *op != '*' && *op != '/')
            printf("Khong the thuc hien phep tinh");
    }
    else
        printf("Truyen doi so sai!");
    return 1;
}