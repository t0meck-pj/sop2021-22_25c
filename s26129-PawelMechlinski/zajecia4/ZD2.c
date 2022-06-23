#include<stdio.h>
#include<stdlib.h>
#define getName(var) #var

///* Zadanie Domowe I
/*
    Napisz program implementujący listę dwustronnie wiązaną.
*/

struct Node {
    char c; // W zależności od potrzeb może tu być umieszczony inny typ zmiennej lub więcej zmiennych;
    struct Node* nastepny; // Wskaźnik do węzła następującego po danym - w przypadku list jednostronnych nie potrzeba nam znać potrzebnego.

    struct Node* poprzedni;

};
typedef struct Node objNode;

//Funkcja do wypisywania zawartości x w następnych node'ach:

void printNextNodes(struct Node* n)
{
    while (n != NULL)
    {
        printf(" %c ", n->c);
        n = n->nastepny;
    }
}
// F-kcja do wypisywania zawartości poprzednich node'ów.
void printPrevsNodes(struct Node* n)
{
    while (n != NULL)
    {
        printf(" %c ", n->c);
        n = n->poprzedni;
    }
}

///
int main()
{
  /*  objNode* Node_new(char c, struct Node* nastepny, struct Node* poprzedni)
    {
    objNode* n = (struct Node*)malloc(sizeof(struct Node));
    n->c = c;
    n->nastepny = nastepny;
    n->poprzedni = poprzedni;
    return n;
    } */
// ^ Eksperyment z implementowania konstruktora. Niestety konieczność odwłania się do następnego węzła komplikuje sprawę. Ew można by pewnie podzielić to na dodatkową funkcje dopisującą non-NULLowy następnik.

    // Zadeklarowanie punktorów węzłów.
    objNode* one = NULL;
    objNode* two = NULL;
    objNode* three = NULL;
    objNode* four = NULL;
    objNode* five = NULL;
    objNode* six = NULL;

    // Alokacja pamięci na stosie:
    one = (struct Node*)malloc(sizeof(struct Node));
    two = (struct Node*)malloc(sizeof(struct Node));
    three = (struct Node*)malloc(sizeof(struct Node));
    four = (struct Node*)malloc(sizeof(struct Node));
    five = (struct Node*)malloc(sizeof(struct Node));
    six = (struct Node*)malloc(sizeof(struct Node));

    one->c='a';
    one->poprzedni=NULL;
    one->nastepny=two;
    two->c='b';
    two->poprzedni=one;
    two->nastepny=three;
    three->c='c';
    three->poprzedni=two;
    three->nastepny=four;
    four->c='d';
    four->poprzedni=three;
    four->nastepny=five;
    five->c='e';
    five->poprzedni=four;
    five->nastepny=six;
    six->c='f';
    six->poprzedni=five;
    six->nastepny=NULL;

    // Testy:
    printf("Value of C from three: %c\n", three->c);
    // printf("After Glowa comes: %s", glowa->nastepny.getName());
    printf("Wartości node'ów po kolei to: ");
    printNextNodes(one);
    printf("\n");

    printf("Wartości w odwróconej kolejności, zaczynając od czwartego: ");
    printPrevsNodes(four);
    printf("\n");
    // Przyda się jeszcze funkcja do podróżowania po node'ach:

    struct Node* nastepnyNode(struct Node* n)
    {
    struct Node* result = n->nastepny;
    return result;
    }

    char nastepny = nastepnyNode(two)->c;
    printf("Węzeł po węźle two ma wartość c równą: %c\n", nastepny);

    struct Node* poprzedniNode(struct Node* n)
    {
    struct Node* result = n->poprzedni;
    return result;
    }

    int poprzedni = poprzedniNode(six)->c;
    printf("Węzeł przed węzłem six ma wartość c równą: %c", poprzedni);
//{
//    return Node->nastepny;
//}


    return 0;
}
