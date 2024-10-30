#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define FILENAME "lote.dat"

int main() {
    int vuelo, num_vuelos = 0;
    char destino[20], nombre[20];
    char confirmacion = 's';

    // Crear el archivo si no existe
    int fd = open(FILENAME, O_CREAT | O_EXCL | O_WRONLY, 0666);
    if (fd == -1) {
        if (errno == EEXIST) {
            printf("El archivo ya existe\n");
        } else {
            printf("Error al crear el archivo\n");
        }
        exit(1);
    }
    close(fd);

    // Cargar vuelos hasta que el usuario ingrese el vuelo 0
    while (confirmacion == 's') {
        printf("Ingrese el número de vuelo (1000-1010): ");
        scanf("%d", &vuelo);
        if (vuelo == 0) {
            break;
        }

        printf("Ingrese el destino (Ciudad): ");
        scanf("%s", destino);

        printf("Ingrese el nombre del pasajero: ");
        scanf("%s", nombre);

        // Abrir el archivo para escritura (con bloqueo)
        fd = open(FILENAME, O_WRONLY);
        if (fd == -1) {
            printf("Error al abrir el archivo\n");
            exit(1);
        }
        if (flock(fd, LOCK_EX) == -1) {
            printf("Error al obtener el bloqueo del archivo\n");
            exit(1);
        }

        // Escribir los datos del vuelo en el archivo
        FILE *archivo = fdopen(fd, "a");
        fprintf(archivo, "%d %s %s\n", vuelo, destino, nombre);
        fclose(archivo);

        // Liberar el bloqueo y cerrar el archivo
        if (flock(fd, LOCK_UN) == -1) {
            printf("Error al liberar el bloqueo del archivo\n");
            exit(1);
        }
        close(fd);

        num_vuelos++;

        printf("¿Desea cargar otro vuelo? (s/n): ");
        scanf(" %c", &confirmacion);
    }

    printf("Se han cargado %d vuelos\n", num_vuelos);

    return 0;
}