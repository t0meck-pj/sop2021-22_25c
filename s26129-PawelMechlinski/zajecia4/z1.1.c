#include<stdio.h>


/* Zadanie 1.1
Napisz program obliczający sumę liczb wprowadzonych przez użytkownika (ze standardowego wejścia) i wypisujący wynik na standardowe wyjście.
*/

int main () {
	int current;
	int counter;
	int sum=0;
	
	printf("Napisz, ile liczb chcesz zsumować:\n");

	scanf("%i", &counter);

	printf("\nTeraz podaj %i liczb:\n", counter);
	for (; counter > 0; counter--) {
	scanf("%i", &current);		
	sum += current;
	}
	
	printf("\nSuma wynosi: %i", sum);
	
	return 0;	
}