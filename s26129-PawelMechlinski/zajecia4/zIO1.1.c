#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LSIZ 128
#define RSIZ 10

/* Zadanie 1.1
    Napisz program wczytujący z pliku tekstowego ciąg liczb.
        Format pliku jest taki:
            liczba elementów ciągu (jako liczba naturalna)
            Kolejne liczby - każda w nowej linii
        Przykład:

3
5
1
9

        Opis przykładu:
            3 liczby do wczytania
            liczby: 5, 1, 9
*/

int main (void) {
    char line[RSIZ][LSIZ];
	char filename[20];
	FILE *fptr = NULL;
	int i = 0;
	int oneTime = 1;
	int tot = 0;
	char counts;

        printf("Podaj nazwę pliku, który chcesz zeskanować poniżej.\n Uwaga! Żeby program działał poprawnie plik musi znajdować	się w tym samym katalogu, co ten program.\n");

        scanf("%s", &filename);

	fptr = fopen(filename, "r");
    while(fgets(line[i], LSIZ, fptr))
	{

        line[i][strlen(line[i]) - 1] = '\0';
        i++;

    }

    tot = i;

	printf("\n There are %s numbers in a series from file %s . Those are : \n",line[0],filename);
    for(i = 1; i < tot; ++i)
    {
        printf(" %s\n", line[i]);
    }
    printf("\n");



	fclose(fptr);
	return 0;

}
