#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FILENAME "lote.dat"

int main() {
    int num_lote = 0;
    int num_reservas_total = 0;
    char nombre[20], destino[20];
    int vuelo, pasajeros;

    while (1) {
        // Comprobar si hay un nuevo lote
        char lote_filename[30];
        sprintf(lote_filename, "lote.%03d.dat", num_lote);
        int fd = open(lote_filename, O_RDONLY);
        if (fd != -1) {
            printf("Se encontró un nuevo lote: %s\n", lote_filename);

            // Procesar el lote
            FILE *archivo = fdopen(fd, "r");
            while (fscanf(archivo, "%d %s %s", &vuelo, destino, nombre) != EOF) {
                printf("%d %s %s\n", vuelo, destino, nombre);
                num_reservas_total++;
            }
            fclose(archivo);

            // Renombrar el archivo del lote procesado
            char new_filename[30];
            sprintf(new_filename, "lote.%03d.dat", num_lote++);
            rename(lote_filename, new_filename);
        } else {
            printf("No se encontró un nuevo lote\n");
        }

        printf("Total de reservas recibidas: %d\n", num_reservas_total);

        // Esperar 300 ms antes de la próxima comprobación del archivo
        usleep(300000);
    }

    return 0;
}
