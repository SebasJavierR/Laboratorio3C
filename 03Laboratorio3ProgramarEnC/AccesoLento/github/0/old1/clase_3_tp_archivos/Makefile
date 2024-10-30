CC=gcc-4.1

CFLAGS = -Wall -O3 -std=gnu89 -pedantic-errors
HEADERS = -I./
all: productor consumidor 

productor: defines.h gestionararchivos.h 
	$(CC) -o productor productor.c gestionararchivos.c $(CFLAGS) $(HEADERS)

consumidor: defines.h gestionararchivos.h
	$(CC) -o consumidor consumidor.c gestionararchivos.c $(CFLAGS) $(HEADERS)

clean: 
	rm -rf *o productor consumidor producto.txt
