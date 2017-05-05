#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#include "publicacion.h"

int menu () {

    int opcion;

    printf("\n1. Alta usuario");
    printf("\n2. Modificar usuario");
    printf("\n3. Baja usuario");
    printf("\n4. Publicar producto");
    printf("\n5. Modificar publicacion");
    printf("\n6. Cancelar publicacion");
    printf("\n7. Comprar producto");
    printf("\n8. Listar publicaciones de usuario");
    printf("\n9. Listar publicaciones");
    printf("\n10. Listar usuarios");
    printf("\n11. Salir");

    printf("\nElija opcion: ");
    scanf("%d", &opcion);

    return opcion;

}

void inicializarUsuarios (Eusuario usuarios[], int tam)
{
    int i;
    for (i=0;i<tam;i++)
    {
        usuarios[i].estado = 0;
    }
}

int buscarLibre (Eusuario usuarios[], int tam)
{
    int indice=-1;
    int i;
    for (i=0;i<tam;i++)
    {
        if(usuarios[i].estado == 0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}


int buscarUsuario (Eusuario usuarios[], int tam, int id)
{
    int indice=-1;
    int i;
    for (i=0;i<tam;i++)
    {
        if (usuarios[i].id == id)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int altaUsuario (Eusuario usuarios[], int id, int tam)
{
    int indice;
    //char auxCad[40];
    indice=buscarLibre(usuarios, tam);

    if (indice==-1) {
        printf("No hay mas espacio de carga de usuarios. Verifique.\n");
    }
    else {

        usuarios[indice].id=id;
        printf("\nID: %d\n", usuarios[indice].id);

        printf("\nIngrese nombre de usuario: ");
        fflush(stdin);
        scanf("%s", usuarios[indice].usuario);

        while (strlen(usuarios[indice].usuario)>20) {
            printf("Nombre de usuario demasiado largo. Reingrese: ");
            scanf("%s", usuarios[indice].usuario);
        }

        printf("\nIngrese password: ");
        fflush(stdin);
        scanf("%s", usuarios[indice].password);

        while (strlen(usuarios[indice].password)<4) {
            printf("Password demasiado corta. Reingrese: ");
            scanf("%s", usuarios[indice].password);
        }

        usuarios[indice].estado=1;
        printf("\nUsuario cargado exitosamente.\n");
    }
    return indice;
}

void mostrarUsuario(Eusuario usuarios[], int tam)
{
    int i;

    printf("\nUsuarios habilitados\n\n");
    for (i=0;i<tam;i++)
    {
        if (usuarios[i].estado == 1)
        {
            printf("\nID: %d\n", usuarios[i].id);
            printf("Usuario: %s\n", usuarios[i].usuario);
            printf("Password: %s\n", usuarios[i].password);
            //printf("Calificacion: %f\n", usuarios[i].calificacion);
        }
    }
}

void modificarUsuario (Eusuario usuarios[], int id, int tam)
{
    int indice;
    int opcion;

    mostrarUsuario(usuarios, tam);

    printf("\nIngrese ID de usuario a modificar: ");
    fflush(stdin);
    scanf("%d", &id);

    indice = buscarUsuario(usuarios, tam, id);
    if (indice == -1) {
        printf("El usuario no se encuentra en el sistema. Reingrese id: ");
        scanf("%d", &id);
    }
    else {
        printf("\nMenu de modificacion\n");

        printf("1. Nombre de usuario\n");
        printf("2. password\n");

        printf("Elija opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch (opcion) {

                case 1:
                    printf("\nIngrese nombre de usuario: ");
                    fflush(stdin);
                    scanf("%s", usuarios[indice].usuario);

                    while (strlen(usuarios[indice].usuario)>20) {
                    printf("Nombre de usuario demasiado largo. Reingrese: ");
                    scanf("%s", usuarios[indice].usuario);
                    }
                    printf("\nNombre de usuario modificado con exito.");
            break;

                case 2:
                    printf("\nIngrese password: ");
                    fflush(stdin);
                    scanf("%s", usuarios[indice].password);

                    while (strlen(usuarios[indice].password)<4) {
                    printf("Password demasiado corta. Reingrese: ");
                    scanf("%s", usuarios[indice].password);
                    }
                    printf("\nPassword modificada con exito.");
            break;
        }
    }
}

void bajaUsuario (Eusuario usuarios[], int id, int tam)
{
    int indice;
    mostrarUsuario(usuarios, tam);

    printf("\nIngrese ID de usuario a dar de baja: ");
    scanf("%d", &id);

    indice = buscarUsuario(usuarios, tam, id);

    if (indice == -1) {
        printf("\nEl usuario no se encuentra en el sistema. Reingrese: ");
        scanf("%d", &id);
    }
    else {
        usuarios[indice].estado=2;
        printf("\nUsuario dado de baja exitosamente.");
    }
}



