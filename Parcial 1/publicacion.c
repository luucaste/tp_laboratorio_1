#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#include "publicacion.h"

int buscarLibrePublicacion (Eproducto productos[], int tam)
{
    int indice = -1;
    int i;

    for (i=0; i<tam; i++) {
            if (productos[i].estado == 0) {
                indice = i;
                break;
            }
    }
    return indice;
}

int nuevaPublicacion (Eproducto productos[], Eusuario usuarios[], int tam, int id)
{
    int indice;
    float aux;
    int auxInt;

    indice = buscarLibrePublicacion(productos, tam);

    if (indice == -1) {
        printf("\nNo hay mas espacio para cargar productos.");
    }
    else {
        productos[indice].id = id;
        printf("\nID de producto: %d\n", productos[indice].id);
        mostrarUsuario(usuarios, tam);
        printf("\nID de usuario: ");
        fflush(stdin);
        scanf("%d", &productos[indice].idusuario);
        printf("\nIngrese nombre del producto: ");
        fflush(stdin);
        scanf("%s", productos[indice].nombreProducto);
        productos[indice].estado = 1;

        printf("\nPrecio: ");
        fflush(stdin);
        scanf("%f", &aux);

        while (aux < 0) {
            printf("El precio no puede ser negativo. Reingrese: ");
            fflush(stdin);
            scanf("%f", &aux);
        }
        productos[indice].precio = aux;

        printf("\nStock: ");
        fflush(stdin);
        scanf("%d", &auxInt);

        while (auxInt < 0) {
            printf("El stock no puede ser negativo. Reingrese: ");
            fflush(stdin);
            scanf("%d", &auxInt);
        }
        productos[indice].stock = auxInt;

        printf("\n\nPublicacion ingresada en el sistema.");
    }
    return indice;
}

int buscarPublicacion (Eproducto productos[], int tam, int id)
{
    int indice = -1;
    int i;

    for (i=0;i<tam;i++) {
        indice = id;
        break;
    }
    return indice;
}

void modificarPublicacion (Eproducto productos[], int id, int tam)
{
    int indice;
    int opcion = 0;

    mostrarPublicaciones(productos, tam);

    printf("\nIngrese ID de producto a modificar: ");
    fflush(stdin);
    scanf("%d", &id);

    indice = buscarPublicacion(productos, tam, id);

    if (indice == -1) {
        printf("La publicacion no se encuentra en el sistema. Reingrese id: ");
        scanf("%d", &id);
    }
    else {
        printf("\nMenu de modificacion\n");

        printf("1. Precio\n");
        printf("2. Stock\n");

        printf("Elija opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch (opcion) {

                case 1:
                    printf("\nIngrese precio: ");
                    fflush(stdin);
                    scanf("%f", &productos[indice].precio);

                    while (productos[indice].precio < 0) {
                    printf("El precio no puede ser negativo. Reingrese: ");
                    fflush(stdin);
                    scanf("%f", &productos[indice].precio);
                    }

                    printf("\nPrecio modificado con exito.");
            break;

                case 2:
                    printf("\nIngrese stock: ");
                    fflush(stdin);
                    scanf("%d", &productos[indice].stock);

                    while (productos[indice].stock < 0) {
                        printf("El stock no puede ser negativo. Reingrese: ");
                        fflush(stdin);
                        scanf("%d", &productos[indice].stock);
                    }

                    printf("\nStock modificado con exito.");
            break;
        }
    }
}

void mostrarPublicaciones (Eproducto productos[], int tam)
{
    int i;
    printf("\nPUBLICACIONES\n");
    for (i=0;i<tam;i++) {
        if (productos[i].estado == 1) {
            if (productos[i].id >= 1 && productos[i].id <= 1000) {
                printf("\nID producto: %d", productos[i].id);
                printf("\nID usuario: %d", productos[i].idusuario);
                printf("\n\nNombre producto: %s", productos[i].nombreProducto);
                printf("\nPrecio: %f", productos[i].precio);
                printf("\nStock: %d", productos[i].stock);
                printf("\n\n+---------------+\n\n");

            }
        }
    }
}

void comprarProducto (Eproducto productos[], int tam)
{
    int indice;
    int id;

    mostrarPublicaciones(productos, tam);

    printf("\nIngrese ID del producto que desea comprar: ");
    fflush(stdin);
    scanf("%d", &id);

    indice = buscarPublicacion(productos, tam, id);

    if (indice == -1 && productos[indice].stock <= 0) {
        printf("\nproducto no encontrado o no se encuentra en stock. Reingrese: ");
        fflush(stdin);
        scanf("%d", &id);
    }
    else {
        productos[indice].estado = 2;
        printf("\nCUMPLIDO. compra concretada.\n");
    }
}


void CancelarPublicacion (Eproducto productos[], int tam)
{
    int indice;
    int id;

    mostrarPublicaciones(productos, tam);

    printf("\nIngrese ID del producto a cancelar: ");
    fflush(stdin);
    scanf("%d", &id);

    indice = buscarPublicacion(productos, tam, id);

    if (indice == -1) {
        printf("\npublicacion no encontrada. Reingrese: ");
        fflush(stdin);
        scanf("%d", &id);
    }
    else {
        productos[indice].estado = 2;
        printf("\nPublicacion cancelada.\n");
    }
}


