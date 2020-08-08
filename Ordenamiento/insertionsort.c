#include <stdio.h>
#include <stdlib.h>
#include "utils.c"

void insertar_en_subarray(int *array,int marcado){
    int i=0;
    int temp;
    while (i<marcado){
        printf("a");
        if( array[marcado] < array[marcado-1]){
            //swap
            temp=array[marcado];
            array[marcado]=array[marcado-1];
            array[marcado-1]=temp;
            
            marcado--;

        }else
        {
            break;
        }
    }
    return;
}
void insertionsort_array(int *array, int size){
    for (int i = 0; i < size; i++)
    {
        insertar_en_subarray(array,i);
    }
    
}