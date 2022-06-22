#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* IO.1.2
Niech program wypisze je w odwrotnej kolejności. Program powinien przyjmować zero albo jeden argument:
NULL:    jeśli nie podano argumentu, to ma wczytywać ze standardowego wejścia
2.       jeśli podano argument, to jest to nazwa pliku do wczytania

    Skorzystaj z:
        fopen
        fclose
        fscanf

    Zabezpiecz przed przepełnieniem bufora.
    Skorzystaj z funkcji do dynamicznej rezerwacji/alokacji pamięci:
        malloc lub calloc
        free
*/

int main (int argc, char *argv[]) {
    char *filename;
    FILE *fptr = NULL;
    filename = (char *) malloc(15);
    char tmp[15];

    if( argc == 2 )
    {
        printf("Nazwa pliku podana w argumencie to: %s\n", argv[1]);
        fptr = fopen(argv[1], "r");
        printf("Poprawnie otworzono plik %s\n", argv[1]);
    }
    else if( argc > 2 ) {
    printf("Za dużo argumentów.\n");
    return 2;
    }
    else {
        printf("Podaj nazwę pliku, który chcesz zeskanować poniżej.\nUwaga! Żeby program działał poprawnie plik musi znajdować	się w tym samym katalogu, co ten program.\n");
        scanf("%s", &tmp);
        strcpy(filename, tmp);
        filename[sizeof(filename - 1)] = '\0';
        for (size_t i = 0; i < sizeof(filename); i++) if (filename[i] == '\0') break;
        fptr = fopen(filename, "r");
        printf("> Poprawnie otworzono plik o nazwie: %s\n", filename);
    }

    // Część powyżej wygląda na poprawną...
    int counter;

    fscanf(fptr, "%d", &counter);

 // printf("counter: %i\n", counter);  // --> Działa

    char buf[256][256];

    printf ("Liczba liczb do wczytania wynosi: %i\nKolejne liczby w ciągu to: ");

    for (int i=0; i < counter; i++)
    {
        fscanf(fptr, "%s", &buf[i][0]);
        if (i+1 == counter) { printf("%s.\n", buf[i] ); break; };
        printf("%s, ", buf[i] );
    }

    printf("Tymczasem w odwróconej kolejności kolejne liczby ciągu wynoszą:\n");

    for (int i=counter-1; i >= 0; i--)
    {
    if (i == 0) { printf("%s.\n", buf[i] ); break; };
    printf("%s, ", buf[i]);
    }


	fclose(fptr);
	printf("> Plik %s zamknięty.\n", filename);
	free(filename);
	printf("> Zaalokowana pamięć po nazwie pliku zwolniona. Do widzenia!\n");
	return 0;

}
