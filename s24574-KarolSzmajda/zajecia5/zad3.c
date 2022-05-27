#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>


int main(int argc, char* argv[])
{
	int number;
	size_t i;

	if (argc != 2)
	{
		printf("Usage: ./zad3 {number}\n\n");
		return EXIT_FAILURE;
	}

	number = atoi(argv[1]);

	if (number <= 0)
	{
		printf("The number must be greater than 0\n");
		return EXIT_FAILURE;
	}

	if (fork() > 0)
	{
		wait(NULL);
		printf("[Parent] Sum: %d\n", (number * (number + 1)) / 2);
	}
	else {
		printf("[Child] Numbers: ");
		for (i = 1; i <= number; i+=2)
		{
			printf("%ld ", i);
		}
		printf("\n");
	}

	return EXIT_SUCCESS;
}


