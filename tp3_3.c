#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define CANT 100

struct Producto{
    int productoID; //Numerado en ciclo iterativo
    int cantidad; //Entre 1 y 10
    char *TipoProducto; //Algun valor del arreglo TipoProductos
    float precioUnitario; //Entre 10 y 100
}typedef Producto;

struct Cliente{
    int clienteID; //Numerado en el ciclo iterativo
    char * nombreCliente; //Ingresado por usuario
    int cantidadProductosAPedir; //Aleatorio entre 1 y 5
    Producto * Productos; //El tamaño de este arreglo depende de la variable "CantidadProductosAPedir"
}typedef Cliente;

void cargarClientes(Cliente * arregloClientes, int cantidadClientes, char * tipoProducto);
void MostrarClientes(Cliente * arregloClientes, int cantidadClientes);

void main(){
    char * TipoProductos[] = {"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    char tProd [CANT];
    Cliente * arregloClientes;
    int cantidadClientes = 6;
    srand(time(NULL));
    while (cantidadClientes >= 5){
        printf("\nIngrese la cantidad de clientes: ");
        scanf("%d", &cantidadClientes);
        fflush(stdin);
        if (cantidadClientes > 5){
            printf("\nIngrese una cantidad menor a 5");
        }
    }
    arregloClientes = malloc(cantidadClientes * sizeof(Cliente));
    cargarClientes(arregloClientes, cantidadClientes, * TipoProductos);
    for (int i = 0; i < cantidadClientes; i++){
        for (int j = 0; j < arregloClientes[i].cantidadProductosAPedir; j++){
            strcpy(tProd, TipoProductos[rand()%5]);
            arregloClientes[i].Productos[j].TipoProducto = malloc(strlen(tProd) * sizeof(char));
            strcpy(arregloClientes[i].Productos[j].TipoProducto, tProd);
        }
    }
    
    MostrarClientes(arregloClientes, cantidadClientes);

}

void cargarClientes(Cliente * arregloClientes, int cantidadClientes, char * tipoProducto){
    char nombreCliente[CANT];
    int cantidad = 0, numeroTipoProducto = 0, cantidadArreglo = 0;
    for (int i = 0; i < cantidadClientes; i++){
        arregloClientes[i].clienteID = i+1;
        printf("\n----------Cliente N[%d]----------\n", i+1);
        printf("Ingrese el nombre del cliente: ");
        gets(nombreCliente);
        fflush(stdin);
        cantidad = strlen(nombreCliente) + 1;
        arregloClientes[i].nombreCliente = malloc(cantidad * sizeof(char));
        strcpy(arregloClientes[i].nombreCliente, nombreCliente);
        arregloClientes[i].cantidadProductosAPedir = 1 + rand()%5;
        arregloClientes[i].Productos = malloc(arregloClientes[i].cantidadProductosAPedir * sizeof(Producto));
        for (int j = 0; j < arregloClientes[i].cantidadProductosAPedir; j++){
            arregloClientes[i].Productos[j].productoID = j+1;
            arregloClientes[i].Productos[j].cantidad = 1 + rand()%11;
            arregloClientes[i].Productos[j].precioUnitario = 11 + rand()%100;
        }
    }
}

void MostrarClientes(Cliente * arregloClientes, int cantidadClientes){
    for (int i = 0; i < cantidadClientes; i++){
        float total = 0;
        printf("\n----------ID Cliente [%d]----------\n", arregloClientes[i].clienteID);
        printf("\nNombre de cliente: %s", arregloClientes[i].nombreCliente);
        printf("\nCantidad de productos pedidos: %d", arregloClientes[i].cantidadProductosAPedir);
        printf("\n==========Productos==========\n");
        for (int j = 0; j < arregloClientes[i].cantidadProductosAPedir; j++){
            printf("\n-----Producto N [%d]-----", arregloClientes[i].Productos[j].productoID);
            printf("\nCantidad de productos: %d", arregloClientes[i].Productos[j].cantidad);
            printf("\nTipo de producto: %s", arregloClientes[i].Productos[j].TipoProducto);
            printf("\nPrecio por unidad: %.2f\n", arregloClientes[i].Productos[j].precioUnitario);
            total += (arregloClientes[i].Productos[j].precioUnitario) * (arregloClientes[i].Productos[j].cantidad);
            free(arregloClientes[i].Productos[j].TipoProducto);
        }
        printf("\n|TOTAL A PAGAR|: %.2f\n", total);
        free(arregloClientes[i].Productos);
        free(arregloClientes[i].nombreCliente);
    }
    free(arregloClientes);
}