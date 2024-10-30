# Laboratorio_III
- Alternativa a VM: https://cocalc.com/
- Alternativa a CoCalc: https://www.online-ide.com/
  - Command line arguments: -Wall -O3 -std=gnu89 -pedantic-errors -pthread
  - Copiar todos los archivos con el mismo nombre y contenido.
  - Solo es para probar ejecución, no se puede observar creación de archivos.

## USB Drive - VirtualBox
  - https://superuser.com/questions/931637/virtualbox-claims-a-usb-drive-but-hosted-centos-7-cannot-access-it
  - Solo lo pude hacer funcionar con driver USB 2.0 de VirtualBox, usando un puerto USB 2.0 y con formato FAT.

## Carpet Externa - VirtualBox
  - En general, si usamos una carpeta externa, no podemos levantar más de una instancia de un proceso.
  - PAra solucionar este problema, copiar carpeta a la VM.

## IPC
- Si cerramos un programa sin que termine de liberar los recursos compartidos. Debemos liberar estos recursos a mano.
- ipcs: https://www.man7.org/linux/man-pages/man1/ipcs.1.html
- ipcrm: https://www.man7.org/linux/man-pages/man1/ipcrm.1.html

## Signal
- signum-generic.h: https://github.com/lattera/glibc/blob/master/bits/signum-generic.h
- signal.h manpage: https://www.man7.org/linux/man-pages/man0/signal.h.0p.html
- kill: https://www.man7.org/linux/man-pages/man1/kill.1.html
- ```kill -l```: permite ver las señales y su número.

## Function Pointers
- https://cdecl.org/

## Abrir administrador de archivos desde la terminal 
- ```gnome-open .```

## Aclaración para entregas
- Las entregas deben realizarse en formato .tar
- Tratar de incluir un archivo readme con instrucciones de cómo levantar los procesos
- Compilar el programa en un entorno linux o macOS con un gcc más actualizado.
- El makefile debe entregarse con la siguiente configuración:
```
CC = gcc-4.1
CFLAGS = -Wall -Werror -O4 -std=gnu89 -pedantic-errors -pthread
```

### macOS
- Utilizar homebrew para instalar el paquete gcc. Recomiendo instalar la versión 13.
- Configuración de makefile para este entorno:
```
CC = gcc-13
CFLAGS = -Wall -Werror -O3 -std=gnu89 -pedantic-errors -pthread
```