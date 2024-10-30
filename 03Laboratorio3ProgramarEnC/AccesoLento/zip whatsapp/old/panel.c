#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "definiciones.h"
#include "semaforos.h"
#include "archivos.h"

int main(int argc, char *argv[])
{
    int n = 0;
    char mensaje[LARGO];
    char panel[LARGO];
    char fp[CORTO];
    fpos_t pos = (fpos_t)NULL;
    int id_semaforo = creo_semaforo();

    if (argc == 2)
    {
        n = atoi(argv[1]);
    }
    else
    {
        printf("Favor ingresar solamente el numero de panel como parametro!\n");
        exit(0);
    }

    memset(fp, 0x00, sizeof(fp));
    memset(panel, 0x00, sizeof(panel));
    memset(mensaje, 0x00, sizeof(mensaje));

    sprintf(fp, FILE_PATH, n);
    strcpy(panel, "default\n");

    printf("%s", panel);

    while (1)
    {
        memset(mensaje, 0x00, sizeof(mensaje));

        espera_semaforo(id_semaforo);
        /* inicio de seccion critica */
        leer_archivo(fp, mensaje, 60, &pos);

        if (strcmp(panel, mensaje) != 0)
        {
            memcpy(panel, mensaje, strlen(mensaje) + 1);
            printf("%s", panel);
        }

        /* fin de seccion critica */
        levanta_semaforo(id_semaforo);

        pos = (fpos_t)NULL;
        sleep(ESPERA);
    }

    return 0;
}