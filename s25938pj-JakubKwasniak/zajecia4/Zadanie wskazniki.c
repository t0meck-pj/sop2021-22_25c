#include <stdio.h>
#include <stdlib.h>

int max(int p1, int p2)
{
    return (p1 > p2) ? p1 : p2;
}

int min(int p1, int p2)
{
    return (p1 < p2) ? p1 : p2;
}

int sum(int p1, int p2)
{
    return p1 + p2;
}


int dlaWszystkich(int* tablica, int liczbaElementow, int (*Funkcja)(int, int))
{
    int v = *(tablica);
    int i;
    for (i = 1; i < liczbaElementow; i++)
    {
        v = Funkcja(v, *(tablica + i));
    }

    return v;
}

int main(int argc, char* argv[])
{
    int functionId = 0;
    int* Tablica;
    int liczbaElementow = 0;
    int i = 0;
    int number = 0;
    int (*TablicaFunkcji[3])(int, int);
    TablicaFunkcji[0] = max;
    TablicaFunkcji[1] = min;
    TablicaFunkcji[2] = sum;

    printf("functionId: ");
    if (!scanf( "%d", &functionId))
    {
        printf("Niepoprawny znak\n");
        return 1;
    }

    printf("Liczba elementow: ");
    if (!scanf( "%d", &liczbaElementow))
    {
        printf("Niepoprawny znak\n");
        return 0;
    }

    Tablica = (int*)malloc(sizeof(int) * liczbaElementow);
    if (Tablica == NULL)
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

        *(Tablica + i) = number;
    }

    printf("Wynik: %d\n", dlaWszystkich(Tablica, liczbaElementow, TablicaFunkcji[functionId]));
    free(Tablica);

    return 0;
}