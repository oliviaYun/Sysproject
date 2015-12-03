#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int bodeplot(char *b_command)
{
	if(fork()==0)
	{
		execl("/bin/bash","bash","-c",b_command,NULL);
		exit(123);
	}
	else
	{
		wait();
	}


}
int nyquist(char *c_command)
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
}

int main (void)
{
	int b_command;
	int n_command;
	b_command = bodeplot("./bode.sh");
	//n_command = nyquist("./nyquist.sh");
	return 0;
}
