#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXIMO 100

void registrarCelular(int cant, int ID[MAXIMO], char marca[MAXIMO][20], float GB[MAXIMO], float RAM[MAXIMO], float precio[MAXIMO])
{
    char decision;
    int indice = 0;
    int contadorCant = 0;

    // Contar cuántos celulares ya están registrados (ID != 0)
    for (int i = 0; i < cant; i++) {
        if (ID[i] != 0) {
            indice++;
        }
    }

    //Si indice (que cuenta los espacios llenos) es igual que Cant(tope de registro) entonces el registro esta lleno
    if (indice == cant) {
        printf("El inventario esta lleno!\n");
        return;
    }

    // Iniciar a llenar desde donde hay espacio (para eso es indice)
    for (int i = indice; i < cant; i++) {
        int nuevoID = 0;
        int idRepetido = 0;

        printf("Ingresa los datos del celular No.%d\n", indice+contadorCant+1);

        // Validación para evitar id repetidos
        do {
            idRepetido = 0;
            printf("ID: ");
            scanf("%d", &nuevoID);

            //valida de que el ID no este repetido
            for (int j = 0; j < cant; j++) {
                if (ID[j] == nuevoID) {
                    idRepetido = 1;
                    printf("Ese ID ya existe. Intente con otro.\n");
                    break;
                }
            }
        } while (idRepetido);

        ID[i] = nuevoID;

        printf("Marca: ");
        scanf("%s", marca[i]);
        printf("Almacenamiento (GB): ");
        scanf("%f", &GB[i]);
        printf("RAM: ");
        scanf("%f", &RAM[i]);
        printf("Precio: ");
        scanf("%f", &precio[i]);

        contadorCant++;

        if (i == cant - 1) {
            printf("El inventario se ha llenado.\n");
            return;
        }

        // Preguntar si desea registrar otro
        do {
            printf("\nDesea registrar otro celular: (S/N)\n");
            while ((getchar()) != '\n'); // Limpiar buffer
            scanf(" %c", &decision);
        } while (toupper(decision) != 'S' && toupper(decision) != 'N');

        if (toupper(decision) == 'N') {
            return;
        }
    }
}
