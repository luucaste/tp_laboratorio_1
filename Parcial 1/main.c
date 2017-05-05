#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#include "publicacion.h"

int main()
{
    char seguir = 's';

    Eusuario usuarios[100];
    Eproducto productos[1000];

    int idusuarios = 100;
    int idproducto = 1;
    int altaU;
    int altaP;

    inicializarUsuarios(usuarios, 100);

    do {

        switch (menu()) {

            case 1:
                altaU = altaUsuario(usuarios, idusuarios, 100);
                if (altaU != -1) {
                    idusuarios++;
                }
        break;

            case 2:
                modificarUsuario(usuarios, idusuarios, 100);
        break;

            case 3:
                bajaUsuario(usuarios, idusuarios, 100);
        break;

            case 4:
                altaP = nuevaPublicacion(productos, usuarios, 100, idproducto);
                if (altaP != -1) {
                    idproducto++;
                }
        break;

            case 5:
                modificarPublicacion(productos, idproducto, 100);
        break;

            case 6:
                CancelarPublicacion(productos, 100);
        break;

            case 7:
                comprarProducto(productos, 100);
        break;

            case 8:
        break;

            case 9:
                mostrarPublicaciones(productos, 100);
                system("pause");
        break;

            case 10:
                mostrarUsuario(usuarios, 100);
                system("pause");
        break;

            case 11:
            seguir='n';
        break;
        }
    system("cls");
    }while(seguir=='s');

    return 0;
}
