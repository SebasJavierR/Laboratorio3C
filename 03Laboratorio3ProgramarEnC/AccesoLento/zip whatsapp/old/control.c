#include <stdlib.h>
#include <string.h>
#include "archivos.h"
#include "semaforos.h"
#include "definiciones.h"

int main(int argc, char *argv[])
{
    int opcion = 0;
    int panel = 0;
    int id_semaforo = creo_semaforo();
    char fp[CORTO];
    char mensaje[LARGO];
    fpos_t pos = (fpos_t)NULL;

    inicia_semaforo(id_semaforo, VERDE);

    do
    {
        puts("Opcion 1: Leer panel (selecione 1):");
        puts("Opcion 2: Escribir panel (seleccione 2):");
        puts("Opcion 3: Ingrese 0 para salir...");
        scanf("%d", &opcion);

        if (opcion == 1 || opcion == 2)
        {
            puts("Ingrese numero de panel");
            scanf("%d", &panel);
            memset(fp, 0x00, sizeof(panel));
            memset(mensaje, 0x00, sizeof(mensaje));
            sprintf(fp, FILE_PATH, panel);

            if (opcion == 1)
            {
                espera_semaforo(id_semaforo);
                /* inicio de seccion critica*/
                leer_archivo(fp, mensaje, LARGO, &pos);
                printf("El mensaje leido: %s\n", mensaje);
                /* fin de seccion critica */
                levanta_semaforo(id_semaforo);
            }
            else if (opcion == 2)
            {
                puts("Ingrese mensaje");
                scanf("%s", mensaje);
                espera_semaforo(id_semaforo);
                /* inicio de seccion critica */
                escribir_archivo(fp, mensaje);
                /* fin de seccion critica */
                levanta_semaforo(id_semaforo);
            }
        }
        else if (opcion != 0)
        {
            puts("Ingrese una opcion valida!");
        }

        pos = (fpos_t)NULL;

    } while (opcion != 0);

    return 0;
}
