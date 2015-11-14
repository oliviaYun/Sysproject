#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <termio.h>
#define LOOPMAX 100  
#define size_t unsigned int
void *bairstow(double *equ, double *arroot_R, double **arroot_I, size_t size, double Accuracy);
int getch()
{
	int ch;
	struct termios buf;
	struct termios save;
	tcgetattr(0, &save);
	buf = save;
	buf.c_lflag &= ~(ICANON|ECHO);
	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;
	tcsetattr(0, TCSAFLUSH, &buf);
	ch = getchar();
	tcsetattr(0,TCSAFLUSH, &save);
	return ch;
}
void main()
{
	int i;
	unsigned int EqnSize=0;
	double *Eqn; //방정식 나타내기 위한 배열
	double *Roots; //근의 배열
	double **Roots_I; //허근의 배열
	int countreal=0;//실근과 허근의 개수를 새는 변수
	int countimg=0;

	printf("방정식의 차수를 입력하세요(1차는 넣을 수 없습니다.):");
	scanf("%d",&EqnSize);
	if (EqnSize == 1)
	{
		exit(0);
	}//1차 방정식은 손으로도 풀 수 있으므로 풀 지 않는다.
	printf("\n");

	Eqn = (double *)calloc(EqnSize+1,sizeof(double)); //방정식 입력을 위한 동적 메모리 할당. +1은 0차항도 더해주기 위함.
	Roots = (double *)calloc(EqnSize,sizeof(double));
	Roots_I = (double **)calloc(EqnSize,sizeof(double));//근의 개수 = 방정식의 차수

	for (i=0; i<EqnSize;i++)
	{
		Roots_I[i] =  (double *)calloc(2,sizeof(double));
	}

	printf("높은 차수의 계수부터 입력하세요.(0차항은 0이되어선 안됩니다.)\n");
	for (i=0; i<=EqnSize; i++)
	{
		printf("%d차항:",EqnSize-i);
		scanf("%lf",&Eqn[i]);
		if (Eqn[0] ==0)
		{ 
			exit(0);
		}
	}


	bairstow(Eqn,Roots,Roots_I,EqnSize,pow(0.1,10)); // 근을 찾는 함수 실행

	for (i=0; i<EqnSize;i++){
		if (Roots[i]==0)
		{
			continue;
		}
		printf("%d번째 실근=%7.4f\n",countreal+1,Roots[i]);
		countreal++;
	}
	countreal=0;//다시 재 초기화
	for (i=0; i<EqnSize;i++){
		if (Roots_I[i][0]==0)
		{
			continue;
		}
		printf("%d번째 허근=%7.4f+(%7.4fi)\n",countimg+1,Roots_I[i][0],Roots_I[i][1]);
		countimg++;
	}
	countimg=0;//다시 재 초기화
	getch();
	free(Eqn);
	free(Roots); //동적 메모리 해제

	for (i=0; i<EqnSize;i++){
		free(Roots_I[i]);
	}
	free(Roots_I);

}


