CC=gcc-4.1

CFLAGS = -Wall -O4 -std=gnu89 -pedantic-errors
HEADERS = -I./
all: clean pienso jugador 

pienso: defines.h globals.h gestionararchivos.h claves.h semaforos.h memoria.h funciones.h productor.h consumidor.h
	$(CC) -o pienso main_pienso.c gestionararchivos.c claves.c semaforos.c memoria.c funciones.c productor.c consumidor.c $(CFLAGS) $(HEADERS)

jugador: defines.h globals.h gestionararchivos.h claves.h semaforos.h memoria.h funciones.h productor.h consumidor.h
	$(CC) -o jugador main_jugador.c gestionararchivos.c claves.c semaforos.c memoria.c funciones.c productor.c consumidor.c $(CFLAGS) $(HEADERS)

clean: 
	rm -rf *o pienso jugador *.txt
