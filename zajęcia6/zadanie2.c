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

	/* 1. Program uruchamia się i sprawdza, czy jest plik /tmp/lock */
	if (access(filename, F_OK) != 0)
	/* 2. Jeśli taki plik nie istnieje, wtedy: */
	{
		/* Uchwyt do czytanego pliku */
		handle = fopen(filename, "w+");
		if (handle == NULL)
		{
			fprintf(stderr, "Error opening %s file: %s\n", filename, strerror(errno));

			return EXIT_FAILURE;
		}

		fprintf(handle, "%d", getpid());
		fflush(handle);

		signal(SIGINT, handler);
		signal(SIGUSR1, handler2);

		while (!CanShutdown)
		{
			sleep(1);
		}

		printf("Exitiing..\n");


		/* Zamykamy plik */
		if (handle != NULL)
		{
			fclose(handle);
		}

		unlink(filename);
	}
	else 
	/* 3. Jeśli taki plik istnieje, wtedy: */
	{
		/* 3.1 Wczytywana jest zawartość tego pliku - pid procesu uruchomionego */
		handle = fopen(filename, "r");
		if (handle == NULL)
		{
			fprintf(stderr, "Error opening %s file: %s\n", filename, strerror(errno));

			return EXIT_FAILURE;
		}

		fscanf(handle, "%d", &pid);

		/* 3.2 generowany jest sygnał USR1 do procesu o pid takim jak wczytany */
		printf("Send signal to PID: %d..\n", pid);
		kill(pid, SIGUSR1);
	}

	/* 3.3 program kończy pracę */
	return 0;
}