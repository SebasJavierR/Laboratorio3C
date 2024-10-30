#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "defines.h"
#include "funciones.h"

int obtenerNumeroAleatorio(int desde, int hasta) {
	int num = 0;
	num = (rand()%(hasta-desde+1))+desde;
	return num;
}

void obtenerNumerosAleatorios(int desde, int hasta, int tamanio, int* nums) {
	int i;
	for (i = 0; i < tamanio; i++)
	{
		int valor = (rand()%(hasta-desde+1))+desde;
		nums[i] = valor;
	}
}

void limpiarPantalla()
{
  int i;
  i = 0;
  while (i<LINEAS_PANTALLA)
  {
    printf("\n");
    i++;
  }
}

char letraMayuscula(char valor)
{
  const int delta = 'a' - 'A';
  /* Devuelve 32 en decimal
  que es la diferencia entre 'a'
  que es en ASCII decimal 97
  y 'A' que es en ASCII decimal 65 */
  if (valor <= 'z' && valor >= 'a')
  {
    valor -= delta;
  }
  return valor;
}

char letraMinuscula(char valor)
{
  const int delta = 'a' - 'A';
  /* Devuelve 32 en decimal
  que es la diferencia entre 'a'
  que es en ASCII decimal 97
  y 'A' que es en ASCII decimal 65 */
  if (valor >= 'A' && valor <= 'Z')
  {
    valor += delta;
  }
  return valor;
}

void cadenaMayuscula(char* cadena, char* cadenaMayusc)
{
  int i;
  for (i = 0; i < strlen(cadena); i++)
  {
    cadenaMayusc[i] = letraMayuscula(cadena[i]);
  }
}

void cadenaMinuscula(char* cadena, char* cadenaMinusc)
{
  int i;
  for (i = 0; i < strlen(cadena); i++)
  {
    cadenaMinusc[i] = letraMinuscula(cadena[i]);
  }
}
