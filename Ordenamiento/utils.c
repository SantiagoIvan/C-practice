#include <stdio.h>
#include <stdlib.h>

void mostrar_array(int *raiz,int size){
    printf("\nImprimiendo Lista...\n");
    for (int i = 0; i < size; i++)
    {
        printf("Elemento: %i\n",raiz[i]);
    }
    
}
typedef struct Box{
    struct Box *next;
    int id;
} Box;