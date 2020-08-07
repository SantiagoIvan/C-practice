#include <stdio.h>
#include <stdlib.h>
#include "sort_algorithms.c"

Box* inicializar_lista(){
    Box* e1= (Box*) malloc(sizeof(Box));
    Box* e2= (Box*) malloc(sizeof(Box));
    Box* e3= (Box*) malloc(sizeof(Box));
    Box* e4= (Box*) malloc(sizeof(Box));
    Box* e5= (Box*) malloc(sizeof(Box));

    e1->id=3;
    e1->next=e2;
    e2->id=1;
    e2->next=e3;
    e3->id=5;
    e3->next=e4;
    e4->id=2;
    e4->next=e5;
    e5->id=4;
    e5->next=NULL;

    return e1;
}

void mostrar_lista(Box *raiz){
    printf("\nImprimiendo Lista...\n");
    while (raiz)
    {
        printf("Elemento: %i\n",raiz->id);
        raiz=raiz->next;
    }
    return;
}


int main(void){
    Box* raiz= inicializar_lista();
    mostrar_lista(raiz);
    raiz=bubblesort_ordenar_lista(raiz,5);
    mostrar_lista(raiz);
    return 0;
}