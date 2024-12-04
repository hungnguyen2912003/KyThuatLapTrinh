#include <stdio.h>
#define Max 50

void DocMangTuFile(char fname[], int a[], int &n)
{
	FILE *p;
	p = fopen(fname, "rt");
	if(p == NULL)
		printf("File khong ton tai!");
	else
	{
		fscanf(p, "%d", &n);
		for(int i = 0; i < n; i++)
			fscanf(p, "%d", &a[i]);
		fclose(p);
	}	
}

void GhiMangVaoFile(char fname[], int a[], int n)
{
	FILE *p;	
	p = fopen(fname, "wt");
	if(p == NULL)
		printf("File khong ton tai!");
	else
	{
		fprintf(p, "%d\n", n);
		for(int i = 0; i < n; i++)
			fprintf(p, "%d ", a[i]);
		fclose(p);
	}
}

void XuatMang(int a[], int n)
{
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
}

void SapXepMang(int a[], int n)
{
	for(int i = 0; i < n-1; i++)
		for(int j = i+1; j < n; j++)
			if(a[i]>a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
}

int main()
{
	int a[Max], n;
	char fname[] = "E:\\VSProjects\\KTLT\\File\\INPUT.txt";
	DocMangTuFile(fname, a, n);
	printf("Mang vua nhap la: ");
	XuatMang(a,n);
	SapXepMang(a,n);
	printf("\nMang vua sap xep tang dan la: ");
	XuatMang(a,n);
	char fname2[] = "E:\\VSProjects\\KTLT\\File\\OUTPUT.txt";
	GhiMangVaoFile(fname2,a,n);
}
