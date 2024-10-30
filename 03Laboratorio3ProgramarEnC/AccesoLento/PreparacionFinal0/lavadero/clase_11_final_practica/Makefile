CC=gcc-4.1

CFLAGS = -Wall -O4 -std=gnu89 -pedantic-errors -pthread
HEADERS = -I./
LIB_COMMON_H = framework/archivos.h framework/claves.h framework/semaforos.h framework/memoria.h framework/memoria_ini.h framework/cola.h framework/hilos.h framework/aleatorio.h framework/cadenas.h framework/pantalla.h framework/tiempos.h
LIB_COMMON_C = framework/archivos.c framework/claves.c framework/semaforos.c framework/memoria.c framework/memoria_ini.c framework/cola.c framework/hilos.c framework/aleatorio.c framework/cadenas.c framework/pantalla.c framework/tiempos.c
LIB_CORE_H = program/defines.h program/globals.h program/funciones.h program/productor.h program/consumidor.h program/memoria_core.h
LIB_CORE_C = program/globals.c program/funciones.c program/productor.c program/consumidor.c program/memoria_core.c

all: clean carrera jugadores 

carrera: $(LIB_COMMON_H) $(LIB_CORE_H) thread/thread_carrera.h
	$(CC) -o carrera main_carrera.c $(LIB_COMMON_C) $(LIB_CORE_C) thread/thread_carrera.c $(CFLAGS) $(HEADERS)
jugadores: $(LIB_COMMON_H) $(LIB_CORE_H) thread/thread_jugadores.h
	$(CC) -o jugadores main_jugadores.c $(LIB_COMMON_C) $(LIB_CORE_C) thread/thread_jugadores.c $(CFLAGS) $(HEADERS)

clean: 
	rm -rf *o carrera jugadores *.txt
