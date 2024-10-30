# Laboratorio_III
- Alternativa a VM: https://cocalc.com/
- Alternativa a CoCalc: https://www.online-ide.com/
  - Command line arguments: -Wall -O3 -std=gnu89 -pedantic-errors -pthread
  - Copiar todos los archivos con el mismo nombre y contenido.
  - Solo es para probar ejecución, no se puede observar creación de archivos.

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
