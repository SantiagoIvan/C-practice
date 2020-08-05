#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    printf("hola\n");
    char nombre[]="santu";
    printf("%s tiene una longitud de %lu bytes, un byte mas por el fin de linea \n",nombre,sizeof(nombre));
    
    int n = 15;
    printf("N es igual a %i\n",n);

    n=16;
    printf("N es igual a %i\n",n);
    printf("N es igual a %p\n",&n);

    char string[] = "un string";
    printf("String es igual a %s\n",string);
    printf("Char es igual a %c\n",string[0]);
    printf("String es igual a %s\n",string);

    printf("Ingresa algo\n");
    char otro[10];
    scanf("%s",otro); /*otro es un puntero al array, apunta al indice 0*/
    printf("%s\n",otro);



    return 0;
}