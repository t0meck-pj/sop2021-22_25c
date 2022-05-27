#include <stdio.h>
#include <stdlib.h>

int maksimum(int a, int b)
{
    return (a > b) ? a : b;
}
int minimum(int a, int b)
{
    return (a < b) ? a : b;
}

int suma(int a, int b)
{
    return a + b;
}

int dlaWszystkich(int *tablica, int liczbaElementow, int (*Funkcja)(int, int))
{
    int v = *(tablica);
    int i;
    for (i = 1; i < liczbaElementow; i++)
    {
        v = Funkcja(v, *(tablica + i));
    }

    return v;
}

int main(int argc, char *argv[])
{
    int functionId = 0;
    int liczbaElementow = 0;
    int *TablicaLiczb;
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

    printf("Liczba elementow: ");
    if (!fscanf(stdin, "%d", &liczbaElementow))
    {
        printf("Niepoprawny znak\n");
        return 0;
    }

    TablicaLiczb = (int *)malloc(sizeof(int) * liczbaElementow);
    if (TablicaLiczb == NULL)
    {
        printf("Błąd podczas rezerwacji pamięci fukcją malloc");

        return 0;
    }

    for (; i < liczbaElementow; i++)
    {
        printf("element[%d]: ", i);
        if (!fscanf(stdin, "%d", &number))
        {
            printf("Niepoprawny znak\n");
            return 0;
        }

        *(TablicaLiczb + i) = number;
    }

    printf("Wynik: %d\n", dlaWszystkich(TablicaLiczb, liczbaElementow, TablicaFunkcji[functionId]));

    free(TablicaLiczb);

    return 0;
}
