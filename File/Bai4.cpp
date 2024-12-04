#include <stdio.h>
#include <math.h>

void DocFile(char fname[], float &a, float &b, float &c)
{
	FILE *p;
	p = fopen(fname, "rt");
	if(p == NULL)
		printf("Khong ton tai FILE!");
	else{
		while(!feof(p))
		{
		fscanf(p, "%f %f %f", &a, &b, &c);
		}
		fclose(p);
	}
}

void GhiFile(char fname2[], float a, float b, float c)
{
	FILE *p;
	p = fopen(fname2, "wt");
	if(p == NULL)
		printf("\nKhong ton tai FILE!");
	else
	{
		fprintf(p,"%.2f x^2 + %.2f x + %.2f = 0", a, b, c);
		int delta = pow(b,2) - 4*a*c;
		if(a==0 && b==0)
			fprintf(p,"\tVo so nghiem");
		if(delta<0)
			fprintf(p,"\tVo nghiem");
		if(delta==0)
			fprintf(p,"\tNghiem kep: x = %.2f", (float)-b/(2*a));
		if(delta>0)
			fprintf(p,"\tx1 = %.2f  x2 = %.2f", (float)(-b+sqrt(delta))/(2*a), (float)(-b-sqrt(delta))/(2*a));
	}
		fclose(p);
}

int main(){
	float a, b, c;
	char fname[] = "d:\\ptbac2.txt";
	DocFile(fname, a, b, c);
	char fname2[] = "d:\\kqptbac2.txt";
	GhiFile(fname2, a, b, c);
}
