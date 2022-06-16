#define _POSIX_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include <sys/file.h>

int CanShutdown = 0;
extern int errno;

void handler(int signal)
{
	CanShutdown = 1;
}

void handler2(int signal)
{
	printf("Wyrkyto probe uruchomienia drugiej instancji programu.\n");
}

int main() 
{
	FILE* handle;
	int pid;
	const char* filename = "/var/lock/zad2.lock";
	if (access(filename, F_OK) != 0)
	{
		handle = fopen(filename, "w+");
		fprintf(handle, "%d", getpid());
		fflush(handle);
		signal(SIGINT, handler);
		signal(SIGUSR1, handler2);
		while (!CanShutdown)
		{
			sleep(1);
		}
		printf("Exitiing..\n");
		fclose(handle);

		unlink(filename);
	}
	else 
	{

		handle = fopen(filename, "r");
		fscanf(handle, "%d", &pid);
		printf("Send signal to PID: %d..\n", pid);
		kill(pid, SIGUSR1);
	}

	return 0;
}