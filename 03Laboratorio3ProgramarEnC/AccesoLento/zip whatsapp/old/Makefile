CC=gcc-12

CFLAGS = -Wall -O3 -std=gnu89 -pedantic-errors
HEADERS = -I./

all: clean panel control

control: control.c
	$(CC) $(CFLAGS) -o control control.c archivos.c semaforos.c clave.c $(HEADERS)

panel: panel.c
	$(CC) $(CFLAGS) -o panel panel.c archivos.c semaforos.c clave.c $(HEADERS)

clean:
	rm -rf *o panel control