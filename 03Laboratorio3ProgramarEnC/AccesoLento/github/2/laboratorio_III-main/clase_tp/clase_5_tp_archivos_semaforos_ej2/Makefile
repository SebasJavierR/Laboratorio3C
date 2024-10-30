CC=gcc-4.1

CFLAGS = -Wall -O4 -std=gnu89 -pedantic-errors
HEADERS = -I./
all: clean tesorero cajero 

tesorero: defines.h gestionararchivos.h claves.h semaforos.h funciones.h productor.h consumidor.h
	$(CC) -o tesorero main_tesorero.c gestionararchivos.c claves.c semaforos.c funciones.c productor.c consumidor.c $(CFLAGS) $(HEADERS)

cajero: defines.h gestionararchivos.h claves.h semaforos.h funciones.h productor.h consumidor.h
	$(CC) -o cajero main_cajero.c gestionararchivos.c claves.c semaforos.c funciones.c productor.c consumidor.c $(CFLAGS) $(HEADERS)

clean: 
	rm -rf *o tesorero cajero cajero*.dat
