#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n;
    int sum = 0;
    int i = 0;
    int number = 0;

    printf("Podaj ilosc liczb: ");

    if (!fscanf(stdin, "%d", &n)) 
    {
        printf("Podana liczba jest niepoprawna\n");
        return -1;
    }

    for (; i < n; i++)
    {
        printf("Podaj liczbe[%d]: ", i+1);

        if (!fscanf(stdin, "%d", &number))
        {
            printf("Podana liczba jest niepoprawna\n");
            return -1;
        }
        sum += number;
    }

    printf("Suma: %d\n", sum);

    return EXIT_SUCCESS;
}

