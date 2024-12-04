#include <stdio.h>
#include <math.h>

void DocFile(char fname[], int &a, int &b, int &c)
{
	FILE *p;
	p = fopen(fname, "rt");
	if(p == NULL)
		printf("Khong ton tai FILE!");
	else{
		fscanf(p, "%d", &a);
		fscanf(p, "%d", &b);
		fscanf(p, "%d", &c);
		fclose(p);
	}
}

void GhiFile(char fname2[], int a, int b, int c)
{
	FILE *p;
	p = fopen(fname2, "wt");
	if(p == NULL)
		printf("\nKhong ton tai FILE!");
	else
	{
		fprintf(p,"Phuong trinh bac 2 la: %dx^2 + %dx + %d = 0", a, b, c);
		int delta = pow(b,2) - 4*a*c;
			if(a==0)
				fprintf(p,"\nNghiem phuong trinh: x = %.2f", (float)-c/b);
			else
			{
				if(delta<0)
					fprintf(p,"\nPhuong trinh vo nghiem");
				if(delta==0)
					fprintf(p,"\nPhuong trinh co nghiem kep: x1 = x2 = %.2f", (float)-b/(2*a));
				if(delta>0){
					fprintf(p,"\nPhuong trinh co 2 nghiem la: ");
					fprintf(p,"x1 = %.2f va x2 = %.2f", (float)(-b+sqrt(delta))/(2*a), (float)(-b-sqrt(delta))/(2*a));
				}
			}
		fclose(p);
	}
}

int main(){
	int a, b, c;
	char fname[] = "d:\\INPUT.txt";
	DocFile(fname, a, b, c);
	printf("Phuong trinh bac 2 la: %dx^2 + %dx + %d = 0", a, b, c);
	char fname2[] = "d:\\OUTPUT.txt";
	GhiFile(fname2, a, b, c);
}
