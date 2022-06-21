#define _POSIX_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include <sys/file.h>

int mozeSieZamknac = 0;
extern int errno;

void handler(int sygnal)
{
	mozeSieZamknac = 1;
}

void handler2(int sygnal)
{
	printf("Wykryto probe uruchomienia drugiej instancji.\n");
}

int main() 
{
	FILE* uchwyt;
	int pid;
	const char* filename = "/var/lock/zad2.lock";
	if (access(filename, F_OK) != 0)
	{
		uchwyt = fopen(filename, "w+");
		fprintf(uchwyt, "%d", getpid());
		fflush(uchwyt);
		signal(SIGINT, handler);
		signal(SIGUSR1, handler2);
		while (!mozeSieZamknac)
		{
			sleep(1);
		}
		printf("Exitiing..\n");
		fclose(handle);

		unlink(filename);
	}
	else 
	{

		uchwyt = fopen(filename, "r");
		fscanf(uchwyt, "%d", &pid);
		printf("Send signal to PID: %d..\n", pid);
		kill(pid, SIGUSR1);
	}

	return 0;
}