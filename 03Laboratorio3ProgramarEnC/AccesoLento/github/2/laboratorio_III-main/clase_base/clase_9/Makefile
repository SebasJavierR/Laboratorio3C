CC=gcc-4.1

CFLAGS = -Wall -O4 -std=gnu89 -pedantic-errors -pthread
HEADERS = -I./
all: clean uno dos 

uno: defines.h globals.h gestionararchivos.h claves.h semaforos.h memoria.h cola.h hilos.h funciones.h productor.h consumidor.h
	$(CC) -o uno main_uno.c globals.c gestionararchivos.c claves.c semaforos.c memoria.c cola.c hilos.c funciones.c productor.c consumidor.c $(CFLAGS) $(HEADERS)

dos: defines.h globals.h gestionararchivos.h claves.h semaforos.h memoria.h cola.h hilos.h funciones.h productor.h consumidor.h
	$(CC) -o dos main_dos.c globals.c gestionararchivos.c claves.c semaforos.c memoria.c cola.c hilos.c funciones.c productor.c consumidor.c $(CFLAGS) $(HEADERS)

clean: 
	rm -rf *o uno dos *.txt
