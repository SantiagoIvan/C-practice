#include <stdio.h>
#include <stdlib.h>

void selectionsort_array(int *array, int size){
    int min,temp,indexMin;
    min=(-1);
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0+i; j < size; j++)
        {
            if(min!=(-1)){
                if(array[j]<min){

                    min=array[j];
                    indexMin=j;
                }
            }else{
                min=array[j];
                indexMin=j;
            }
        }
        printf("El minimo de esta iteracion es (%i , %i) \n y lo swapeo con el elemento i(%i) %i\n",array[indexMin],min,i,array[i]);
        //swapeo elemento i con el minimo
        temp=array[i];
        array[i]=array[indexMin];
        array[indexMin]=temp;
        //reseteo variables
        min=(-1);
    }
    
    return;
}