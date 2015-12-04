#include <stdio.h>
#include <stdlib.h>
#include "bode.h"
#include "callshell.h"
#include "gtk2.h"
#include "Nyquistgtk.h"
//#include "nyquist.h"

//0 : G, 1: GH
//0 : openloop, 1: closed loop
void Bode_main(int argc, char *argv[], int p, int l)
{
	bode(p-1,l-1);
        bodeplot("lib/disp/bode.sh");
        gtk2(argc, argv);
}
void Nyquist_main(int argc, char *argv[],int p, int l)
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

		clearTerm();
		printf("Choose the graph you want to see the result \n");
		printf("1.Nyquist 2.Bode plot\n");
		scanf("%d",&NorB);
		fflush(stdin);//buffer clear
		
		clearTerm();
		printf("Choose plant(G) or plant&controller(GH)\n");
		printf("1.Plant(G) 2.Plant(G)&Controller(GH)\n");
		scanf("%d",&plant);
		fflush(stdin);
		
		clearTerm();
		printf("Choose the the loop\n");
		printf("1.Open loop 2.Closed loop\n");
		scanf("%d",&loop);
		fflush(stdin);
		
		clearTerm();
		printf("Please wait for the result!!\n");
		fflush(stdin);
		if(NorB == 1)//Nyquist
		{
			Nyquist_main(argc,argv,plant,loop);
		}
		else if(NorB == 2)//Bodeplot
		{
			Bode_main(argc,argv,plant,loop);
		}
		else
		{
			printf("Wrong input!\n");
		}
	
	//bode(0,0);
	//bodeplot("lib/disp/bode.sh");
	//gtk2(argc, argv);
}
