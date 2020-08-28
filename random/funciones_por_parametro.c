#include <stdio.h>
#include <stdlib.h>

#ifndef __cplusplus
typedef unsigned char bool;
static const bool False = 0;
static const bool True = 1;
#endif

int sumar_segun_criterio(int n, bool (*criterio)(int)){
    if(criterio(n)){
        return n+1;
    }else
    {
        return n;
    }
    
}

bool criterio_mayor_a_10(int n){
    return n>10;
}

bool criterio_es_par(int n){
    return n%2==0;
}


void saludar(){
    printf("holaaaa \n");
}

void ejecutar(void (*func)()){
    func();
    return;
}

int incrementar(int n){
    return n+1;
}
int restar_1(int n){
    return n-1;
}

void nuevo_incrementar(int *n){
    (*n)++;
    return;
}

int aplicar_funcion_segun_criterio(int param,int (*func)(int),bool (*criterio)(int)){
    if(criterio(param)){
        return func(param);
    }else
    {
        return param;
    }
    
}


int main(void){
    printf("Saludar: %p\n",saludar);
    printf("Saludar con ampersand: %p\n",&saludar);
    if(saludar == &saludar){
        printf("Son iguales\n");
    }
    void (*puntero_a_funcion)()=saludar;
    ejecutar(puntero_a_funcion);

    bool (*criterio)(int) = &criterio_es_par;

    int a=sumar_segun_criterio(10,criterio);
    printf("Resultado %d\n",a);

    int (*func)(int) = &incrementar;
    int res = aplicar_funcion_segun_criterio(20,func,criterio);
    printf("Resultado %d\n",res);

    nuevo_incrementar(&res);
    printf("Resultado %d\n",res);

    return 0;
}