void *bairstow(double *equ, double *arroot_R, double *arroot_I[2], size_t size, double Accuracy)
{

	int i,j,k;
	double r,s;
	double r_last,s_last;
	double dr,ds;
	double *b;
	double *c;
	double *buffer_b;
	int countzero=0;
	//각각의 필요한 변수를 설정. buffer_b는 b의 예전 내용을 집어넣는 배열이다. 
	//2차방정식을 분리하고 남은 식을 저장하는데 사용한다.

	unsigned int n,m;          //함수내에서만 사용할 수 있는 지역변수 선언

	buffer_b = (double *)calloc(size+1,sizeof(double));
	memcpy(buffer_b,equ,(size+1)*sizeof(double));

	for(i=0;i<=size;i++)
	{
		if (buffer_b[i]==0)
		{
			buffer_b[i]+=pow(10,-8);
			countzero++;
		}
	} 
	//계수에 0이 나올 때 렉 방지.


	n=size;
	m=size; //size를 그대로 쓸 수 없기 때문에 그것을 m,n에 집어넣어서 변수로 다룸
	b = (double *)calloc(n+1,sizeof(double));
	c = (double *)calloc(n+1,sizeof(double)); //b와 c배열의 크기를 동적 할당

	for (j=0;j<(n/2);j++)
	{
		r_last=(-1)*(buffer_b[1])/(buffer_b[0]);
		s_last=(-1)*(buffer_b[2])/(buffer_b[0]);//r0,s0를 설정

		if (m==2 && j==0)
		{
			r=r_last;
			s=s_last;

			if((r*r+4*s)>0) // 이차식이 두개의 실근을 가진다면
			{
				arroot_R[2*j]=(r/2)+(sqrt(r*r+4*s)/2);
				arroot_R[2*j+1]=(r/2)-(sqrt(r*r+4*s)/2);
			} 
			else if ((r*r+4*s)==0) //이차식이 1개의 중근을 가진다면
			{
				arroot_R[2*j]=(r/2);
				arroot_R[2*j+1]=(r/2);
			} 
			else if ((r*r+4*s)<0) //이차식이 두개의 허근을 가지고 있다면
			{
				arroot_I[2*j][0]=(r/2);
				arroot_I[2*j][1]=(-1)*(sqrt((-1)*(r*r+4*s))/2);
				arroot_I[2*j+1][0]=(r/2);
				arroot_I[2*j+1][1]=(sqrt((-1)*(r*r+4*s))/2);
			}
		}

		else if (m==2 && j!=0)
		{
			r=(-1)*(b[1])/(b[0]);
			s=(-1)*(b[2])/(b[0]);

			if((r*r+4*s)>0) // 이차식이 두개의 실근을 가진다면
			{
				arroot_R[2*j]=(r/2)+(sqrt(r*r+4*s)/2);
				arroot_R[2*j+1]=(r/2)-(sqrt(r*r+4*s)/2);
			} 
			else if ((r*r+4*s)==0) //이차식이 1개의 중근을 가진다면
			{
				arroot_R[2*j]=(r/2);
				arroot_R[2*j+1]=(r/2);
			} 
			else if ((r*r+4*s)<0) //이차식이 두개의 허근을 가지고 있다면
			{
				arroot_I[2*j][0]=(r/2);
				arroot_I[2*j][1]=(-1)*(sqrt((-1)*(r*r+4*s))/2);
				arroot_I[2*j+1][0]=(r/2);
				arroot_I[2*j+1][1]=(sqrt((-1)*(r*r+4*s))/2);
			}
		}

		for(k=0;k<=LOOPMAX;k++)
		{

			for (i=0; i<=m; i++)
			{
				if (i==0)
				{
					b[i]=buffer_b[i];
				}
				else if (i==1)
				{
					b[i]=buffer_b[i]+(r_last)*(b[i-1]);
				}
				else
				{
					b[i]=buffer_b[i]+(r_last)*(b[i-1])+(s_last)*(b[i-2]);
				}
			}//b[0]=b1, b[n]=bn+1

			for (i=0; i<=m; i++)
			{
				if (i==0)
				{
					c[i]=b[i];
				}
				else if (i==1)
				{
					c[i]=b[i]+(r_last)*(c[i-1]);
				} 
				else 
				{
					c[i]=b[i]+(r_last)*(c[i-1])+(s_last)*(c[i-2]);
				}
			} //c[0]=c1, c[n-1]=cn  ck와 bk에 각각의 값을 대입하는 일.


			dr=((b[m-1])*(c[m-2])-(b[m])*(c[m-3]))/((c[m-1])*(c[m-3])-(c[m-2])*(c[m-2]));
			ds=((b[m])*(c[m-2])-(b[m-1])*(c[m-1]))/((c[m-1])*(c[m-3])-(c[m-2])*(c[m-2]));

			if ((int)dr==0 && (int)ds==0)
			{
				break;
			} 
			//ds, dr 둘 중 하나라도 0이 아닌 값이 나오면 진행할 수 있지만
			//둘 다 0이 나오면 r이나 s가 0이 나와 뒤의 if문이 진행되지 못해 렉이 걸릴 수 있기 때문에 종료할 수 밖에 없다.

			r=r_last+dr;
			s=s_last+ds;
			if((fabs((ds/s))<Accuracy) && (fabs((dr/r))<Accuracy))
			{
				break;
			}// 연산의 정확도가 어느 정도로 만족하면 연산을 중지한다.

			if(k==LOOPMAX)
			{
				printf("\n근을 정확하게 구하기 힘드네요,,반복 연산수를 늘려주세요!\n\n");
				return 0;
			}//어느정도 루프를 돌아도 정확도에 만족하지 못한 근을 구한 경우 계산을 중지한다.

			r_last=r;
			s_last=s;


		} //r과 s를 Bairstow법에 의해 구할 수 있는 연산을 반복시행.


		if((r*r+4*s)>0) // 이차식이 두개의 실근을 가진다면
		{
			arroot_R[2*j]=(r/2)+(sqrt(r*r+4*s)/2);
			arroot_R[2*j+1]=(r/2)-(sqrt(r*r+4*s)/2);
		} 
		else if ((r*r+4*s)==0) //이차식이 1개의 중근을 가진다면
		{
			arroot_R[2*j]=(r/2);
			arroot_R[2*j+1]=(r/2);
		} 
		else if ((r*r+4*s)<0) //이차식이 두개의 허근을 가지고 있다면
		{
			arroot_I[2*j][0]=(r/2);
			arroot_I[2*j][1]=(-1)*(sqrt((-1)*(r*r+4*s))/2);
			arroot_I[2*j+1][0]=(r/2);
			arroot_I[2*j+1][1]=(sqrt((-1)*(r*r+4*s))/2);
		}

		m=m-2;
		memcpy(buffer_b,b,(m+1)*sizeof(double));
	}

	if (n%2==1)// 방정식의 차수가 홀수차이면 일차식에 의한 실근이 나오므로 그것에 관한 설정
	{
		arroot_R[n-1]=(-1)*(b[1])/(b[0]);//맨 마지막 루프에서 남은 일차식을 가지고 마지막 하나의 실근을 결정한다.
		free(c);
		free(b);
		free(buffer_b);//동적 메모리 할당 해제
		return 0;
	} else
	{
		free(c);
		free(b);
		free(buffer_b);//동적 메모리 할당 해제
		return 0;
	}
}
