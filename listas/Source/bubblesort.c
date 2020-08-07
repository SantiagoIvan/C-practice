#include <stdio.h>
#include <stdlib.h>
typedef struct Box{
    struct Box *next;
    int id;
} Box;
void mostrar_list(Box *raiz){
    printf("\nImprimiendo Lista...\n");
    while (raiz)
    {
        printf("Elemento: %i\n",raiz->id);
        raiz=raiz->next;
    }
    return;
}


void bubblesort_ordenar_array(int *array,int size){//menor a mayor
    int aux;
    printf("Ordenando array ...\n");
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-1-i; j++)
        {
            if( array[j] > array[j+1] ){
                aux=array[j];
                array[j]=array[j+1];
                array[j+1]=aux;
            }
        }
        
    }
    
    return;
}

Box* bubblesort_ordenar_lista(Box *raiz, int size){
    Box* actual=raiz;
    Box* anterior=NULL;
    Box* siguiente=actual->next;
    if(raiz && size>1){
        for (int i = 0; i < size-1; i++)
        {
            for (int j = 0; j < size-1-i; j++)
            {
                if(actual->id > siguiente->id ){
                    //swapeo:
                    if(anterior==NULL){
                        //si estoy en el primer nodo, voy a tener que cambiar la raiz
                        actual->next=siguiente->next;
                        siguiente->next=actual;
                        raiz=siguiente;
                        //actualizo variables temporales
                        anterior=raiz;
                        siguiente=actual->next;
                    }else
                    {
                        actual->next=siguiente->next;
                        siguiente->next=actual;
                        anterior->next=siguiente;
                        //actualizo variables temporales
                        anterior=siguiente;
                        siguiente=actual->next;
                    }
                }else
                {
                    //no swapeo nada, no se cumple la condicion.
                    actual=actual->next;
                    siguiente=siguiente->next;
                    if(anterior==NULL){//por si estoy en la raiz
                        anterior=raiz;
                    }else{
                        anterior=anterior->next;
                    }
                }
            }
            //vuelvo al principio
            anterior=NULL;
            actual=raiz;
            siguiente=actual->next;
        }
    }
    return raiz;
}
