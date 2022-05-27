#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>


int main(int argc, char* argv[])
{
	int i;

	for (i = 0; i < 100; i++)
	{
		if (fork() == 0)
		{
			printf("[Child] PID: %d, PPID: %d\n", getpid(), getppid());
			exit(0);
		}
	}

	for (i = 0; i < 100; i++)
	{
		wait(NULL);
	}

	printf("[Parent] PID: %d, PPID: %d\n", getpid(), getppid());

	return EXIT_SUCCESS;
}


