#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void handler(int signal)
{
	printf("Signal SIGUSR1 Received!\n");
	exit(0);
}

int main() 
{
	signal(SIGUSR1, handler);

	printf("PID: %d\n", getpid());

	while (1) 
	{
		sleep(1);
	}

	return 0;
}
