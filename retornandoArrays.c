#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// https://www.youtube.com/watch?v=EDy8BmAW3uo&list=PLn3A1FGnKiUzerbdW4Zdp3-urUG27-TKV&index=3

/* FORMA MAL HECHA SIN SENTIDO

int *return_int_array(){
    int array[]={1,2,3};
    return array;
}

int main(void){
    int a[10];
    a= return_int_array();
    return 0;
}
 1) ese array va a estar guardado en una variable local, que luego de la ejecucion de la funcion,
se limpia, por lo tanto, se estaría retornando el puntero, que tiene una dirección de memoria
correspondiente a la memoria Stack. Es ilegal acceder a esta fuera del scope de la funcion en sí.
Además luego de la ejecución de esa función, se limpia.
2) los array son inmutables, no se modifican, se puede cambiar valor por valor, pero no por asignacion
3) Ademas se está tratando de asignar un puntero a un array, lo cual en sí no tiene sentido.
*/

/* -----------------------------------------------

**********6 formas de retornar arrays******************

*/


/* FORMA NO° 1 - Retornar un string 

1- Solución más simple
2- Sólo funciona con strings
3- Ese retorno es estático.
4- Pueden llegar a ser alocados en la memoria rom.
*/
char *forma_1(){
    char *string="String literal";
    return string;
}

/* FORMA NO° 2 - Retornar variable global

1- Es accedida y modificada por todos
2- Debe ser copiada en cada llamada por el caller
3- Si son buffer muy grandes
4- Se puede operar correctamente y retornar el array.
*/
char array_global[100];
char *forma_2(){
    //hacer algo con el array
    return array_global;
}

/* FORMA NO° 3 - usar static

1- Sigue siendo accedida por otros callers, pero en un universo reducido, ya que es accedido 
solamente los que llaman a la función, no es accedida globalmente.
2- Puede ser modificada en cada llamado
3- El valor por esa razon debería ser copiado en cada llamado.
*/
char *forma_3(){
    static char array[100];
    return array;
}
/* FORMA NO° 4 - Malloc/calloc dentro de la funcion. Alojar memoria explicitamente dentro de 
la función para luego retornarlo.

1- El size del malloc es fijo.
2- El malloc, como es allocacion de memoria dinamicamente,
 reservará memoria en la memoria **Heap**.
3- Cada funcion resultará en un nuevo buffer, que va a ser diferente ante cada llamado. (pro)
4- Desemboca en fallas de Gestión de memoria si se gestiona mal la memoria dinamicamente.
    - Se puede liberar memoria que está siendo utilizada.
    - Pérdida de memoria, ya no está en uso pero queda la basura ahi de los valores viejos.
*/

char *forma_4(){
    char *buffer = malloc(100);
    return buffer;
}

/* FORMA NO° 5 - El caller aloja memoria para recibir el valor de retorno.
Le pasa a la funcion el puntero al array y el size. La funcion está totalmente abstraida
del array en particular recibido y el size, simplemente hace su trabajo.

THE CHOOSEN ONE

1- El caller se encarga de la gestion de su propia memoria necesitada. Más **cohesión**.
2- El retorno se puede utilizar como codigo de estado.
3- Le ahorra el trabajo a la funcion de ademas calcular la longitud del array recibido, para
que esté más abstraído de cualquier array de cualquier longitud.
*/

void forma_5(char *target_array, int size){
    //hace cositas
    char array[]="algo";
    strncpy(target_array,array,size);
    return;
}

/* FORMA NO°6 - Wrapear en un struct al array

1- Solo funciona para arrays de longitud fija
2- Al fin y al cabo, el usuario va a crear una struct y a copiar el valor que retorne la funcion
3- No hay gestion de memoria (pro) pero perdes
4- Alto costo de memoria por arrays grandes.

*/

struct Wrapper{
    char string[100];
};

struct Wrapper forma_6(){
    struct Wrapper aux;
    strncpy(aux.string, "algun valor",100);//fixed size
    return aux;
};
// esto es equivalente a cuando cualquier funcion retorna un int
// ese valor retornado puede ser siendo utilizado, en este caso, será una struct con sus campos
// pero es la misma mecánica.
// Cuando se crea la struct, como es una variable local, se crea en la memoria Stack.
// A la hora de retornar el valor, se reserva una porción de memoria en la memoria Stack.
// donde va a estar alojado el valor de retorno. Siempre es un int o un char,
// en este caso es un Struct.

int main(void){
    //forma 5
    int size= 100;
    char *buffer = malloc(size);
    forma_5(buffer,size);
    printf("%s\n",buffer);
    free(buffer);
    
    return 0;
}