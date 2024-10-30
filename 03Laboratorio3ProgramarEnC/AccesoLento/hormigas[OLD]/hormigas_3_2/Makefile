CC=gcc-4.1

CFLAGS = -Wall -Werror -O4 -std=gnu89 -pedantic-errors -pthread
HEADERS = -I./
FRAMEWORK_H = framework/archivos.h framework/claves.h framework/semaforos.h framework/memoria.h framework/memoria_ini.h framework/cola.h framework/hilos.h framework/aleatorio.h framework/cadenas.h framework/pantalla.h framework/tiempos.h
FRAMEWORK_C = framework/archivos.c framework/claves.c framework/semaforos.c framework/memoria.c framework/memoria_ini.c framework/cola.c framework/hilos.c framework/aleatorio.c framework/cadenas.c framework/pantalla.c framework/tiempos.c
PROGRAM_H = program/defines.h program/globals.h program/funciones.h program/productor.h program/consumidor.h program/memoria_core.h program/menus.h
PROGRAM_C = program/globals.c program/funciones.c program/productor.c program/consumidor.c program/memoria_core.c program/menus.c

all: clean reina hormigas 

reina: $(FRAMEWORK_H) $(PROGRAM_H) thread/thread_reina.h
	$(CC) -o reina main_reina.c $(FRAMEWORK_C) $(PROGRAM_C) thread/thread_reina.c $(CFLAGS) $(HEADERS)
hormigas: $(FRAMEWORK_H) $(PROGRAM_H) thread/thread_hormigas.h
	$(CC) -o hormigas main_hormigas.c $(FRAMEWORK_C) $(PROGRAM_C) thread/thread_hormigas.c $(CFLAGS) $(HEADERS)

clean: 
	rm -rf *o reina hormigas *.txt
