#include <stdio.h>

int filesize(FILE *p)
{
	fseek(p, 0, SEEK_END);
	return ftell(p);
}

int main()
{
	char fname[] = "d:\\Tiengthu_LuuTrongLu.txt";
	FILE *p = fopen(fname, "rb");
	if(p == NULL)
		printf("Khong ton tai FILE!");
	else
	{
		printf("Kich thuoc tap tin %s la %d Bytes", fname, filesize(p));
		fclose(p);
	}
}
