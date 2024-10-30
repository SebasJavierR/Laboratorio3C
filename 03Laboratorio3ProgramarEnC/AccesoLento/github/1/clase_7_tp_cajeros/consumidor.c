#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "defines.h"
#include "globals.h"
#include "funciones.h"

int totalCantidadDepositos;
int totalCantidadEfectivos;
int totalCantidadCheques;

int totalPesosDepositos;
int totalPesosEfectivos;
int totalPesosCheques;

int vTotalCantidadDepositos[CANT_MAX_CAJEROS];
int vTotalCantidadEfectivos[CANT_MAX_CAJEROS];
int vTotalCantidadCheques[CANT_MAX_CAJEROS];

int vTotalPesosDepositos[CANT_MAX_CAJEROS];
int vTotalPesosEfectivos[CANT_MAX_CAJEROS];
int vTotalPesosCheques[CANT_MAX_CAJEROS];

void verificarMemoriaIni(dato* memoria)
{
  int i;
  i = 0;
  while (memoria[i].inicializado != 1)
  {
    printf("Atención: Recuerde levantar el programa inicial \"tesorero\". Presione \"enter\" para continuar...\n");
    getchar();
  }

  limpiarPantalla();
}

void inicializarResumenes()
{
  totalCantidadDepositos = 0;
  totalCantidadEfectivos = 0;
  totalCantidadCheques = 0;

  totalPesosDepositos = 0;
  totalPesosEfectivos = 0;
  totalPesosCheques = 0;

  vTotalCantidadDepositos[0] = 0;
  vTotalCantidadEfectivos[0] = 0;
  vTotalCantidadCheques[0] = 0;
  vTotalCantidadDepositos[1] = 0;
  vTotalCantidadEfectivos[1] = 0;
  vTotalCantidadCheques[1] = 0;
  vTotalCantidadDepositos[2] = 0;
  vTotalCantidadEfectivos[2] = 0;
  vTotalCantidadCheques[2] = 0;

  vTotalPesosDepositos[0] = 0;
  vTotalPesosEfectivos[0] = 0;
  vTotalPesosCheques[0] = 0;
  vTotalPesosDepositos[1] = 0;
  vTotalPesosEfectivos[1] = 0;
  vTotalPesosCheques[1] = 0;
  vTotalPesosDepositos[2] = 0;
  vTotalPesosEfectivos[2] = 0;
  vTotalPesosCheques[2] = 0;
}

void imprimirResumen()
{
  int i;
  printf("TOTAL\n");
  printf("TCD\t%d\tT$D\t%d\tTCE\t%d\tT$E\t%d\tTCC\t%d\tT$C\t%d\n",
  totalCantidadDepositos,
  totalPesosDepositos,
  totalCantidadEfectivos,
  totalPesosEfectivos,
  totalCantidadCheques,
  totalPesosCheques);
  
  for (i = 0; i < CANT_MAX_CAJEROS; i++)
  {
    printf("CAJERO\t%d\n", i + 1);
    printf("TCD\t%d\tT$D\t%d\tTCE\t%d\tT$E\t%d\tTCC\t%d\tT$C\t%d\n",
    vTotalCantidadDepositos[i],
    vTotalPesosDepositos[i],
    vTotalCantidadEfectivos[i],
    vTotalPesosEfectivos[i],
    vTotalCantidadCheques[i],
    vTotalPesosCheques[i]);
  }
}

void leerDepositosCajeros(dato* memoria)
{
  int i;
  i = 0;
  while (i < CANTIDAD)
  {
    if (memoria[i].listo == 1)
    {
      if (memoria[i].cajero <= CANT_MAX_CAJEROS)
      {
        memoria[i].listo = 0;
        totalCantidadDepositos++;
        totalPesosDepositos += memoria[i].importe;
        vTotalCantidadDepositos[(memoria[i].cajero)-1]++; 
        vTotalPesosDepositos[(memoria[i].cajero)-1] += memoria[i].importe;

        if (memoria[i].cheque == 0)
        {
          totalCantidadEfectivos++;
          totalPesosEfectivos += memoria[i].importe;
          vTotalCantidadEfectivos[(memoria[i].cajero)-1]++; 
          vTotalPesosEfectivos[(memoria[i].cajero)-1] += memoria[i].importe;
        }
        else
        {
          totalCantidadCheques++;
          totalPesosCheques += memoria[i].importe;
          vTotalCantidadCheques[(memoria[i].cajero)-1]++; 
          vTotalPesosCheques[(memoria[i].cajero)-1] += memoria[i].importe;
        } 
      }
    }
    i++;
  }
}
