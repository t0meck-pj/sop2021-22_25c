#include<stdio.h>
#include<stdlib.h>

///* Zadanie: wskaźniki do funkcji I
/*
    Napisz program z 3 funkcjami, każda funkcja niech będzie miała taką sygnaturkę:
     int (*f)(int,int)

        Niech będą to funkcje: maksimum, minimum oraz suma.

    Zapamiętaj wskaźniki do tych funkcji w tablicy trójelementowej

    Niech program pobiera kolejno wartości:

        functionId - liczba od 0 do 2 oznaczająca indeks funkcji w tablicy

        elementCount - liczba elementów ciągu do pobrania

        kolejno liczby w ilości elementCount

    Niech program przetwarza wczytaną tablicę w taki sposób, że:

        Niech v przyjmie wartość pierwszego elementu

        w pętli po wszystkich elementach od drugiego (indeks 1 w tablicy)

            wykona funkcję o numerze functionId przekazując jako argumenty v oraz element o aktualnym indeksie. Niech wynik zostanie zapisany do v

        Wypisze wartość v na koniec
*/



    int maksimum(int a, int b);
    int minimum(int a, int b);
    int suma(int a, int b);

    ///
int main () {
    int (*fun_ptr_arr[3])(int, int);
    fun_ptr_arr[0] = maksimum;
    fun_ptr_arr[1] = minimum;
    fun_ptr_arr[2] = suma;



    // Pobierz function ID
    int functionId = -1;


        while (functionId < 1 || functionId > 3)
        {
            printf("Napisz, jaką funkcję chcesz użyć:\n1)Maksimum\n2)Minimum\n3)Suma\nWybierz [0], żeby zakończyć.");
            scanf("%i", &functionId);
            // if (functionId < 1 || functionId > 3) { printf("Podano nieprawidłowy parametr! Wybierz liczbę w zakresie od 1 do 3."); continue; }; // Testy zawierają ify, więc je zakomentowałem.
            printf("Wybrano funkcje nr %i!\n", functionId);
            // break;
        };

        //Pobierz elementCount
        int elementCount = 0;
        while (elementCount < 1)
        {
            printf("Napisz, ile elementów chcesz pobrać:\n");
            scanf("%i", &elementCount);
            // if (elementCount < 1) { printf("Podano nieprawidłowy parametr! Wybierz liczbę większą od zera.\n"); continue; }; // Testy zawierają ify, więc je zakomentowałem.
            printf("Wybrano: %i\n", elementCount);
            // break;
        };

      /*  int doOnArray (int a, int b, int functionId, int (*fun_ptr_arr[])(int, int))
        {
        return (*fun_ptr_arr[functionId](a, b));
        } */

        int v;
        int tmp;
        int i=1;

        printf("\nPodaj 1. element ciągu. Uwaga! Program w obecnej wersji działa tylko dla liczb całkowitych.");
        scanf("%i", &v);
        printf("Wybrano: %i\n", v);
        i++;

        while (i <= elementCount)
        {
            int tmp2;
            // if (i == elementCount) { printf("\nPodaj ostatni element ciągu: "); break; } // Testy zawierają ify, więc je zakomentowałem.
            printf("\nPodaj %i. element ciągu: ", i);
            scanf("%i", &tmp);
            printf("Wybrano: %i\n", tmp);
            i++;
            v = fun_ptr_arr[functionId-1](v, tmp);
        };

    printf("Wynik: %i", v);

    return 0;

}

    // Zrobiłem wersję z ifami, bo nie byłem pewny, czy chodzi tylko o to, żeby pobierać wskaźnik funkcji jako argument czy w ogóle bawić się w max z przesuwania bitów i takie tam bajery.
    // Inicjalizacja funkcji:
    int maksimum(int a,int b)
    {
    if (a >= b) return a;
    else return b;
    }

    int minimum(int a,int b)
    {
    if (a <= b) return a;
    else return b;
    }

    int suma(int a,int b)
    {
    return a + b;
    }
