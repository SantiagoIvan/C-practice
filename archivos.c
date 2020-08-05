#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE* punteroAlArchivo = fopen("employees.txt","r");
    printf("Se creo el archivo Employees\n");
    printf("El puntero apunta al inicio del archivo %p, este puntero esta alojado en %p\n",punteroAlArchivo,&punteroAlArchivo);

    //fprintf(punteroAlArchivo,"Empleado 1\n");
    
    char linea[20];//capacidad maxima
    fgets(linea,5,punteroAlArchivo);
    printf("Linea obtenida %s\n",linea);
    fgets(linea,5,punteroAlArchivo);
    printf("Linea obtenida %s\n",linea);
    fclose(punteroAlArchivo);
    return 0;
}