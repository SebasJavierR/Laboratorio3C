CC=gcc-4.1

CFLAGS = -Wall -O3 -std=gnu89 -pedantic-errors
HEADERS = -I./
all : programa

programa: funciones.h 
	$(CC) -o programa clase_2_c.c funciones.c $(CFLAGS) $(HEADERS)

clean: 
	rm -rf *o programa
