/*Librerias*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "tiempos.h"

/*Devuelve el tiempo en ms*/
int obtenerTiempoTranscurrido(tiempo tiempoInicio, tiempo tiempoFin)
{
    int secInicio, microInicio;
    int inicio;
    int secFin, microFin;
    int fin;

    secInicio = tiempoInicio.tv_sec & 0xFFF;
    microInicio = tiempoInicio.tv_usec;
    inicio = (secInicio * 1000) + (microInicio / 1000);

    secFin = tiempoFin.tv_sec & 0xFFF;
    microFin = tiempoFin.tv_usec;
    fin = (secFin * 1000) + (microFin / 1000);
    return fin - inicio;
}

int obtenerTiempoActual(tiempo* tiempoActual)
{
    return gettimeofday(tiempoActual, 0);
}

