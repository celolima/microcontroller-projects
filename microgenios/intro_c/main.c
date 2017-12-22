#include <stdio.h>
#include <stdlib.h>

// void imprime(unsigned char *msg);

void main () {
    printf("Teste\n");
    unsigned char *msg;
    msg = malloc(10*sizeof(char));
    msg[0] = 'M';
    msg[1] = 'a';
    msg[2] = 'r';
    msg[3] = 'c';
    msg[4] = 'e';
    msg[5] = 'l';
    msg[6] = 'o';
    printf(msg);
}
/*
void imprime(unsigned char *msg) {
    printf("Endereço : %d", msg);
    printf("Conteudo : %c",*msg);
}
*/
