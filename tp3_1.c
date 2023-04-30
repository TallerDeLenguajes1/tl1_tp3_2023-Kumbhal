#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ANIO 5
#define MES 12

void main(){
    int matrizProduccion[ANIO][MES];
    int gananciaAnual[ANIO];
    srand(time(NULL));
    for (int z = 0; z < ANIO; z++){
        gananciaAnual[z] = 0;
    }
    for (int i = 0; i < ANIO; i++){
        for (int j = 0; j < MES; j++){
            matrizProduccion[i][j] = 10000 + rand()%50000;
            printf("|%d|", matrizProduccion[i][j]);
            gananciaAnual[i] = matrizProduccion [i][j] + gananciaAnual [i];
        }
        printf("\nGanancia anual = %d\n", gananciaAnual[i]/12);
    }
    
}