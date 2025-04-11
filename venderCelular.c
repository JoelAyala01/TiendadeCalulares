
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXIMO 100

void venderCelular(int cant, int ID[], char marca[][20], float GB[], float RAM[], float precio[], char vendido[], float ventasPorMarca[])
{
    int opcionVenta;
    char marcaBuscada[20];
    int idSeleccionado = -1;
    char confirmar;
    int encontrado = 0;

    printf("\n************ V E N T A   D E   C E L U L A R E S ************\n");
    printf("\nFavor seleccionar una de las siguientes opciones:\n");
    printf("1. Seleccionar celular de una lista\n");
    printf("2. Recomendar un Celular Basado en su Preferencia\n");
    printf("3. Cancelar Venta\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcionVenta);

    if (opcionVenta == 3) return;

    printf("\nEspecificar marca: ");
    scanf("%s", marcaBuscada);

    if (opcionVenta == 1)
    {
        printf("\n%-4s %10s %15s %10s %16s\n", "ID", "Marca", "Disco", "RAM", "Precio");
        printf("--------------------------------------------------------------------------\n");

        for (int i = 0; i < cant; i++)
        {
            if (strcasecmp(marca[i], marcaBuscada) == 0 && vendido[i] == 'N')
            {
                printf("%-4d %10s %15.2f %10.2f %16.2f\n", ID[i], marca[i], GB[i], RAM[i], precio[i]);
                encontrado = 1;
            }
        }

        if (encontrado == 0)
        {
            printf("No hay celulares disponibles para esta marca.\n");
            return;
        }

        printf("\nFavor especificar el ID del celular que desea o -1 para cancelar la compra: ");
        scanf("%d", &idSeleccionado);

        if (idSeleccionado == -1) return;

        for (int i = 0; i < cant; i++)
        {
            if (ID[i] == idSeleccionado && vendido[i] == 'N')
            {
                printf("\nA continuacion los datos del celular seleccionado y monto a pagar:\n");
                printf("\n%-4s %10s %15s %10s %16s\n", "ID", "Marca", "Disco", "RAM", "Precio");
                printf("--------------------------------------------------------------------------\n");
                printf("%-4d %10s %15.2f %10.2f %16.2f\n", ID[i], marca[i], GB[i], RAM[i], precio[i]);
                printf("\nTotal a Pagar: %.2f\n", precio[i]);
                printf("Desea continuar con la compra(S/N)?: ");
                fflush(stdin);
                scanf(" %c", &confirmar);

                if (toupper(confirmar) == 'S')
                {
                    vendido[i] = 'S';
                    int idx = toupper(marca[i][0]) - 'A';
                    ventasPorMarca[idx] =ventasPorMarca[idx] + precio[i];
                    printf("\nCompra registrada exitosamente!!\n");
                }
                else
                {
                    printf("\nCompra cancelada.\n");
                }
                return;
            }
        }

        printf("ID no valido o el celular ya fue vendido.\n");
    }
    else if (opcionVenta == 2)
    {
        float precioMax, ramMin, discoMin;
        printf("\nPrecio maximo permitido: ");
        scanf("%f", &precioMax);
        printf("RAM monima requerida: ");
        scanf("%f", &ramMin);
        printf("Almacenamiento minimo requerido: ");
        scanf("%f", &discoMin);

        int mejor = -1, segundo = -1;
        for (int i = 0; i < cant; i++)
        {
            if (strcasecmp(marca[i], marcaBuscada) == 0 && vendido[i] == 'N' &&
                precio[i] <= precioMax && RAM[i] >= ramMin && GB[i] >= discoMin)
            {
                if (mejor == -1 ||
                    (precio[i] < precio[mejor]) ||
                    (precio[i] == precio[mejor] && RAM[i] > RAM[mejor]) ||
                    (precio[i] == precio[mejor] && RAM[i] == RAM[mejor] && GB[i] > GB[mejor]))
                {
                    segundo = mejor;
                    mejor = i;
                }
                else if (segundo == -1 ||
                         (precio[i] < precio[segundo]) ||
                         (precio[i] == precio[segundo] && RAM[i] > RAM[segundo]) ||
                         (precio[i] == precio[segundo] && RAM[i] == RAM[segundo] && GB[i] > GB[segundo]))
                {
                    segundo = i;
                }
            }
        }

        if (mejor == -1)
        {
            printf("\nNo hay celulares que cumplan con las preferencias.\n");
            return;
        }

        printf("\nCelulares recomendados:\n");
        printf("\n%-4s %10s %15s %10s %16s\n", "ID", "Marca", "Disco", "RAM", "Precio");
        printf("--------------------------------------------------------------------------\n");
        if (mejor != -1)
            printf("%-4d %10s %15.2f %10.2f %16.2f\n", ID[mejor], marca[mejor], GB[mejor], RAM[mejor], precio[mejor]);
        if (segundo != -1)
            printf("%-4d %10s %15.2f %10.2f %16.2f\n", ID[segundo], marca[segundo], GB[segundo], RAM[segundo], precio[segundo]);

        printf("\nEscriba el ID del celular que desea comprar o -1 para cancelar: ");
        scanf("%d", &idSeleccionado);

        if (idSeleccionado == -1) return;

        for (int i = 0; i < cant; i++)
        {
            if (ID[i] == idSeleccionado && vendido[i] == 'N')
            {
                printf("\nTotal a pagar: %.2f\n", precio[i]);
                printf("Desea continuar con la compra(S/N)?: ");
                fflush(stdin);
                scanf(" %c", &confirmar);

                if (toupper(confirmar) == 'S')
                {
                    vendido[i] = 'S';
                    int idx = toupper(marca[i][0]) - 'A';
                    ventasPorMarca[idx] = ventasPorMarca[idx] + precio[i];
                    printf("\nCompra registrada exitosamente!!\n");
                }
                else
                {
                    printf("\nCompra cancelada.\n");
                }
                return;
            }
        }

        printf("ID no valido o el celular ya fue vendido.\n");
    }
}
