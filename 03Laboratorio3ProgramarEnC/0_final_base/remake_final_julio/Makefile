CC=gcc-4.1

CFLAGS = -Wall -Werror -O3 -std=gnu89 -pedantic-errors -pthread
HEADERS = -I./
LIB_COMMON_H = framework/archivos.h framework/claves.h framework/semaforos.h framework/memoria.h framework/memoria_ini.h framework/cola.h framework/hilos.h framework/aleatorio.h framework/cadenas.h framework/pantalla.h framework/tiempos.h framework/signals.h
LIB_COMMON_C = framework/archivos.c framework/claves.c framework/semaforos.c framework/memoria.c framework/memoria_ini.c framework/cola.c framework/hilos.c framework/aleatorio.c framework/cadenas.c framework/pantalla.c framework/tiempos.c framework/signals.c
LIB_CORE_H = program/defines.h program/globals.h program/funciones.h program/productor.h program/consumidor.h program/memoria_core.h program/menus.h
LIB_CORE_C = program/globals.c program/funciones.c program/productor.c program/consumidor.c program/memoria_core.c program/menus.c

all: clean partido jugador 

partido: $(LIB_COMMON_H) $(LIB_CORE_H) hilos/thread_partido.h
	$(CC) -o partido main_partido.c $(LIB_COMMON_C) $(LIB_CORE_C) hilos/thread_partido.c $(CFLAGS) $(HEADERS)
jugador: $(LIB_COMMON_H) $(LIB_CORE_H) hilos/thread_jugador.h
	$(CC) -o jugador main_jugador.c $(LIB_COMMON_C) $(LIB_CORE_C) hilos/thread_jugador.c $(CFLAGS) $(HEADERS)

clean: 
	rm -rf *o partido jugador *.txt
