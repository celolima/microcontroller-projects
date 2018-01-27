#include <stdio.h>
#include <stdlib.h>

// void imprime(unsigned char *msg);

void main () {
    printf("Teste\n");
    unsigned int valor = 1023;
    unsigned int resultado = 0;
    resultado = (valor * 100) / 1023;
    printf("Resultado 1: %d\n",resultado);
    resultado = (valor * 100) / 255;
    printf("Resultado 2: %d\n",resultado);
}
