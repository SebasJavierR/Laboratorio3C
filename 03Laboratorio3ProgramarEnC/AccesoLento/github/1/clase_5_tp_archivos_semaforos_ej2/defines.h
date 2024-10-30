#ifndef _DEFINES_H_
#define _DEFINES_H_
#define FALSE 0
#define TRUE 1
#define CANTIDAD 10
#define DESDE 0
#define HASTA 10
#define RUTA_ARCHIVO_FTOK "/bin/ls"
#define CLAVE_BASE 33
#define ROJO 0
#define VERDE 1
#define INTERVALO_TESORERO_MS 500
#define INTERVALO_CAJERO_MIN_MS 1000
#define INTERVALO_CAJERO_MAX_MS 2500
#define LARGO_LINEA 100
#define LARGO_RUTA 100
#define RUTA_ARCHIVO_CAJERO "./cajero%d.dat"
#define RUTA_BACKUP "./cajero%d.%03d.dat"
#define IMPORTE_MIN 100
#define IMPORTE_MAX 500
#define VAL_CHEQUE 0
#define VAL_EFECTIVO 1
#define CANT_DEPOSITOS_MIN 10
#define CANT_DEPOSITOS_MAX 20
#define FORMATO_DEPOSITO "%d %d"
#define CANT_MAX_BAK 999
struct Resumen
{
  int tcEfect;
  int tsEfect;
  int tcCheq;
  int tsCheq;
  int lote;
};
typedef struct Resumen resumen;
#endif
