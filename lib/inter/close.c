#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>
#include <string.h>
#include "open.h"

void close(void)
{
	
	double complex z1 = I;
	char buf[50];
	int i,ncnt,dcnt,hncnt,hdcnt;
	double *num, *den, *hnum, *hden;
	printf("Insert Plant's Numerator\n");
	fflush(stdin);
	fgets(buf,sizeof(buf),stdin);
	ncnt = count_num(buf);
	num = (double *)malloc(sizeof(double)*ncnt);
	atoiarray(buf,num,ncnt);
	printf("Insert Plant's Denomenator\n");
	fflush(stdin);
	fgets(buf,sizeof(buf),stdin);
	dcnt = count_num(buf);
	den = (double *)malloc(sizeof(double)*dcnt);
	atoiarray(buf,den,dcnt);

	printf("Insert Controller's Numerator\n");
	fflush(stdin);
	fgets(buf,sizeof(buf),stdin);
	hncnt = count_num(buf);
	hnum = (double *)malloc(sizeof(double)*hncnt);
	atoiarray(buf,hnum,ncnt);
	printf("Insert Controller's Denomenator\n");
	fflush(stdin);
	fgets(buf,sizeof(buf),stdin);
	hdcnt = count_num(buf);
	hden = (double *)malloc(sizeof(double)*hdcnt);
	atoiarray(buf,hden,dcnt);
	for(i = 0; i < ncnt; i++)
	{
		if(i == (ncnt-1))
			printf("%f \n");
		else
			printf("%fs^%d +",num[i],(ncnt-i-1));

	}
	printf("----------------------------------------------\n");

	for(i = 0; i < dcnt; i++)
	{
		if(i==(dcnt-1))
			printf("%f \n");
		else
			printf("%fs^%d +",den[i],(dcnt-i-1));
	}
	return 0;
}

int main(void)
{
	close();
	return 0;
}
