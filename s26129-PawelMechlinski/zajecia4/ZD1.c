#include<stdio.h>
#include<stdlib.h>
#define getName(var) #var

///* Zadanie Domowe I
/*
    Napisz program implementujący listę jednostronnie wiązaną.
*/

struct Node {
    int x; // W zależności od potrzeb może tu być umieszczony inny typ zmiennej lub więcej zmiennych;
    struct Node* nastepny; // Wskaźnik do węzła następującego po danym - w przypadku list jednostronnych nie potrzeba nam znać potrzebnego.

 //   char name[20]; // Dla potrzeb przykładu może przydać sie zmienna dla nazwy węzła.
 //   char* getName() { return Node.name; }
};

//Funkcja do wypisywania zawartości x w następnych node'ach:

void printNodesX(struct Node* n)
{
    while (n != NULL)
    {
        printf(" %i ", n->x);
        n = n->nastepny;
    }
}

///
int main()
{
    // Zadeklarowanie punktorów węzłów.
    struct Node* glowa = NULL;
    struct Node* tulow = NULL;
    struct Node* ogon = NULL;

    // Alokacja pamięci na stosie:
    glowa = (struct Node*)malloc(sizeof(struct Node));
    tulow = (struct Node*)malloc(sizeof(struct Node));
    ogon = (struct Node*)malloc(sizeof(struct Node));

    glowa->x=1;
    glowa->nastepny=tulow;

    tulow->x=2;
    tulow->nastepny=ogon;

    ogon->x=3;
    ogon->nastepny=NULL;


    // Testy:
    printf("Value of X from tułów: %i\n", tulow->x);
    // printf("After Glowa comes: %s", glowa->nastepny.getName());
    printf("Wartości node'ów po kolei to: ");
    printNodesX(glowa);
    printf("\n");

    // Przyda się jeszcze funkcja do podróżowania po node'ach:

    struct Node* nastepnyNode(struct Node* n)
    {
    struct Node* result = n->nastepny;
    return result;
    }

    int nastepny = nastepnyNode(glowa)->x;
    printf("Węzeł po węźle głowa ma wartość x równą: %i", nastepny);
//{
//    return Node->nastepny;
//}


    return 0;
}
