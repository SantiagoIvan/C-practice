#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Persona{
    int edad;
    char nombre[20];
} typedef Persona;

/* Otra forma de definir lo mismo */
typedef struct Perro{
    int edad;
    char nombre[20];
} Perro;

// o sino

struct {
    int edad;
    char nombre[20];
} typedef Gato;

int main(){
    printf("Structs!\n");
    Persona santu;
    santu.edad=31;
    strcpy( santu.nombre, "santu");
    printf("Mi nombre es %s y mi edad es de %i\n",santu.nombre,santu.edad);

    printf("\n-------------------------\n");
    Gato gatito;
    gatito.edad=58;
    strncpy(gatito.nombre,"michi",20);
    printf("Mi nombre es %s y mi edad es de %i\n",gatito.nombre,gatito.edad);

    return 0;
}