CC=gcc-4.1

CFLAGS = -Wall -Werror -O4 -std=gnu89 -pedantic-errors -pthread
HEADERS = -I./
LIB_COMMON_H = libCommon/archivos.h libCommon/claves.h libCommon/semaforos.h libCommon/memoria.h libCommon/memoria_ini.h libCommon/cola.h libCommon/hilos.h libCommon/aleatorio.h libCommon/cadenas.h libCommon/pantalla.h libCommon/tiempos.h libCommon/signals.h
LIB_COMMON_C = libCommon/archivos.c libCommon/claves.c libCommon/semaforos.c libCommon/memoria.c libCommon/memoria_ini.c libCommon/cola.c libCommon/hilos.c libCommon/aleatorio.c libCommon/cadenas.c libCommon/pantalla.c libCommon/tiempos.c libCommon/signals.c
LIB_CORE_H = libCore/defines.h libCore/globals.h libCore/funciones.h libCore/productor.h libCore/consumidor.h libCore/menus.h
LIB_CORE_C = libCore/globals.c libCore/funciones.c libCore/productor.c libCore/consumidor.c libCore/menus.c

all: clean resto sdc 

resto: $(LIB_COMMON_H) $(LIB_CORE_H)
	$(CC) -o resto main_resto.c $(LIB_COMMON_C) $(LIB_CORE_C) $(CFLAGS) $(HEADERS)
sdc: $(LIB_COMMON_H) $(LIB_CORE_H)
	$(CC) -o sdc main_sdc.c $(LIB_COMMON_C) $(LIB_CORE_C) $(CFLAGS) $(HEADERS)

clean: 
	rm -rf *o resto sdc *.txt
