#include <stdio.h>
#include <stdlib.h>

int maksimum(int a, int b)
{
	return (a > b) ? a : b;
}
int minimum(int a, int b) {
	return (a < b) ? a : b;
}

int suma(int a, int b) {
	return a + b;
}

int forAll(int* tablica, int liczbaElementow, int (*Funkcja)(int, int))
{
	int v = *(tablica);
	int i = 1;
	for (; i < liczbaElementow; i++)
	{
		v = Funkcja(v, *(tablica + i));
	}

	return v;
}


int main(int argc, char* argv[])
{
	int functionId = 0;
	int elementCount = 0;
	int* TablicaLiczb;
	int i = 0;
	int number = 0;
	int (*TablicaFunkcji[3])(int, int);
	TablicaFunkcji[0] = maksimum;
	TablicaFunkcji[1] = minimum;
	TablicaFunkcji[2] = suma;

	printf("functionId: ");
	if (!fscanf(stdin, "%d", &functionId))
	{
		printf("Niepoprawny znak\n");
		return EXIT_FAILURE;
	}




	printf("elementCount: ");
	if (!fscanf(stdin, "%d", &elementCount))
	{
		printf("Niepoprawny znak\n");
		return EXIT_FAILURE;
	}

	TablicaLiczb = (int*)malloc(sizeof(int) * elementCount);
	if (TablicaLiczb == NULL) 
	{
		perror("malloc failed");
		
		return EXIT_FAILURE;
	}

	for (; i < elementCount; i++)
	{
		printf("element[%d]: ", i);
		if (!fscanf(stdin, "%d", &number))
		{
			printf("Niepoprawny znak\n");
			return EXIT_FAILURE;
		}

		*(TablicaLiczb + i) = number;
	}


	printf("Wynik: %d\n", forAll(TablicaLiczb, elementCount, TablicaFunkcji[functionId]));

	free(TablicaLiczb);

	return EXIT_SUCCESS;
}

