CC=gcc-4.1

CFLAGS = -Wall -O3 -std=gnu89 -pedantic-errors
HEADERS = -I./
all: clean archivos 

archivos: defines.h gestionararchivos.h productor.h consumidor.h
	$(CC) -o archivos main.c gestionararchivos.c productor.c consumidor.c $(CFLAGS) $(HEADERS)

clean: 
	rm -rf *o archivos producto.txt
