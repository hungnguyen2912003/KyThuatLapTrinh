#include <stdio.h>

int main(){
	FILE *p;
	p = fopen("d:\\Tiengthu_LuuTrongLu.txt", "rt");
	if(p == NULL)
		printf("Khong ton tai File!");
	else{
		while(!feof(p))
			printf("%c", fgetc(p));
		fclose(p);
	}
}
