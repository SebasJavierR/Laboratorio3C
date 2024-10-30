/*Librerias*/
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include "pthread.h"
/*Librerias de Headers*/
#include "framework/aleatorio.h"
#include "framework/hilos.h"
#include "framework/cola.h"
#include "program/defines.h"
#include "program/globals.h"
#include "program/funciones.h"
/*Header*/
#include "thread_hormigas.h"

void* hormigasThread(void* parametro)
{
  mensaje msg;
  hormiga* datosThread;
  int recursoAleatorio;
  int recursoTotal;
  int hormigas_finalizar;
  
  msg.longDest = MSG_NADIE;
  msg.intRte = MSG_NADIE;
  msg.intEvento = EVT_NINGUNO;
  memset(msg.charMensaje,0x00,LARGO_MENSAJE);

  datosThread = (hormiga*)parametro;

  recursoAleatorio = 0;
  recursoTotal = 0;
  hormigas_finalizar = 0;

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

        printf("La hormiga %d acaba de recolectar %d de comida\n", datosThread->nroHormiga, recursoAleatorio);
        printf("La hormiga %d recolecto personalmente %d de comida\n", datosThread->nroHormiga, datosThread->recursoComida);
        printf("En total se a recolectado %d de comida\n", recursoTotal);

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

        printf("La hormiga %d acaba de recolectar %d de hoja\n", datosThread->nroHormiga, recursoAleatorio);
        printf("La hormiga %d recolecto personalmente %d de hoja\n", datosThread->nroHormiga, datosThread->recursoHoja);
        printf("En total se a recolectado %d de hoja\n", recursoTotal);

        lockMutex(&mutex);
        enviarMensaje(datosThread->idColaMensajes, MSG_REINA, MSG_HORMIGA + datosThread->nroHormiga, EVT_END_HOJA, "");
        unlockMutex(&mutex);

        break;
      case EVT_START_PALO:
        recursoAleatorio = obtenerNumeroAleatorio(JUNTAR_MIN, JUNTAR_MAX);

        lockMutex(&mutex);
        recursoTotal = leerrecursoPalo(datosThread->memoria, 0);
        unlockMutex(&mutex);

        recursoTotal += recursoAleatorio;
        datosThread->recursoPalo += recursoAleatorio;

        lockMutex(&mutex);
        escribirrecursoPalo(datosThread->memoria, 0, recursoTotal);
        unlockMutex(&mutex);

        printf("La hormiga %d acaba de recolectar %d de palos\n", datosThread->nroHormiga, recursoAleatorio);
        printf("La hormiga %d recolecto personalmente %d de palo\n", datosThread->nroHormiga, datosThread->recursoPalo);
        printf("En total se a recolectado %d de palo\n", recursoTotal);

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

        printf("La hormiga %d acaba de recolectar %d de agua\n", datosThread->nroHormiga, recursoAleatorio);
        printf("La hormiga %d recolecto personalmente %d de agua\n", datosThread->nroHormiga, datosThread->recursoAgua);
        printf("En total se a recolectado %d de agua\n", recursoTotal);

        lockMutex(&mutex);
        enviarMensaje(datosThread->idColaMensajes, MSG_REINA, MSG_HORMIGA + datosThread->nroHormiga, EVT_END_AGUA, "");
        unlockMutex(&mutex);

        break;
      default:
        break;
    }

    if ( datosThread->recursoComida >= TOTAL_RECURSO || datosThread->recursoHoja >= TOTAL_RECURSO || datosThread->recursoPalo >= TOTAL_RECURSO || datosThread->recursoAgua >= TOTAL_RECURSO )
    {
      printf("\nLa hormiga %d alcanzo su limite personal en un recurso\n", datosThread->nroHormiga);
      printf("Esta hormiga dejara de trabajar\n\n");
      lockMutex(&mutex);
      enviarMensaje(datosThread->idColaMensajes, MSG_REINA, MSG_HORMIGA + datosThread->nroHormiga, EVT_FIN_HORMIGA, "");
      unlockMutex(&mutex);
      break;
    }

            /*UTILIZE ESTE MENU SI QUIERE QUE EL PROCESO DEJE DE FUNCIONAR CON X CANTIDAD DE RECURSOS TOTALES EN VEZ DE PERSONALES*/
    /*
    lockMutex(&mutex);
    if ( leerRecursoComida(datosThread->memoria, 0); >= TOTAL_RECURSO || leerRecursoHoja(datosThread->memoria, 0); >= TOTAL_RECURSO || leerRecursoPalo(datosThread->memoria, 0); >= TOTAL_RECURSO || leerRecursoAgua(datosThread->memoria, 0); >= TOTAL_RECURSO )
    {
      unlockMutex(&mutex);
      printf("\nLa hormiga %d alcanzo su limite personal en un recurso\n", datosThread->nroHormiga);
      printf("Esta hormiga dejara de trabajar\n\n");
      lockMutex(&mutex);
      enviarMensaje(datosThread->idColaMensajes, MSG_REINA, MSG_HORMIGA + datosThread->nroHormiga, EVT_FIN_HORMIGA, "");
      unlockMutex(&mutex);
      break;
    }
    else
      {
      unlockMutex(&mutex);
      }
    */

    usleep(INTERVALO_HORMIGA_MS * 1000);
  }
  return 0;
}
