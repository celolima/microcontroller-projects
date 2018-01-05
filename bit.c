#include <stdio.h>

void main() {
    unsigned int bit = 0B00000001;
    unsigned int interator = 0;
    while(interator < 8) {
        printf("Valor atual: %d\n",bit);
        bit = (bit << 1) | bit;
        interator++;
    }
}