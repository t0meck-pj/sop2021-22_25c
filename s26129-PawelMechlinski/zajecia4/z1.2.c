#include<stdio.h>


/* Zadanie 1.2
Przerób ten program tak, aby wartość była zwracana jako kod zakończenia programu. Wyświetl tą wartość z linii komend. 
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
	
	//printf("\nSuma wynosi: %i", sum);
	
	return sum;	
}