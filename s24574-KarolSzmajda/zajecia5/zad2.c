#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char* argv[])
{
	if (fork() == 0) {
		printf("I'm parent process\n");
	}
	else {
		printf("I'm child process\n");
	}

	printf("PID: %d\n", getpid());
	printf("PPID: %d\n\n", getppid());

	return EXIT_SUCCESS;
}


