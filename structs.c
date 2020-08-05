#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Persona{
    int edad;
    char nombre[20];
} typedef Persona;

/* Otra forma de definir lo mismo 
typedef struct Persona{
    int edad;
    char nombre[20];
} Persona;

o sino

struct Persona{
    int edad;
    char nombre[20];
};

typdedef struct Persona Persona;
*/


int main(){
    printf("Structs!\n");
    Persona santu;
    santu.edad=31;
    strcpy( santu.nombre, "santu");
    printf("Mi nombre es %s y mi edad es de %i\n",santu.nombre,santu.edad);
    return 0;
}