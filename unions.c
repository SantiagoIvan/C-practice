#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Una struct es cun conjunto de campos, el tamaño total de la struct será la suma
de cada uno de sus campos.
Cada campo tendrá una región de memoria dentro de la memoria asignada al struct.

**UNION***
Permite unir campos, asignandolos a un mismo espacio de memoria. De esta forma, se almacena
uno a la vez. Los campos en el union comparten un mismo espacio de memoria. A medida que se van
asignando, van sobrescribiendo el mismo espacio.

Recordar que no hay polimorfirsmo, no es objetos. Pero se puede hacer algo semejante.

1- Ahorro de memoria, ya que se puede unir campos que sean mutuamente excluyentes.
2- El tamaño del espacio asignado pensaba que era del campo mas grande, pero abajo hay un ejemplo donde no se cumple eso.
*/

typedef struct Test{
    char nombre[20];
}  Test;

typedef struct Otro_Test{
    char nombre[20];
    union
    {
        int indice_frio;
        int indice_calor;
    } temperatura;
    
}  Otro_Test;


//---------------------------------------------------


typedef enum Tipo {
    ENTERO,
    CON_COMA,
    GRANDE
} Tipo;

#pragma pack(push, 1)
typedef struct Pseudo_Polimorfismo{
    Tipo tipo_asignado_actualmente;
    //no solo informa el tipo, sino también el espacio requerido si es usado por otro componente.
    union
    {
        int n1;
        float n2;
        double n3;
    } valor;
} Pseudo_Polimorfismo;
#pragma pack(pop)

int main(void){
    printf("Tamaño de Otro_Test: 20 del array + 4 del union int. %lu\n",sizeof(Otro_Test));

    Otro_Test t;
    Pseudo_Polimorfismo p;
    t.temperatura.indice_calor=20;
    t.temperatura.indice_frio=10;
    printf("Indice de calor: %i\n",t.temperatura.indice_calor);
    printf("Indice de frio: %i\n",t.temperatura.indice_frio);

    printf("\n--------------------------------\n");
    printf("Enum: %lu\n",sizeof(Tipo));
    printf("Float: %lu\n",sizeof(float));
    printf("Double: %lu\n",sizeof(double));
    printf("Int: %lu\n",sizeof(int));
    printf("-------------\n");
    printf("Tipo: %lu\n",sizeof(p.tipo_asignado_actualmente));
    printf("Valor: %lu\n",sizeof(p.valor)); 
    printf("El tamaño de Pseudo_Polimorfismo es de: %lu\n", sizeof(Pseudo_Polimorfismo));
    // TODO: Por que no me da 12?!?!!?!
    /*
    Aparentemente depende del compilador. Con el trucazo de PRAGMA da bien. Es un tema de configuracion del compilador.
    */
    return 0;
}