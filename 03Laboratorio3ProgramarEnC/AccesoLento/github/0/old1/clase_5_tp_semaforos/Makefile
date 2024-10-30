CC=gcc-4.1

CFLAGS = -Wall -O3 -std=gnu89 -pedantic-errors
HEADERS = -I./
all: clean semaforos 

semaforos: defines.h gestionararchivos.h claves.h semaforos.h productor.h consumidor.h
	$(CC) -o semaforos main.c gestionararchivos.c claves.c semaforos.c productor.c consumidor.c $(CFLAGS) $(HEADERS)

clean: 
	rm -rf *o semaforos producto.txt
