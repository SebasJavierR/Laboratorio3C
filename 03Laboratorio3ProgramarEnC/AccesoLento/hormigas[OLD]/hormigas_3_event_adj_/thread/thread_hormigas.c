/*Standard Library*/
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include "pthread.h"
/*Headers Library*/
#include "framework/aleatorio.h"
#include "framework/hilos.h"
#include "framework/cola.h"
#include "program/defines.h"
#include "program/globals.h"
#include "program/funciones.h"
/*File Header*/
#include "thread_hormigas.h"

void* hormigasThread(void* parametro)
{
  mensaje msg;
  hormiga* datosThread;
  int recursoAleatorio;
  int recursoTotal;
  int cantHormigasFin;
  
  msg.longDest = MSG_NADIE;
  msg.intRte = MSG_NADIE;
  msg.intEvento = EVT_NINGUNO;
  memset(msg.charMensaje,0x00,LARGO_MENSAJE);

  datosThread = (hormiga*)parametro;

  recursoAleatorio = 0;
  recursoTotal = 0;
  cantHormigasFin = 0;

  while(1)
  {
    lockMutex(&mutex);
    recibirMensaje(datosThread->idColaMensajes, MSG_HORMIGA + datosThread->nroHormiga, &msg);
    unlockMutex(&mutex);
    switch(msg.intEvento)
    {
      case EVT_NINGUNO:
        break;
      case EVT_START_COMIDA:
        recursoAleatorio = obtenerNumeroAleatorio(JUNTAR_MIN, JUNTAR_MAX);
        lockMutex(&mutex);
        recursoTotal = leerRecursoComida(datosThread->memoria, 0);
        unlockMutex(&mutex);
        recursoTotal += recursoAleatorio;
        datosThread->recursoComida += recursoAleatorio;
        lockMutex(&mutex);
        escribirRecursoComida(datosThread->memoria, 0, recursoTotal);
        unlockMutex(&mutex);
        printf("Hormiga %d: obtuvo %d recurso comida\n", datosThread->nroHormiga, recursoAleatorio);
        printf("Hormiga %d: total local -> %d recurso comida\n", datosThread->nroHormiga, datosThread->recursoComida);
        printf("Hormiga %d: total global -> %d recurso comida\n", datosThread->nroHormiga, recursoTotal);
        lockMutex(&mutex);
        enviarMensaje(datosThread->idColaMensajes, MSG_REINA, MSG_HORMIGA + datosThread->nroHormiga, EVT_END_COMIDA, "");
        unlockMutex(&mutex);
        break;
      case EVT_START_HOJA:
        recursoAleatorio = obtenerNumeroAleatorio(JUNTAR_MIN, JUNTAR_MAX);
        lockMutex(&mutex);
        recursoTotal = leerRecursoHoja(datosThread->memoria, 0);
        unlockMutex(&mutex);
        recursoTotal += recursoAleatorio;
        datosThread->recursoHoja += recursoAleatorio;
        lockMutex(&mutex);
        escribirRecursoHoja(datosThread->memoria, 0, recursoTotal);
        unlockMutex(&mutex);
        printf("Hormiga %d: obtuvo %d recurso hoja\n", datosThread->nroHormiga, recursoAleatorio);
        printf("Hormiga %d: total local -> %d recurso hoja\n", datosThread->nroHormiga, datosThread->recursoHoja);
        printf("Hormiga %d: total global -> %d recurso hoja\n", datosThread->nroHormiga, recursoTotal);
        lockMutex(&mutex);
        enviarMensaje(datosThread->idColaMensajes, MSG_REINA, MSG_HORMIGA + datosThread->nroHormiga, EVT_END_HOJA, "");
        unlockMutex(&mutex);
        break;
      case EVT_START_PALO:
        recursoAleatorio = obtenerNumeroAleatorio(JUNTAR_MIN, JUNTAR_MAX);
        lockMutex(&mutex);
        recursoTotal = leerRecursoRama(datosThread->memoria, 0);
        unlockMutex(&mutex);
        recursoTotal += recursoAleatorio;
        datosThread->recursoRama += recursoAleatorio;
        lockMutex(&mutex);
        escribirRecursoRama(datosThread->memoria, 0, recursoTotal);
        unlockMutex(&mutex);
        printf("Hormiga %d: obtuvo %d recurso rama\n", datosThread->nroHormiga, recursoAleatorio);
        printf("Hormiga %d: total local -> %d recurso rama\n", datosThread->nroHormiga, datosThread->recursoRama);
        printf("Hormiga %d: total global -> %d recurso rama\n", datosThread->nroHormiga, recursoTotal);
        lockMutex(&mutex);
        enviarMensaje(datosThread->idColaMensajes, MSG_REINA, MSG_HORMIGA + datosThread->nroHormiga, EVT_END_PALO, "");
        unlockMutex(&mutex);
        break;
      case EVT_START_AGUA:
        recursoAleatorio = obtenerNumeroAleatorio(JUNTAR_MIN, JUNTAR_MAX);
        lockMutex(&mutex);
        recursoTotal = leerRecursoAgua(datosThread->memoria, 0);
        unlockMutex(&mutex);
        recursoTotal += recursoAleatorio;
        datosThread->recursoAgua += recursoAleatorio;
        lockMutex(&mutex);
        escribirRecursoAgua(datosThread->memoria, 0, recursoTotal);
        unlockMutex(&mutex);
        printf("Hormiga %d: obtuvo %d recurso agua\n", datosThread->nroHormiga, recursoAleatorio);
        printf("Hormiga %d: total local -> %d recurso agua\n", datosThread->nroHormiga, datosThread->recursoAgua);
        printf("Hormiga %d: total global -> %d recurso agua\n", datosThread->nroHormiga, recursoTotal);
        lockMutex(&mutex);
        enviarMensaje(datosThread->idColaMensajes, MSG_REINA, MSG_HORMIGA + datosThread->nroHormiga, EVT_END_AGUA, "");
        unlockMutex(&mutex);
        break;
      default:
        break;
    }

    if (datosThread->recursoComida >= TOTAL_RECURSO
    || datosThread->recursoHoja >= TOTAL_RECURSO
    || datosThread->recursoRama >= TOTAL_RECURSO
    || datosThread->recursoAgua >= TOTAL_RECURSO)
    {
      printf("Hormiga %d: alcanzó recurso local máximo\n", datosThread->nroHormiga);
      printf("Hormiga %d: fin de trabajo\n", datosThread->nroHormiga);
      lockMutex(&mutex);
      enviarMensaje(datosThread->idColaMensajes, MSG_REINA, MSG_HORMIGA + datosThread->nroHormiga, EVT_FIN_HORMIGA, "");
      unlockMutex(&mutex);
      break;
    }

    usleep(INTERVALO_HORMIGA_MS * 1000);
  }
  return 0;
}
