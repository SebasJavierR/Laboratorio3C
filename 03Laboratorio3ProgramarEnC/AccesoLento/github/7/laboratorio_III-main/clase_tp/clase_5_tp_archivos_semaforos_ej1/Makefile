CC=gcc-4.1

CFLAGS = -Wall -O3 -std=gnu89 -pedantic-errors
HEADERS = -I./
all: clean carga reserva 

carga: defines.h gestionararchivos.h claves.h semaforos.h funciones.h productor.h consumidor.h
	$(CC) -o carga main_carga.c gestionararchivos.c claves.c semaforos.c funciones.c productor.c consumidor.c $(CFLAGS) $(HEADERS)

reserva: defines.h gestionararchivos.h claves.h semaforos.h funciones.h productor.h consumidor.h
	$(CC) -o reserva main_reserva.c gestionararchivos.c claves.c semaforos.c funciones.c productor.c consumidor.c $(CFLAGS) $(HEADERS)

clean: 
	rm -rf *o carga reserva lote.dat lote.*.dat
