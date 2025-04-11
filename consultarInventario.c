#include <stdio.h>
#include <ctype.h>

#define MAXIMO 100

void consultarInventario(int cant, int ID[MAXIMO], char marca[MAXIMO][20], float GB[MAXIMO], float RAM[MAXIMO], float precio[MAXIMO], char vendido[MAXIMO])
{
    char filtro;
    float montoTotalRegistrado = 0;
    float montoTotalInventario = 0;
    float montoTotalVendido = 0;

    printf("\n********** I N V E N T A R I O  C E L U L A R E S **********\n\n");
    printf("Desea aplicar un filtro (S/N): ");
    getchar(); // limpiar buffer
    scanf("%c", &filtro);
    printf("\n");

    float filtroGB = -1;
    float filtroRAM = -1;
    float filtroprecio = -1;

    if (toupper(filtro) == 'S')
    {
        printf("A continuaci%cn, especifique los datos por los que desea filtrar:\n", 162);
        printf("***** Si no desea filtrar por alguno, escriba -1 *****\n\n");

        printf("Almacenamiento (GB): ");
        scanf("%f", &filtroGB);
        printf("RAM (GB): ");
        scanf("%f", &filtroRAM);
        printf("Precio venta: ");
        scanf("%f", &filtroprecio);
        printf("\n");
    }

    // Encabezado
    printf("%-4s %13s %8s %10s %17s" "%12s\n", "ID", "Marca", "Disco", "RAM", "Precio", "Vendido");
    printf("---------------------------------------------------------------------------\n");

    ///MODIFICACIONES
    float mayor = 0;
    ///


    for (int i = 0; i < cant; i++)
    {
        // Si se activa un filtro y no se cumple >> saltar
        if ((filtroGB != -1 && GB[i] != filtroGB) ||
                (filtroRAM != -1 && RAM[i] != filtroRAM) ||
                (filtroprecio != -1 && precio[i] != filtroprecio))
        {
            continue;
        }

        printf("%-4d %13s %8.2f %10.2f %17.2f %12c\n", ID[i], marca[i], GB[i], RAM[i], precio[i], vendido[i]);

        montoTotalRegistrado = montoTotalRegistrado + precio[i];

        //cuenta el total de los celulares que quedan en inventario
        if(vendido[i]=='N')
        {
            montoTotalInventario = montoTotalInventario + precio[i];
        }
        if(vendido[i]=='S')
        {
            montoTotalVendido = montoTotalVendido + precio[i];
        }



    }

    //

    printf("---------------------------------------------------------------------------\n");
    printf("%-26s %15.2f\n", "Monto total registrado:", montoTotalRegistrado);
    printf("%-26s %15.2f\n", "Monto total inventario:", montoTotalInventario);
    printf("%-26s %15.2f\n", "Monto total vendido:", montoTotalVendido);
    printf("\n");

    ///MODIFICACIONES

    //Listar los ceulares con almacenamiento entre 128 y 512
    printf("\n----Celulares cuyo almacenamiento(Gb) esta entre 128Gb y 512Gb----");
    printf("\n---------------------------------------------------------------------------\n");

    for(int i=0; i<cant; i++)
    {
        if(GB[i]>=128 && GB[i]<=512 && vendido[i]=='S')
        {
            printf("%-4d %13s %8.2f %10.2f %17.2f %12c\n", ID[i], marca[i], GB[i], RAM[i], precio[i], vendido[i]);
        }
    }
    printf("\n---------------------------------------------------------------------------\n\n");

    float almacenaMenor;
    int menor;

    for (int i = 0; i < cant; i++)
    {
        if (i == 0)
        {
            almacenaMenor = precio[i];
            menor = i;
        }
        else if (precio[i] < almacenaMenor)
        {
            almacenaMenor = precio[i];
            menor = i;
        }
    }

    printf("\nCelular con menor precio:\n\n");
   // printf("ID: %d de Marca: %s y Precio: %.2f\n", ID[menor], marca[menor], precio[menor]);
    printf("%-4s %13s %17s", "ID", "Marca", "Precio");
    printf("\n---------------------------------------------------------------------------\n");
    printf("%-4d %13s %17.2f\n", ID[menor], marca[menor], precio[menor]);
    printf("\n---------------------------------------------------------------------------\n");
    printf("\n\n");




}
