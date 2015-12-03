//compile like this! gcc -o test testfile.c -I../../inc/ -L. -lopen -lm
#include <stdio.h>
#include <stdlib.h>
#include "myopen.h"
#include <complex.h>
#include <tgmath.h>


void bode()
{
	FILE *fp;
	double *num, *den, w;
	int retncnt, retdcnt, i, j;
	double complex znum, zden, z;
	double real;
	retncnt = 0; retdcnt = 0;
	myopen(&num,&retncnt,&den,&retdcnt);
	printf("ncnt : %d, dnct : %d\n",retncnt,retdcnt);
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
	fp = fopen("result.txt","w+");
	for(w = 0.1; w <10; w+=0.001)
	{
//		w = 1;
		znum = 0;
		zden = 0;
		for(i = 0; i < retncnt; i++)
		{
			if((retncnt-i-1)==0)
				znum+=num[i];
			else
				znum+=num[i]*pow(w*I,retncnt-i-1);
		}
		for(i = 0; i < retdcnt; i++)
		{
			if((retdcnt-i-1)==0)
				zden+=den[i];
			else
				zden+=den[i]*pow(w*I,retdcnt-i-1);
		}		
		
		fprintf(fp,"%f %lf %lf\n",w,20*log10(cabs(znum))-20*log10(cabs(zden)),carg(znum)-carg(zden));
	}

}
