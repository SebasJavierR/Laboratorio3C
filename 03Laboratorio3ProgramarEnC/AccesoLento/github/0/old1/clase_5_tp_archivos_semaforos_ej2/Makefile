CC=gcc-4.1

CFLAGS = -Wall -O3 -std=gnu89 -pedantic-errors
HEADERS = -I./
all: clean tesorero cajero 

tesorero: defines.h gestionararchivos.h claves.h semaforos.h funciones.h productor.h consumidor.h
	$(CC) -o cci main_cci.c gestionararchivos.c claves.c semaforos.c funciones.c productor.c consumidor.c $(CFLAGS) $(HEADERS)

cajero: defines.h gestionararchivos.h claves.h semaforos.h funciones.h productor.h consumidor.h
	$(CC) -o panel main_panel.c gestionararchivos.c claves.c semaforos.c funciones.c productor.c consumidor.c $(CFLAGS) $(HEADERS)

clean: 
	rm -rf *o tesorero cajero cajero1.dat cajero2.dat cajero3.dat cajero1.*.dat cajero2.*.dat cajero3.*.dat
