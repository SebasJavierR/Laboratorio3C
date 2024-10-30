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
#include "program/menu_base.h"
/*Header*/
#include "thread_reina.h"

void reinaAcciones(int opcion, int idColaMensajes, int hormiga_actual)
{
    switch (opcion) {

      case OP_AGUA: 
        printf("La hormiga numero %d empezo a recolectar agua\n", hormiga_actual + 1);
        lockMutex(&mutex);
        enviarMensaje(idColaMensajes, MSG_HORMIGA + hormiga_actual, MSG_REINA, EVT_START_AGUA, "");
        unlockMutex(&mutex);
        break;

      case OP_PALO: 
        printf("La hormiga numero %d empezo a recolectar Palos\n", hormiga_actual + 1);
        lockMutex(&mutex);
        enviarMensaje(idColaMensajes, MSG_HORMIGA + hormiga_actual, MSG_REINA, EVT_START_PALO, "");
        unlockMutex(&mutex);
        break;

      case OP_HOJA:
        printf("La hormiga numero %d empezo a recolectar hojas\n", hormiga_actual + 1);
        lockMutex(&mutex);
        enviarMensaje(idColaMensajes, MSG_HORMIGA + hormiga_actual, MSG_REINA, EVT_START_HOJA, "");
        unlockMutex(&mutex);
        break;

      case OP_COMIDA:
        printf("La hormiga numero %d empezo a recolectar comidas\n", hormiga_actual + 1);
        lockMutex(&mutex);
        enviarMensaje(idColaMensajes, MSG_HORMIGA + hormiga_actual, MSG_REINA, EVT_START_COMIDA, "");
        unlockMutex(&mutex);
        break;

      default:
        break;
        
    }
}

void* reinaThread(void* parametro)
{
  mensaje msg;
  reina* datosThread;
  int recursoComida;
  int recursoHoja;
  int recursoPalo;
  int recursoAgua;
  int hormigas_finalizar;
  int i;
  int opcion;
  int hormiga_actual;

  msg.longDest = MSG_NADIE;
  msg.intRte = MSG_NADIE;
  msg.intEvento = EVT_NINGUNO;
  memset(msg.charMensaje,0x00,LARGO_MENSAJE);

  datosThread = (reina*)parametro;
  recursoComida = 0;
  recursoHoja = 0;
  recursoPalo = 0;
  recursoAgua = 0;
  opcion = -1;
  hormigas_finalizar = 0;
  hormiga_actual = -1;

  for (i = 0; i < hormigas_totales; i++)
  {
    opcion = menuBase(i);
    reinaAcciones(opcion, datosThread->idColaMensajes, i);
  }

  while(1)
  {
    lockMutex(&mutex);
    recibirMensaje(datosThread->idColaMensajes, MSG_REINA, &msg);
    unlockMutex(&mutex);
    hormiga_actual = msg.intRte - MSG_HORMIGA;
    switch(msg.intEvento)
    {
      case EVT_NINGUNO:
        break;
      case EVT_END_COMIDA:
        printf("La hormiga numero %d termino la recoleccion de comida\n", hormiga_actual + 1);
        break;
      case EVT_END_HOJA:
        printf("La hormiga numero %d termino la recoleccion de hojas\n", hormiga_actual + 1);
        break;
      case EVT_END_PALO:
        printf("La hormiga numero %d termino la recoleccion de palos\n", hormiga_actual + 1);
        break;
      case EVT_END_AGUA:
        printf("La hormiga numero %d termino la recoleccion de agua\n", hormiga_actual + 1);
        break;
      case EVT_FIN_HORMIGA:
        printf("La hormiga %d dejo de trabjar\n", hormiga_actual + 1);
        printf("*");
        hormigas_finalizar++;
        hormiga_actual = -1;
        break;
      default:
        break;
    }

    lockMutex(&mutex);
    recursoComida = leerRecursoComida(datosThread->memoria, 0);
    recursoHoja = leerRecursoHoja(datosThread->memoria, 0);
    recursoPalo = leerrecursoPalo(datosThread->memoria, 0);
    recursoAgua = leerRecursoAgua(datosThread->memoria, 0);
    unlockMutex(&mutex);

    printf("\n-----RECURSOS TOTALES-----\n");
    printf("Comida: %d unidades\n", recursoComida);
    printf("Hojas: %d unidades\n", recursoHoja);
    printf("Palos: %d unidades\n", recursoPalo);
    printf("Agua: %d unidades\n", recursoAgua);
    printf("--------------------------\n\n");
 
    if (hormigas_finalizar >= hormigas_totales)
    {
      /*printf("DEBUG: thead_Reina\n");*/
      printf("La reina ya no tiene hormigas para dar hordenes\n");
      break;
    }

    if (hormiga_actual >= 0)
    {
      opcion = menuBase(hormiga_actual);
      reinaAcciones(opcion, datosThread->idColaMensajes, hormiga_actual);
    }

    usleep(INTERVALO_REINA_MS * 1000);
  }
  return 0;
}
