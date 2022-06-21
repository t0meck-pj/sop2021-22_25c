#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>


int main(int argc, char* argv[])
{
	int i=0;
	for (i = 0; i < 100; i++)
	{
		if (fork() == 0)
		{
			printf("Dziecko PID: %d\n Dziecko PPID: %d\n", getpid(), getppid());
			exit(0);
		}
	}

	for (i = 0; i < 100; i++)
	{
		wait(NULL);
	}

	printf("Rodzic PID: %d\n Dziecko PPID: %d\n", getpid(), getppid());

	return 0
}
