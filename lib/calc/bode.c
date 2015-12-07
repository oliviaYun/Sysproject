//compile like this! gcc -o test testfile.c -I../../inc/ -L. -lopen -lm
#include <stdio.h>
#include <stdlib.h>
#include "myopen.h"
#include "myclose.h"
#include <complex.h>
#include <tgmath.h>

double complex devide (double complex x, double complex y){
	double complex z;
	z = (creal(x)*creal(y)+cimag(x)*cimag(y))/(creal(y)*creal(y)+cimag(y)*cimag(y));
	z+=((cimag(x)*creal(y)-creal(x)*cimag(y))/(creal(y)*creal(y)+cimag(y)*cimag(y)))*I;
	return z;
}

void bode(int status, int mode)
{
	FILE *fp;
	double *num, *den, *hnum, *hden, w;
	int retncnt, retdcnt,rethncnt,rethdcnt, i, j;
	double complex znum, zden, z,G,H,zhnum,zhden;
	double real;
	retncnt = 0; retdcnt = 0;
	if(status == 0)
		myopen(&num,&retncnt,&den,&retdcnt);
	else
		myclose(&num,&retncnt,&den,&retdcnt,&hnum,&rethncnt,&hden,&rethdcnt);
	printf("G is \n");
//	printf("ncnt : %d, dnct : %d\n",retncnt,retdcnt);
	for(i = 0; i < retncnt; i++)
	{
		printf("%.2f ^ %d + ",num[i],retncnt-i-1);
	}
	printf("\n-----------------\n");
	for(i = 0; i < retdcnt; i++)
	{
		printf("%.2f ^ %d + ",den[i],retdcnt-i-1);
	}
	printf("\n");
	
	if(status!=0)
	{
		printf("H is \n");
		for(i = 0; i < rethncnt; i++)
		{
			printf("%.2f ^ %d + ",hnum[i],rethncnt-i-1);
		}
		printf("\n-----------------\n");
		for(i = 0; i < rethdcnt; i++)
		{
			printf("%.2f ^ %d + ",hden[i],rethdcnt-i-1);
		}
		printf("\n");
	
	}
	fp = fopen("result.dat","w+");
	for(w = 0.1; w <10; w+=0.001)
	{
//		w = 1;
		znum = 0;
		zden = 0;
		zhnum = 0;
		zhden = 0;

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
		G = devide(znum,zden);
		if(status != 0)
		{	
			for(i = 0; i < rethncnt; i++)
			{
				if((rethncnt-i-1)==0)
					zhnum+=hnum[i];
				else
					zhnum+=hnum[i]*pow(w*I,rethncnt-i-1);
			}
			for(i = 0; i < rethdcnt; i++)
			{
				if((rethdcnt-i-1)==0)
					zhden+=hden[i];
				else
					zhden+=hden[i]*pow(w*I,rethdcnt-i-1);
			}
			H = devide(zhnum,zhden);		
		}
		double complex result;
		if(status == 0 && mode == 0)
			result = G;
		else if(status == 0 && mode == 1)
			result = devide(G,(1+G));
		else if(status == 1 && mode == 0)
			result = G*H;
		else if(status == 1 && mode == 1)
			result = devide(G, 1+G*H);
		else{
			printf("wrong parameters\n");
			exit(1);
		}	
		fprintf(fp,"%f %lf %lf\n",w,20*log10(cabs(result)),carg(result));
	}
}
