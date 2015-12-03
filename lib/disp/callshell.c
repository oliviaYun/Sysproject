#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int bodeplot(char *b_command)
{
	int result;
	if(fork()==0)
	{
		result = execl("/bin/bash","bash","-c",b_command,NULL);
		if(result == -1)
		printf("bash open error\n");
		exit(123);
	}
	else
	{
		wait();
	}
	return 0;
}
int nyquistplot(char *c_command)
{
	 if(fork()==0)
        {
                execl("/bin/bash","bash","-c",c_command,NULL);
                exit(123);
        }
        else
        {
                wait();
        }
	return 0;
}
/*
int main (void)
{
	int b_command;
	int n_command;
	//b_command = bodeplot("./bode.sh");
	n_command = nyquist("./nyquist.sh");
	return 0;
}
*/
