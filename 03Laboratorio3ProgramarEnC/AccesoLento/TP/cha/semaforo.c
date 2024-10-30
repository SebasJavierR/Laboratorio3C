#include <semaphore.h>

sen_t *sem_open (
    const char *name, /*Nombre del semaforo*/
    int oflag, /*flags*/
    mode_t mode, /*permisos*/
    unsigned int value /*valor inicial*/
) ;

sem_t *sem_open (
    const char *name, /*nombre del semaforo*/
    int oflag, /*flag*/
);

/*--------------*/
#include <semaphore.h>

/* Devuelve 0 si todo correcto o 1 en caso de error*/
int sem_close (sem_t *sem);
int sem_unlink (const char *name);


/*--------------*/
#include <semaphore.h>

/* Devuelve 0 si todo correcto o -1 en caso de error*/
int sem_wait (sem_t *sem);
int sem_post (sem_t *sem);

/*--------------*/
#include <semaphore.h>

typedef int bool;
#define false 0
#define true 1

/* Crea un semaforo POSIX*/
sem_t *crear_sem (const char * name, unsigned int valor);

/* Obtener un semaforo POSIX (ya existente)*/
sem_t *get_sem (const char *name);

/*Cierra un semaforo POSIX*/
void destruir_sem (const char *name);

/* Incrementa el semaforo*/
void signal_sem (sem_t *sem);

/*Decrementa el semaforo*/
void wait_sem (sem_t *sem);

/*--------------*/
#include <mman.h>

/*devuelve el descriptor de arcivo 0 -1 si error*/
int shm_open(
    const char *name, /*nombre del segmento*/
    int oflag, /*flags*/
    mode_t mode /*permisos*/
);

/*devuelve 0 si todo correcto o -1 en caso de error*/
int shm_unlink(
    const char *name /*nombre del segmento*/
);

/*--------------*/
#include <unistd.h>

int close(
    int fd /*descriptor del archivo*/
);

/*--------------*/
#include <unistd.h>
#include <sys/types.h>

int ftruncate(
    int fd, /*descriptor de archivo*/
    off_t length /*nueva longitud*/ 
)

/*--------------*/
#include <sys/mman.h>

void *mmap(
    void *addr, /*direccion de memoria*/
    size_t length, /*longitud del segmento*/
    int prot, /* proteccion*/
    int flags, /*flags*/
    int fd, /*descriptor de archivo*/
    off_t offset /*desplazamiento*/
);

int munmap(
    void *addr, /*direccion de memoria*/
    size_t lenght /*longitud del segmento*/
);

/*--------------*/
/*crea un objeto de memoria compartida*/

/*devuelve el descriptor de archivo*/
int crear_var (const char * name, int valor);

/*obiene el descriptor asociado a la variable*/
int obtener_var (const char * name);

/*destruye el objeto de memoria compartida*/
int destruir_var (const char * name;

/*modifica el valor del objeto de memoria compartida*/
int modificar_var (int shm_fd, int valor);

/*devuelve el valor del objeto de memoria compartida*/
void consultar_var (int shm_fd, int *valor);

/*--------------*/
int crear_var (const char *name, int valor) {
    int shm_fd;
    int *p;

    /*Abre el objeto de memoria compartida*/
    shm_fd = shm_open(name, 0_CREAT | 0_RDWR, 0644);
    if (shm_fd == -1) {
        fprintf(stderr, "error al crear la variable: %s \n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    /*Establecer el tamaño*/
    if (ftruncate(shm_fd, sizeof(int)) == -1) {
        fprintf(stderr, "error al truncar la variable: %s \n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    /*Mapeo del objeto de memoria compartida*/
    p= mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (p == MAP_FAILED) {
        fprintf(stderr, "error al mapear la variable: %s \n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    *p = valor;
    munmap(p, sizeof(int));

    return shm_fd;
}