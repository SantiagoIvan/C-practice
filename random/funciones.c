#include <stdio.h>
#include <stdlib.h>

void saludar(char nombre[],int* edad){
    printf("hola %s\n",nombre);
    printf("tenes %i\n",*edad);//para mostrar el valor que hay donde está apuntando
    return;
}

int main(int argc, char* argv[]){
    /* El argv corresponde a los parametros ingresados por consola cuando se ejecuta el programa
    el 0 es la ejecucion misma del programa y el resto, las variables.*/
    printf("hola %s %s\n", argv[0],argv[1]);
    printf("Cantidad de parametros %i \n",argc);

    printf("\n--------------------------\n\n");
    printf("Ejemplo de funciones\n");
    int edad=24; //variable
    saludar("santuuuu\n",&edad); 
    /*como la funcion recibe un puntero por parametro, en lugar de pasar el valor, paso la direccion de memoria,
    es decir, dónde se encuentra el dato, y eso es recibido por la funcion en un puntero
    */
    return 0;
}