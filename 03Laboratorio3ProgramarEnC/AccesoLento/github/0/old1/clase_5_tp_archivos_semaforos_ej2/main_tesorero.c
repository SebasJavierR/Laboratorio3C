#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "defines.h"
#include "gestionararchivos.h"
#include "semaforos.h"
#include "funciones.h"
#include "productor.h"
#include "consumidor.h"
int main(int argc, char *argv[])
{
  int idSemaforoCajero;
  int cajeroActual;
  char* rutaArchivo;
  resumen resumenCajeroUno;
  resumen resumenCajeroDos;
  resumen resumenCajeroTres;
  resumen resumenTotal;

  if (argc != 1)
  {
    printf("Uso: ./tesorero \n");
    return 0;
  }
  
  idSemaforoCajero = creoSemaforo();
  iniciaSemaforo(idSemaforoPanel, VERDE);

  rutaArchivo = (char*)malloc(100*sizeof(char));
  memset(rutaArchivo,0x00,sizeof(rutaArchivo));
  resumenCajeroUno = (resumen)malloc(sizeof(resumen));
  resumenCajeroDos = (resumen)malloc(sizeof(resumen));
  resumenCajeroTres = (resumen)malloc(sizeof(resumen));
  resumenTotal = (resumen)malloc(sizeof(resumen));
  cajeroActual = 1;

  resumenCajeroUno.tcEfect = 0;
  resumenCajeroUno.tsEfect = 0;
  resumenCajeroUno.tcCheq = 0;
  resumenCajeroUno.tsCheq = 0;
  resumenCajeroUno.lote = 0;

  resumenCajeroDos.tcEfect = 0;
  resumenCajeroDos.tsEfect = 0;
  resumenCajeroDos.tcCheq = 0;
  resumenCajeroDos.tsCheq = 0;
  resumenCajeroDos.lote = 0;

  resumenCajeroTres.tcEfect = 0;
  resumenCajeroTres.tsEfect = 0;
  resumenCajeroTres.tcCheq = 0;
  resumenCajeroTres.tsCheq = 0;
  resumenCajeroTres.lote = 0;

  resumenTotal.tcEfect = 0;
  resumenTotal.tsEfect = 0;
  resumenTotal.tcCheq = 0;
  resumenTotal.tsCheq = 0;
  resumenTotal.lote = 0;

  while(1)
  {
    strcpy(rutaArchivo, obtenerRutaArchivoPanel(cajeroActual));
    esperaSemaforo(idSemaforoPanel);

    if (abrirLectura(rutaArchivo))
    {
      if (cajeroActual == 1)
      {
        leerCajero(&resumenCajeroUno);
        resumenTotal.tcEfect += resumenCajeroUno.tcEfect;
        resumenTotal.tsEfect += resumenCajeroUno.tsEfect;
        resumenTotal.tcCheq += resumenCajeroUno.tcCheq;
        resumenTotal.tsCheq += resumenCajeroUno.tsCheq;
        backupLote(resumenCajeroUno.lote, cajeroActual);
        resumenCajeroUno.lote++;
      }

      if (cajeroActual == 2)
      {
        leerCajero(&resumenCajeroDos);
        resumenTotal.tcEfect += resumenCajeroDos.tcEfect;
        resumenTotal.tsEfect += resumenCajeroDos.tsEfect;
        resumenTotal.tcCheq += resumenCajeroDos.tcCheq;
        resumenTotal.tsCheq += resumenCajeroDos.tsCheq;
        backupLote(resumenCajeroDos.lote, cajeroActual);
        resumenCajeroDos.lote++;
      }

      if (cajeroActual == 3)
      {
        leerCajero(&resumenCajeroTres);
        resumenTotal.tcEfect += resumenCajeroTres.tcEfect;
        resumenTotal.tsEfect += resumenCajeroTres.tsEfect;
        resumenTotal.tcCheq += resumenCajeroTres.tcCheq;
        resumenTotal.tsCheq += resumenCajeroTres.tsCheq;
        backupLote(resumenCajeroTres.lote, cajeroActual);
        resumenCajeroTres.lote++;
      }

      cerrarArchivo();
    }

    imprimirResumen("TOTAL", resumenTotal);
    imprimirResumen("CAJERO1", resumenCajeroUno);
    imprimirResumen("CAJERO2", resumenCajeroDos);
    imprimirResumen("CAJERO3", resumenCajeroTres);

    if (cajeroActual < 3)
    {
      cajeroActual++;
    }
    else
    {
      cajeroACtual = 1;
    }
    levantaSemaforo(idSemaforoPanel);
    memset(rutaArchivo,0x00,sizeof(rutaArchivo));
    usleep(INTERVALO_TESORERO_MS * 1000);
  }
  free(rutaArchivo);
  free(resumenCajeroUno);
  free(resumenCajeroDos);
  free(resumenCajeroTres);
  free(resumenTotal);
  return 0;
}
