#include <stdio.h>
#include <stdlib.h>
#include "bubblesort.c"

void mostrar_array(int *array,int size){
    printf("Mostrando array ...\n");
    for (int i = 0; i < size; i++)
    {
        printf("Array[%i]: %i\n",i,array[i]);
    }
    return;
}

int main(void){
    int array[10]={6,3,8,1,4,9,7,5,2,0};

    mostrar_array(array,10);
    bubblesort_ordenar_array(array,10);
    mostrar_array(array,10);
    return 0;
}