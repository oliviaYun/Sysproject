//compile like this! gcc -o test testfile.c -I../../inc/ -L. -lopen -lm
#include <stdio.h>
#include "open.h"
#include <complex.h>
#include <tgmath.h>


void main(void)
{
	double *num, *den, w;
	int retncnt, retdcnt, i, j;
	double complex znum, zden, z;
	double real;
	retncnt = 0; retdcnt = 0;
	open(&num,&retncnt,&den,&retdcnt);
//	printf("ncnt : %d, dnct : %d\n",retncnt,retdcnt);
	for(i = 0; i < retncnt; i++)
	{
		printf("%.2f ^ %d + ",num[i],retncnt-i);
	}
	printf("\n-----------------\n");
	for(i = 0; i < retdcnt; i++)
	{
		printf("%.2f ^ %d + ",den[i],retdcnt-i);
	}
	printf("\n");
	for(w = 0.1; w <1; w+=0.01)
	{
		znum = 0;
		zden = 0;
		for(i = 1; i < retncnt; i++)
		{
			znum+=pow(num[i]*w,retncnt-i)*pow(I,retncnt-i);
		}
		for(i = 1; i < retdcnt; i++)
		{
			zden+=pow(den[i]*w,retdcnt-i)*pow(I,retdcnt-i);
		}		
		z = znum/zden;
		
//		printf("real : %.1f  imag : %.1f \n",creal(z),cimag(z));
		real = creal(z);
//		double imag = cimag(z);
//		printf("real : %.1f imag : %.1f \n",creal(z),cimag(z));	
		//double mag = cabs(z);
		//double angle = carg(z);
	//	printf("%.3f, %3.f",cabs(z),carg(z));
	}

}
