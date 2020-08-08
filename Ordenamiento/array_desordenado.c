#include <stdio.h>
#include <stdlib.h>
//#include "bubblesort.c"
//#include "selectionsort.c"
#include "insertionsort.c"

int main(void){
    int array1[11]={6,3,8,1,4,9,7,5,2,0,5};
    int array2[10]={6,3,8,1,4,9,7,5,2,0};

    //bubblesort_ordenar_array(array2,10);
    //selectionsort_array(array2,10);
    insertionsort_array(array1,11);
    mostrar_array(array1,11);
    return 0;
}