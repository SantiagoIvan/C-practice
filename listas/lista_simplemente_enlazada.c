#include <stdio.h>
#include <stdlib.h>

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

int main(void){

    Box *raiz=inicializar_lista(5);
    print_list(raiz);
    Box *last=last_one_from_list(raiz);
    printf("%i\n",last->id);
    return 0;
}