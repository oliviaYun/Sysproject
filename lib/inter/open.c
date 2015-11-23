#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>
#include <string.h>
#include "open.h"
int count_num(char *str)
{
	int i,cnt=0;
	int flag=0;
	for(i = 0; i < 50; i++)
	{
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
void open(void)
{
	
	double complex z1 = I;
	char buf[50];
	int i,ncnt,dcnt;
	double *num, *den;
	fflush(stdin);
	printf("Insert Numerator\n");
	fflush(stdin);
	fgets(buf,sizeof(buf),stdin);
	ncnt = count_num(buf);
	num = (double *)malloc(sizeof(double)*ncnt);
	atoiarray(buf,num,ncnt);
	printf("Insert Denomenator\n");
	fflush(stdin);
	fgets(buf,sizeof(buf),stdin);
	dcnt = count_num(buf);
	den = (double *)malloc(sizeof(double)*dcnt);
	atoiarray(buf,den,dcnt);

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

