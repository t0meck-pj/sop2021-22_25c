#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void uchwyt(int signal)
{
	exit(0);
}
int main() 
{
	signal(SIGUSR1, uchwyt);
	printf("PID: %d\n", getpid());
	while(1) 
	{
		sleep(1);
	}
	return 0;
}