#include <stdio.h>
#include <unistd.h>


int main(void)
{
	char buf[50];
	read(0,buf,50);
	write(1,buf,sizeof(buf));
	return 0;
}

