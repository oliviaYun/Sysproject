//compile like this! gcc -o test testfile.c -I../../inc/ -L. -lopen -lm

#include "open.h"
#include <complex.h>
#include <tgmath.h>


void main(void)
{
	double *num, *den, w;
	int ncnt, dcnt, i, j;
	double complex znum, zden, z;
	ncnt = 0; dcnt = 0;
	open(num,&ncnt,den,&dcnt);
	printf("ncnt : %d, dnct : %d",ncnt,dcnt);
	for(i = 0; i < ncnt; i++)
	{
		printf("%.2f ^ %d",num[i],ncnt-i);
	}
	printf("\n");
	for(w = 0; w <100; w+=0.01)
	{
		znum = 0;
		zden = 0;
		for(i = 0; i < ncnt; i++)
		{
			znum+=pow(num[i]*w*I,ncnt-i);
		}
		for(i = 0; i < dcnt; i++)
		{
			zden+=pow(den[i]*w*I,dcnt-i);
		}		
		z = znum/zden;
		printf("real : %.1f  imag : %.1f \n",creal(z),cimag(z));
	}
}
