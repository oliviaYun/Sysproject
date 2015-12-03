#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>
#include <string.h>
#include "myopen.h"
#include "myclose.h"
void myclose(double **num, int *retncnt, double **den, int *retdcnt, double **hnum, int *rethncnt, double **hden, int *rethdcnt)
{
	
	char buf[50]={0,};
	char dbuf[50]={0,};
	int i,ncnt,dcnt,hncnt,hdcnt;

	fflush(stdin);
	printf("Insert Plant Numerator\n");
	fflush(stdin);
	fgets(buf,sizeof(buf),stdin);
	ncnt = count_num(buf);
	*num = (double *)malloc(sizeof(double)*ncnt);
	atoiarray(buf,*num,ncnt);
	printf("Insert Plant Denomenator\n");
	fflush(stdin);
	fgets(buf,sizeof(buf),stdin);
	dcnt = count_num(buf);
	*den = (double *)malloc(sizeof(double)*dcnt);
	atoiarray(buf,*den,dcnt);
	printf("Insert Controller Numerator\n");
	fflush(stdin);
	fgets(buf,sizeof(buf),stdin);
	hncnt = count_num(buf);
	*hnum = (double *)malloc(sizeof(double)*hncnt);
	atoiarray(buf,*hnum,hncnt);
	printf("Insert Controller Denomenator\n");
	fflush(stdin);
	fgets(buf,sizeof(buf),stdin);
	hdcnt = count_num(buf);
	*hden = (double *)malloc(sizeof(double)*hdcnt);
	atoiarray(buf,*hden,hdcnt);

	*retncnt = ncnt;
	*retdcnt = dcnt;
	*rethncnt = hncnt;
	*rethdcnt = hdcnt;

	return;
}

