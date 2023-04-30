#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define CANT 5

void main(){
    char *v[CANT];
    char nombre[100];
    int cantidad = 0;
    for (int i = 0; i < CANT; i++){
        printf("Ingrese el nombre: ");
        gets(nombre);
        fflush(stdin);
        cantidad = strlen(nombre);
        v[i] = malloc(cantidad * sizeof(char));
        strcpy(v[i], nombre);
    }
    for (int j = 0; j < CANT; j++){
        printf("\nNombre y Apellido: %s", v[j]);
        free(v[j]);
    }    
}