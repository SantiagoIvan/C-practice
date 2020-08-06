#include <stdio.h>
#include <stdlib.h>

void modificarX(int operando){
    static int x = 0;
    /* con el static, la variable queda en memoria 
    (sector DATA, donde están las static y global)
    guardada con su valor final para ser accedida 
    luego en las proximas llamadas a la funcion SOLAMENTE por la funcion, no es accedida globalmente
    esa variable de cualquier lugar. Solamente ejecutando esa función.
    Tambien se lo llama life extender.
    Hay otras formas de usar el static, definiendo un comportamiento diferente
    https://www.youtube.com/watch?v=kz2lQdYXsKE&list=PLn3A1FGnKiUzerbdW4Zdp3-urUG27-TKV&index=1
    */
    printf("Antes: %i\n",x);
    x=x+operando;
    printf("Despues: %i\n",x);
    return;
}

int main(void){

    modificarX(1);
    modificarX(1);
    modificarX(1);
    return 0;
}