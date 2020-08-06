#include <stdio.h>
#include <stdlib.h>

void sumar1(int array[], int size){
    for(int i=0;i<size;i++){
        array[i]+=1;
    }
    return;
}
void mostrar_array(int array[],int size){
    for(int i=0;i<size;i++){
        printf("El valor del item %i es: %i\n",i,array[i]);
    }
    return;
}


int main(){
    int numeros[]={1,2,3,4,5};

    mostrar_array(numeros,5);
    sumar1(numeros,5);
    mostrar_array(numeros,5);

    printf("la variable 'numeros' es un puntero que apunta al primer elemento del array.\n");
    printf("Su valor es %p. La direccion del primer elemento es %p\n",numeros,&numeros[0]);

    printf("Es por esta razon que el array siempre se pasa por referencia a una funcion, y nunca por valor.");
    return 0;
}