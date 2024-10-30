#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>

#define MIN_DEPOSIT 100
#define MAX_DEPOSIT 500
#define MIN_DEPOSITS 10
#define MAX_DEPOSITS 20
#define SLEEP_MIN_MS 1000
#define SLEEP_MAX_MS 2500

sem_t *sem_cajero1, *sem_cajero2, *sem_cajero3, *sem_tesorero;

void generar_depositos(int cajero_num) {
    char filename[20];
    sprintf(filename, "cajero%d.dat", cajero_num);
    int fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, S_IRWXU);
    if (fd < 0) {
        perror("Error al abrir archivo");
        exit(EXIT_FAILURE);
    }

    int num_deposits = rand() % (MAX_DEPOSITS - MIN_DEPOSITS + 1) + MIN_DEPOSITS;

    for (int i = 0; i < num_deposits; i++) {
        int deposit = rand() % (MAX_DEPOSIT - MIN_DEPOSIT + 1) + MIN_DEPOSIT;
        int payment_method = rand() % 2;

        char deposit_type;
        if (payment_method == 0) {
            deposit_type = 'C';
        } else {
            deposit_type = 'E';
        }

        dprintf(fd, "%d %c\n", deposit, deposit_type);
    }

    close(fd);
}

void procesar_lotes(int cajero_num) {
    char filename[20];
    sprintf(filename, "cajero%d.dat", cajero_num);
    int lote_num = 0;

    while (1) {
        sem_wait(sem_cajero1);
        sem_wait(sem_cajero2);
        sem_wait(sem_cajero3);

        char new_filename[20];
        sprintf(new_filename, "cajero%d.%03d.dat", cajero_num, lote_num);
        rename(filename, new_filename);
        int fd = open(new_filename, O_RDONLY);
        if (fd < 0) {
            perror("Error al abrir archivo");
            exit(EXIT_FAILURE);
        }

        int num_deposits = 0;
        int total_deposits = 0;
        char deposit_type;
        int deposit;

        while (scanf("%d %c", &deposit, &deposit_type) == 2) {
            num_deposits++;
            total_deposits += deposit;
            if (deposit_type == 'C') {
                printf("Cajero %d: deposito cheque $%d\n", cajero_num, deposit);
            } else {
                printf("Cajero %d: deposito efectivo $%d\n", cajero_num, deposit);
            }
        }

        printf("Cajero %d: Lote %d - Cantidad de depositos: %d - Total depositado: $%d\n", cajero_num, lote_num, num_deposits, total_deposits);

        close(fd);

        sem_post(sem_cajero1);
        sem_post(sem_cajero2);
        sem_post(sem_cajero3);
        sem_wait(sem_tesorero);

        // Actualizar totales y resumen por cajero

        sem_post(sem_tesorero);

        lote_num++;

        usleep
