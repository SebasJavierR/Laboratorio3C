// dado un texto caracter a caracter terminado en punto, calcular en cuantas palabras aparece la primer vocal ingresada en la primera palabra / ejemplo: "Salir hasta el Parque" = 3 

#include <stdio.h> 
#include <stdlib.h>

int main(){
    int c,cambioPalabra = 1,cont = 1,primer;
    printf("Ingrese la frase\n");
    c=getchar();
    primer = c;
    printf("Ascii primer letra: %d \n",primer);//debug
    while(c!='.')
    {
        
        if(c==' '){
            cambioPalabra=0;
            printf("Cambio de palabra CP 0\n");//debug
        }
        if(cambioPalabra==0 && primer == c){
            printf("encontro C +1 CP +1\n");//debug
            cont = cont+1;
            cambioPalabra = cambioPalabra +1;
        }
        c=getchar();

    }
    printf("La cantidad de palabras es: %d\n", cont);
    return 0;
}