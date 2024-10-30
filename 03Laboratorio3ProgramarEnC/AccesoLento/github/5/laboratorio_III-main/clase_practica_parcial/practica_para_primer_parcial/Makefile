CC=gcc-4.1

CFLAGS = -Wall -O4 -std=gnu89 -pedantic-errors
HEADERS = -I./
all: clean resto sdc 

resto: defines.h gestionararchivos.h claves.h semaforos.h funciones.h productor.h consumidor.h
	$(CC) -o resto main_resto.c gestionararchivos.c claves.c semaforos.c funciones.c productor.c consumidor.c $(CFLAGS) $(HEADERS)

sdc: defines.h gestionararchivos.h claves.h semaforos.h funciones.h productor.h consumidor.h
	$(CC) -o sdc main_sdc.c gestionararchivos.c claves.c semaforos.c funciones.c productor.c consumidor.c $(CFLAGS) $(HEADERS)

clean: 
	rm -rf *o resto sdc *.txt
