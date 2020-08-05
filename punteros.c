#include <stdio.h>
#include <stdlib.h>

int main(){

    int age= 30;
    int* agePointer=&age;

    printf("La edad es de %i \n",age);
    printf("El puntero es tiene un valor de %p, que es donde esta alojada la variable Age. %p\n",agePointer,&age);
    printf("-------------------------\n\n");
    printf("El valor que hay donde esta apuntando agePointer es %i\n",*agePointer);
    *agePointer=10;
    printf("El valor que hay donde esta apuntando agePointer es %i\n",*agePointer);

    printf("El valor derefered %i",*&age);
    printf("El puntero tiene una direccion fisica: %p y apunta a %p\n",&agePointer,agePointer);
    printf("Ahora voy a tratar de ir más a fondo");
    printf("\n -----------------------------------\n\n");

    char nombre[]="santu";
    printf("Nombre es un puntero que apunta al primer item del array. %c con notacion de punteros\n",*nombre);
    printf("Con notacion de array %c\n",nombre[0]);

    printf("Ahora el nombre es %s\n",nombre);
    printf("El valor del puntero es esta direccion: %p. Deberia ser igual a la direccion de la primer letra\n",nombre);

    printf("La direccion de memoria de la primer letra es %p\n",&nombre[0]);
    printf("\n--------------------------------------\n");

    int** punteroAlAgePointer=&agePointer; //un puntero que apunta a un puntero de int
    printf("El valor que posee punteroAlAgePointer es la direccion de memoria de agePointer\n");
    printf("Es decir,donde esta alojado el agePointer\n");
    printf("%p  es igual a %p\n",punteroAlAgePointer,&agePointer);

    printf("\n--------------------------------------\n");
    printf("Tamaño de un puntero: %lu bytes.\n",sizeof(agePointer));
    return 0;
}