#include<stdio.h>
#include<stdlib.h>

///* Zadanie: wskaźniki do funkcji II
/*
    Korzystając z wiedzy z poprzedniego zadania, napisz funkcję, która będzie przetwarzała tablicę za pomocą uniwersalnej funkcji podanej jako argument funkcji.
Na przykład:

int wynik = forAll(tablica, liczbaElementow, maksimum); // maksimum to nazwa funkcji porownojacej dwie wartosci
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

/*

    // Pobierz function ID
    int functionId = -1;


        while (functionId < 1 || functionId > 3)
        {
            printf("Napisz, jaką funkcję chcesz użyć:\n1)Maksimum\n2)Minimum\n3)Suma\nWybierz [0], żeby zakończyć.");
            scanf("%i", &functionId);
            // if (functionId < 1 || functionId > 3) { printf("Podano nieprawidłowy parametr! Wybierz liczbę w zakresie od 1 do 3."); continue; };
            printf("Wybrano funkcje nr %i!\n", functionId);
            // break;
        };

        //Pobierz elementCount
        int elementCount = 0;
        while (elementCount < 1)
        {
            printf("Napisz, ile elementów chcesz pobrać:\n");
            scanf("%i", &elementCount);
            // if (elementCount < 1) { printf("Podano nieprawidłowy parametr! Wybierz liczbę większą od zera"); continue; };
            printf("Wybrano: %i\n", elementCount);
            // break;
        }; */

      /*  int doOnArray (int a, int b, int functionId, int (*fun_ptr_arr[])(int, int))
        {
        return (*fun_ptr_arr[functionId](a, b));
        } */

        /*
        int v;
        int tmp;
        int i=1;

        printf("\nPodaj 1. element ciągu: ");
        scanf("%i", &v);
        printf("Wybrano: %i\n", v);
        i++;

        while (i <= elementCount)
        {
            int tmp2;
            // if (i == elementCount) { printf("\nPodaj ostatni element ciągu: "); break; } // Miało nie byc ifów :D
            printf("\nPodaj %i. element ciągu: ", i);
            scanf("%i", &tmp);
            printf("Wybrano: %i\n", tmp);
            i++;
            v = fun_ptr_arr[functionId-1](v, tmp);
        };

    printf("Wynik: %i", v);
*/
    int tablica[10] = { 0, 0, 33, 4, 55, 6, 7, 8, 9, -100};
    int liczbaElementow = sizeof tablica / sizeof tablica[0];


    int forAll(int tablica[], int liczbaElementow, int *fun_ptr_arr(int, int))
    {
        printf("tablica[0]= %i", tablica[0]);
        int result = tablica[0];
        int i = 1;
        printf(" liczbaElementów = %i\n", liczbaElementow);
        while (i < liczbaElementow)
        {
        printf("Tablica[%i]: %i ", i, tablica[i]);
        result = fun_ptr_arr(result, tablica[i]);
        printf("Result: %i '\n", result);
            i++;
        }
        return result;
    }
    printf("Maksimum:\n");
    int wynik = forAll(tablica, liczbaElementow, maksimum);
    printf("Wynik: %i\n\n", wynik);

    printf("Maksimum:\n");
    wynik = forAll(tablica, liczbaElementow, minimum);
    printf("Wynik: %i\n\n", wynik);

    printf("Maksimum:\n");
    wynik = forAll(tablica, liczbaElementow, suma);
    printf("Wynik: %i\n\n", wynik);
    return 0;

}

    // Wersja z ifami, bo nie byłem pewny, czy chodzi tylko o to, żeby pobierać wskaźnik funkcji jako argument czy w ogóle bawić się w max z przesuwania bitów i takie tam bajery.
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
