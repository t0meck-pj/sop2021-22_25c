#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char* argv[])
{
	int number = 0;

	printf("PID: %d\n", getpid());
	printf("PPID: %d\n", getppid());
	printf("Podaj liczbe: ");
	fscanf(stdin, "%d", &number);

	printf("%d XOR 777 = %d\n", number, number ^ 777);

	return EXIT_SUCCESS;
}


