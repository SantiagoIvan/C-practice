#include <stdio.h>
#include <stdlib.h>
#include "bubblesort.c"

Box* inicializar_lista(){
    Box* e1= (Box*) malloc(sizeof(Box));
    Box* e2= (Box*) malloc(sizeof(Box));
    Box* e3= (Box*) malloc(sizeof(Box));
    Box* e4= (Box*) malloc(sizeof(Box));
    Box* e5= (Box*) malloc(sizeof(Box));
    Box* e6= (Box*) malloc(sizeof(Box));
    Box* e7= (Box*) malloc(sizeof(Box));
    Box* e8= (Box*) malloc(sizeof(Box));
    Box* e9= (Box*) malloc(sizeof(Box));
    Box* e10= (Box*) malloc(sizeof(Box));

    e1->id=3;
    e1->next=e2;
    e2->id=1;
    e2->next=e3;
    e3->id=9;
    e3->next=e4;
    e4->id=7;
    e4->next=e5;
    e5->id=23;
    e5->next=e6;
    e6->id=28;
    e6->next=e7;
    e7->id=19;
    e7->next=e8;
    e8->id=13;
    e8->next=e9;
    e9->id=69;//xd
    e9->next=e10;
    e10->id=47;
    e10->next=NULL;

    return e1;
}



int main(void){
    Box* raiz= inicializar_lista();
    mostrar_lista(raiz);
    raiz=bubblesort_ordenar_lista(raiz,10);
    mostrar_lista(raiz);
    return 0;
}