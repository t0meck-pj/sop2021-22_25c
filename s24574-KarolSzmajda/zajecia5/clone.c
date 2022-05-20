#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/stat.h>

#define STACK_SIZE (128 * 128)
#define CHILD_COUNT 2
#define NUMBER_PER_CHILD 100

static key_t shm_key = 666;
static int shm_size = 2;
static int shm_id;
static int* shmaddr;

static int childFunc(void* arg)
{
	int i = (intptr_t)arg; /* index dziecka */
	int start = i * NUMBER_PER_CHILD; /* początkowy zakres sumowania */
	int end = start + NUMBER_PER_CHILD - 1; /* końcowy zakres sumowania */

	/* Alokuje segment współdzielonej pamięci */
	shm_id = shmget (shm_key, shm_size, S_IRUSR | S_IWUSR);

	/* Dołączam segment współdzielonej pamięci */
	shmaddr = (int*) shmat (shm_id, 0, 0);

	/* Zmodyfikowałem wzór, wynik zapisuje do współdzielonej pamięci między procesami */
	/* https://pl.wikipedia.org/wiki/Liczba_tr%C3%B3jk%C4%85tna */
	*(shmaddr+i) = ((end * end + end) - (start * start - start)) / 2;
	
	/* Odłączenie segmentu współdzielonej pamięci*/
	shmdt(shmaddr);
	
	return 0;
}

int main(int argc, char *argv[])
{
	char* stack; /* Stos */
	pid_t pid[CHILD_COUNT]; /* Tablica PID procesów */
	intptr_t i = 0;
	int sum = 0;

	/* Alokuje segment współdzielonej pamięci */
	shm_id = shmget (shm_key, shm_size, IPC_CREAT | S_IRUSR | S_IWUSR);

	/* Dołączam segment współdzielonej pamięci */
	shmaddr = (int*) shmat (shm_id, 0, 0);
	
	/* Alokuje stos */
	stack = (char*)malloc(STACK_SIZE*CHILD_COUNT);
	if (stack == NULL)
	{
		perror("malloc"); 
		exit(EXIT_FAILURE); 
	}

	/* Tworze dwa procesy, z własnym stosem, które wykonują funkcje childFunc z parametrem "i" */
	for(; i < CHILD_COUNT; i++)
	{
		pid[i] = clone(childFunc, stack + (STACK_SIZE * (i+1)), 0, (void*)i);
	}

	i = 0;
	for(; i < CHILD_COUNT; i++)
	{
		/* Czekam na zakończenie procesu */
		waitpid(pid[i], NULL, 0);
		
		/* Sumuje wynik zwrócony do współdzielonej pamięci */
		sum += *(shmaddr+i);
	}

	printf ("Suma: %d\n", sum);
	
	/* Odłączenie segmentu współdzielonej pamięci*/
	shmdt(shmaddr);
	shmctl(shm_id, IPC_RMID, NULL); /* Oznaczenie o możliwości usuniecia pamieci */
	
	free(stack);
	
	return 0;
}
