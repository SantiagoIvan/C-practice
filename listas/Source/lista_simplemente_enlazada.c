#include <stdio.h>
#include <stdlib.h>
#include "sort_algorithms.c"

typedef struct Box{
    struct Box *next;
    int id;
} Box;


Box* inicializar_lista(int size){

    Box *raiz=NULL;
    Box *aux=NULL;
    Box *last=NULL;
    for (int i = 0; i < size; i++)
    {
        if (raiz)
        {
            aux=(Box*) malloc(sizeof(Box));
            aux->id=i;
            aux->next=NULL;
            last->next=aux;
            last=aux;
        }else
        {
            raiz=(Box*) malloc(sizeof(Box));
            raiz->id=i;
            raiz->next=NULL;
            last=raiz;
        }
    }
    return raiz;
}

void print_list(Box *raiz){
    printf("\nImprimiendo Lista...\n");
    while (raiz)
    {
        printf("Elemento: %i\n",raiz->id);
        raiz=raiz->next;
    }
    return;
}
Box* last_one_from_list(Box *raiz){
    while (raiz->next)
    {
        raiz=raiz->next;
    }
    return raiz;
}

Box* get_from_list(Box *raiz, int buscado){
    while (raiz)
    {
        if(raiz->id==buscado){
            return raiz;
        }else
        {
            raiz=raiz->next;
        }
    }
    return NULL;
}

void push(Box **raiz,int n){//recibe la dirección de memoria del puntero
    printf("\nPush %i!\n",n);
    
    if(*raiz){//si el valor que tiene el puntero es distinto de la direccion null
        Box* aux;
        aux=last_one_from_list(*raiz);//le paso el valor al cual apunta mi variable local
        //es decir, el valor que posee el puntero que pasé por parametro.
        
        aux->next=(Box*) malloc(sizeof(Box));
        aux->next->id=n;
        aux->next->next=NULL;
    }else
    {
        *raiz=(Box*) malloc(sizeof(Box));
        //reservo memoria y hago que el puntero que pasé
        //por parametro apunte a ese sector.
        (*raiz)->id=n;
        (*raiz)->next=NULL;
    }
    return;
}

void pop(Box **raiz,int size){
    printf("\nPop !\n");
    if(*raiz && size>1){
        Box* aux;
        aux=*raiz;
        while (aux->next->next)
        {
            aux=aux->next;
        }
        free(aux->next);
        aux->next=NULL;
    }else if (size == 1)
    {
        free(*raiz);
        *raiz=NULL;
    }
    
    return;
}

int main(void){

    Box *raiz=inicializar_lista(5);
    print_list(raiz);
    Box *last=last_one_from_list(raiz);
    printf("Id del ultimo: %i\n",last->id);

    printf("\n---------------------------\n");

    push(&raiz,67);
    print_list(raiz);
    last=last_one_from_list(raiz);
    printf("Id del ultimo: %i\n",last->id);

    printf("\n---------------------------\n");

    pop(&raiz,6);
    print_list(raiz);
    last=last_one_from_list(raiz);
    printf("Id del ultimo: %i\n",last->id);
    return 0;
}