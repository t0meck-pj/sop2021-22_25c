#include<stdio.h>


/* Zadanie 1.3
Napisz program wyświetlający tradycyjną choinkę o zadanej wysokości. Wysokość niech będzie podana jako parametr wywołania programu.
*/

int main ( int argc, char *argv[] ) {

	// Test ilości argumentów.
	if (argc < 2) { printf ("Oczekiwany argument - liczba choinek!"); return 0; };
	if ( argc > 2) { printf ("Zbyt dużo argumentów - zostanie wykorzystany tylko pierwszy!"); };

	int h = atoi(argv[1]);



	//Test wysokości:
	//int h;
	//scanf("%i", &h);

	for (int branches = 1; h > 0; h --) {
		int blanks = h - 1;
		while (blanks > 0) { printf(" "); blanks--; };
		int tmp = branches;
		while (branches > 0) { printf("#"); branches--; };
		branches = tmp + 2;
		blanks = h-1;
		while (blanks > 0) { printf(" "); blanks--; };
		printf("\n");
		}
	return 0;
}
