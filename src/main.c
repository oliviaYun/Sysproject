#include <stdio.h>
#include <stdlib.h>
#include "bode.h"
#include "callshell.h"
#include "gtk2.h"
#include "Nyquistgtk.h"
#include "nyquist.h"
//0 : G, 1: GH
//0 : openloop, 1: closed loop

void Bode(int p, int l)
{
	//00
	//01
	//10
	//11

}

void Nyquist(int p, int l)
{
	//00
	//01
	//10
	//11

}
void clearTerm()
{
	system("clear");
}
void main(int argc, char *argv[])
{
	int NorB;
	int plant;
	int loop;
	while(1)
	{
		clearTerm();
		printf("Choose the graph you want to see the result \n");
		printf("1.Nyquist 2.Bode plot\n");
		scanf("%d",NorB);
		fflush(stdin);//buffer clear
		
		clearTerm();
		printf("Choose plant(G) or plant&controller(GH)\n");
		printf("1.Plant(G) 2.Plant(G)&Controller(GH)\n");
		scanf("%d",plant);
		fflush(stdin);
		
		clearTerm();
		printf("Choose the the loop\n");
		printf("1.Open loop 2.Closed loop");
		scanf("%d",loop);
		fflush(stdin);
		
		clearTerm();
		printf("Please wait for the result!!\n");
		if(NorB == 1)//Nyquist
		{
			Nyquist(plant,loop);
		}
		else//Bodeplot
		{
			Bode(plant,loop);
		}
	}
	//bode(0,0);
	//bodeplot("lib/disp/bode.sh");
	//gtk2(argc, argv);
}
