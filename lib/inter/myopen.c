#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>
#include <string.h>
#include "myopen.h"
int count_num(char *str)
{
	int i,cnt=0;
	int flag=0;
	for(i = 0; i < 50; i++)
	{
		if(str[i] == 0)
			return cnt;
		if(flag == 0)
		{
			if(str[i]<='9'&&str[i]>='0'){
				flag = 1;
				cnt ++;
			}
		}
		else if(str[i]==' '||str[i]=='\n')
			flag = 0;
	}
	return cnt;
}
void atoiarray(char *buf, double *num, int cnt)
{
	int i = 0;
	char *temp;
	num[i] = atof(strtok(buf," "));
	if(cnt == 1)
		return;
	for(i = 1; i < cnt; i++)
	{
		temp=strtok(NULL," ");
		while(!(temp[0]<='9' && temp[0]>='0'))
		{
			temp = strtok(NULL," ");
		}
		num[i] = atof(temp);
	}

}
void myopen(double **num, int *retncnt, double **den, int *retdcnt)
{
	
	char buf[50]={0,};
	char dbuf[50]={0,};
	int i,ncnt,dcnt;

	printf("Insert Numerator\n");
	getchar();
	fgets(buf,sizeof(buf),stdin);
	ncnt = count_num(buf);
	*num = (double *)malloc(sizeof(double)*ncnt);
	atoiarray(buf,*num,ncnt);
	printf("Insert Denomenator\n");
	fgets(buf,sizeof(buf),stdin);
	dcnt = count_num(buf);
	*den = (double *)malloc(sizeof(double)*dcnt);
	atoiarray(buf,*den,dcnt);
/*
	for(i = 0; i < ncnt; i++)
	{
		if(i == (ncnt-1))
			printf("%.2lf \n",*num[i]);
		else
			printf("%.2lfs^%d +",*num[i],(ncnt-i-1));

	}
	printf("----------------------------------------------\n");

	for(i = 0; i < dcnt; i++)
	{
		if(i==(dcnt-1))
			printf("%.2lf \n",*den[i]);
		else
			printf("%.2lfs^%d +",*den[i],(dcnt-i-1));
	}
*/
	printf("return\n");
	*retncnt = ncnt;
	*retdcnt = dcnt;
	printf("%d %d\n",*retncnt,*retdcnt);
	return;
}

