#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>


int main(int argc, char* argv[])
{
	int i = 0;

	for (; i < 5; i++)
	{
		if (fork() > 0)
		{
			printf("[Child] PID: %d, PPID: %d\n", getpid(), getppid());
		}
		else {
			printf("[Parent] PID: %d, PPID: %d\n", getpid(), getppid());
		}
	}

	return EXIT_SUCCESS;
}

