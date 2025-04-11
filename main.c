#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"

#define REGISTRAR 1
#define VENDER 2
#define INVENTARIO 3
#define CONSULTA_VENTAS 4
#define SALIR 5
#define MAXIMO 100

int main()
{
    int ID[MAXIMO];
    char marca[MAXIMO][20];
    float GB[MAXIMO];
    float RAM[MAXIMO];
    float precio[MAXIMO];
    char vendido[MAXIMO];
    float ventasPorMarca[26];


    memset(ID, 0, sizeof(ID));
    memset(GB, 0, sizeof(GB));
    memset(RAM, 0, sizeof(RAM));
    memset(precio, 0, sizeof(precio));
    memset(vendido, 'N', sizeof(vendido));
    memset(ventasPorMarca, 0, sizeof(ventasPorMarca));

    int cant = 0;
    int opcion;


    do
    {

        menu();
        printf("\nSeleccione opci%cn: ", 162);
        scanf("%d", &opcion);

        switch(opcion)
        {
        case REGISTRAR:
            //valida que solo se pregunte la primera vez
            if(cant==0)
            {
                printf("Favor introduzca la cantidad total de celulares a registrar: ");
                scanf("%d", &cant);
            }

            //validacion que sea una valor valido
            if(cant<=0)
            {
                printf("Valor invalido!\n");
                cant=0;
            }
            //funcion para registrar celular
            registrarCelular(cant, ID, marca, GB, RAM, precio);
            break;
        case VENDER:
            venderCelular(cant, ID, marca, GB, RAM, precio, vendido, ventasPorMarca);
            break;
        case INVENTARIO:
            consultarInventario(cant, ID, marca, GB, RAM, precio, vendido);
            break;
        case CONSULTA_VENTAS:
            printf("\n\n----------***SECCION EN CONSTRUCCION***----------\n\n");
            break;
        case SALIR:
            return 0;
            break;
        default:
            printf("\nINGRESE UNA OPCION VALIDA!!!");
        }

        system("pause");
        system("cls");
    }
    while(1);

    return 0;
}
