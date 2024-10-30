CC=gcc-4.1

CFLAGS = -Wall -O4 -std=gnu89 -pedantic-errors -pthread
HEADERS = -I./
LIB_H = libCore/defines.h libCore/globals.h libCommon/archivos.h libCommon/claves.h libCommon/semaforos.h libCommon/memoria.h libCommon/cola.h libCommon/hilos.h libCommon/aleatorio.h libCommon/cadenas.h libCommon/pantalla.h libCore/funciones.h libCore/productor.h libCore/consumidor.h libCore/memoria_core.h
LIB_C = libCore/globals.c libCommon/archivos.c libCommon/claves.c libCommon/semaforos.c libCommon/memoria.c libCommon/cola.c libCommon/hilos.c libCommon/aleatorio.c libCommon/cadenas.c libCommon/pantalla.c libCore/funciones.c libCore/productor.c libCore/consumidor.c libCore/memoria_core.c
all: clean pienso 

pienso: $(LIB_H) libThread/thread_pienso.h
	$(CC) -o pienso main_pienso.c $(LIB_C) libThread/thread_pienso.c $(CFLAGS) $(HEADERS)

clean: 
	rm -rf *o pienso *.txt
