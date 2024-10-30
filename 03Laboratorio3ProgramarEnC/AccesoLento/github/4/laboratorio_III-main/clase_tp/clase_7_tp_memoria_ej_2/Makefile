CC=gcc-4.1

CFLAGS = -Wall -O4 -std=gnu89 -pedantic-errors
HEADERS = -I./
all: clean peaje autos 

peaje: defines.h globals.h gestionararchivos.h claves.h semaforos.h memoria.h funciones.h productor.h consumidor.h
	$(CC) -o peaje main_peaje.c gestionararchivos.c claves.c semaforos.c memoria.c funciones.c productor.c consumidor.c $(CFLAGS) $(HEADERS)

autos: defines.h globals.h gestionararchivos.h claves.h semaforos.h memoria.h funciones.h productor.h consumidor.h
	$(CC) -o autos main_autos.c gestionararchivos.c claves.c semaforos.c memoria.c funciones.c productor.c consumidor.c $(CFLAGS) $(HEADERS)

clean: 
	rm -rf *o peaje autos *.txt
