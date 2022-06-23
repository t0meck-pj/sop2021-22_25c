#include<stdio.h>
#include<stdlib.h>

///* Zadanie Domowe III
/*
    Napisz program liczący kolejne wartości ciągu Fibonacciego w wersji:
    A. rekursywnej (rekurencyjnej)
    B. iteracyjnej
*/

///
int main()
{
    int fiboRek(int n)
    {
    if (n < 0) return -1; // Na wypadek błędu.
    if (n == 0) return n;
    if (n == 1) return n;
    if (n > 1)
    {

        return fiboRek(n-1)+fiboRek(n-2);
    // Normalnie przy takiej liczbie ifów można by zastosować switch-case, ale if powinien być szybszy.
    }
    return -1;
    }

    int fiboIter(int n)
    {
        int minusJeden = 1, minusDwa = 0, aktualny; // "Cofacze" można zadeklarować z góry, bo i tak w pierwszych 2. przypadkach nie będą używane.

        if (n < 0) return -1;

        switch (n) // W tym przypadku nie przechodzimy wielokrotnie przez switcha, więc można sobie rozpisać case'y:
        {
            case 0:
                return 0;

            case 1:
                return 1;

            default:
                for (int i = 1; i < n; i++)
                {
                    aktualny = minusJeden + minusDwa;
                    minusDwa = minusJeden;
                    minusJeden = aktualny;
                }
        }
        return aktualny;
    }

    int exit = 1;
    while(1 == 1)
    {
    int n;
    printf("\nPodaj n:\n");
    scanf("%i", &n);
    if (n < 0)
    {
    printf("Niepoprawny numer. Do widzenia!");
    break;
    }

    printf("Wybrano n=%i\n", n);
    int wynikRek = fiboRek(n);
    printf("\nDla n=%i, obliczany rekurencyjnie ciąg fibonacciego ma wartość: %i", n, wynikRek);
    printf(" (przy algorytmie rekurencyjnym);\n przy iteracyjnym powinna być taka sama, a wynosi: %i", fiboIter(n));
    }

    return 0;
}
