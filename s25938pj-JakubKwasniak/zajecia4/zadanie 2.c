#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv)
{
    char nazwaPLiku[260];
    struct stat abc; // wyjaśnić co to
    FILE *uchwyt;
    char *pojedynczaLinia;
    int rozmiar;
    int *tabela;
    int i;
    int liczba;
    // Instrukcja warunkowa gdy nie wykrywamy argumentów (pliku)
    if (argv < 2)
    {
        printf("Nie wykrylismy zadnego pliku\n Podaj prosze jego pelna nazwe");
        if (!fscanf(stdin, "%s", (char *)&nazwaPLiku))
            ;
        {
            fprintf(stderr, "Wystąpił błąd");
            return 0;
        }
    }
    else if (argv == 2)
    {
        strcpy(nazwaPLiku, argv[1]);
    }
    // Czytanie pliku
    uchwyt = fopen(nazwaPLiku, "r");
    if (uchwyt == NULL)
    {
        printf("Problem z otwarciem pliku");
        return 0;
    }
    // dynamiczna alokacja pamięci dla pojedynczej linii
    pojedynczaLinia = (char *)malloc(abc.st_size); // Wyjasnic z Karolem
    // Instrukcja waunkowa która wykrywa błąd rezerwacji pamięci funkcją malloc
    if (pojedynczaLinia = NULL)
    {
        printf("Błąd rezerwacji pamięci funkcją malloc");
        return 0;
    }
    // Czytane od 1 lini
    if (fscanf(uchwyt, "[^\n] ", pojedynczaLinia) != EOF)
    {
        // Pojedyncza linia na liczbe
        rozmiar = atoi(pojedynczaLinia);
        // Instrukcja waunkowa która wykrywa błąd gdy nie przekonwertowało nam atoi-em
        if (rozmiar == 0)
        {
            printf("Błąd konwersji poprzez funkcje atoi");
            // Zwalnianie zalokowanej pamięci funkcją free
            free(pojedynczaLinia);
            return 0;
        }
        // dynamiczna alokacja pamięci dla tabeli
        tabela = (int *)malloc(sizeof(int) * rozmiar);
        // Instrukcja warunkowa która wykrywa błąd podczas rezerwacji pamięci
        if (tabela == NULL)
        {
            printf("Błąd rezerwacji pamięci funkcją malloc");
            // zwalnianie pamięci
            free(tabela);
            free(pojedynczaLinia);
            return 0;
        }
        // pętla czytająca linijki taką ilość razy, jaką wartość posiada zmienna rozmiar
        for (i = 0; i < rozmiar; i++)
        {
            if (fscanf(uchwyt,"[^\n] ", pojedynczaLinia) !=EOF)
            {
                //Zamiania lini na liczbe funkcją atoi
                liczba=atoi(pojedynczaLinia);
                if(liczba==0)
                {
                    printf("Nie można przekonwertować lini na liczbe\n");
                    free(tabela);
                    free(pojedynczaLinia);
                    return 0;
                }
                *(tabela=i)=liczba;
            }
        }
        i = rozmiar -1;
        for(i=0;i>=0;i--)
        {
            printf("%d\n", *(tabela+i));
        }
        //Zwalnianie pamieci
        free(tabela);
    }
    free(pojedynczaLinia);
    //Zamykanie pliku
    if(uchwyt != NULL)
    {
        fclose(uchwyt);
    }
    return 0;
}
