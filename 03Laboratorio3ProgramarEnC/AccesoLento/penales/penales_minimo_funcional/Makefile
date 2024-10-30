CC=gcc-4.1

CFLAGS = -Wall -O4 -std=gnu89 -pedantic-errors -pthread
HEADERS = -I./
LIB_COMMON_H = libCommon/archivos.h libCommon/claves.h libCommon/semaforos.h libCommon/memoria.h libCommon/memoria_ini.h libCommon/cola.h libCommon/hilos.h libCommon/aleatorio.h libCommon/cadenas.h libCommon/pantalla.h libCommon/tiempos.h
LIB_COMMON_C = libCommon/archivos.c libCommon/claves.c libCommon/semaforos.c libCommon/memoria.c libCommon/memoria_ini.c libCommon/cola.c libCommon/hilos.c libCommon/aleatorio.c libCommon/cadenas.c libCommon/pantalla.c libCommon/tiempos.c
LIB_CORE_H = libCore/defines.h libCore/globals.h libCore/funciones.h libCore/productor.h libCore/consumidor.h libCore/memoria_core.h
LIB_CORE_C = libCore/globals.c libCore/funciones.c libCore/productor.c libCore/consumidor.c libCore/memoria_core.c

all: clean carrera jugadores 

carrera: $(LIB_COMMON_H) $(LIB_CORE_H) libThread/thread_carrera.h
	$(CC) -o carrera main_carrera.c $(LIB_COMMON_C) $(LIB_CORE_C) libThread/thread_carrera.c $(CFLAGS) $(HEADERS)
jugadores: $(LIB_COMMON_H) $(LIB_CORE_H) libThread/thread_jugadores.h
	$(CC) -o jugadores main_jugadores.c $(LIB_COMMON_C) $(LIB_CORE_C) libThread/thread_jugadores.c $(CFLAGS) $(HEADERS)

clean: 
	rm -rf *o carrera jugadores *.txt
