#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void main(){
    char ** v;
    char nombre[100];
    int cantidad = 0, cantidadNombres = 0;
    printf("Ingrese cuantos nombres habran: ");
    scanf("%d", &cantidadNombres);
    fflush(stdin);
    v =(char ** )malloc(cantidadNombres * sizeof(char *));
    for (int i = 0; i < cantidadNombres; i++){
        printf("Ingrese el nombre: ");
        gets(nombre);
        fflush(stdin);
        v[i] = (char *)malloc(strlen(nombre) * sizeof(char));
        strcpy(v[i], nombre);
    }
    for (int j = 0; j < cantidadNombres; j++){
        printf("\nNombre y Apellido: ");
        puts(v[j]);
        free(v[j]);
        free(v);
    }    
}