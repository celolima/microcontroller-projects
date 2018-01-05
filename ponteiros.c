#include <stdio.h>

void inc(unsigned int *val) {
    printf("Valor atual: %d\n", (*val)++);
}

void main() {
    unsigned int bit = 0, iter = 0;
    while(iter<5) {
        inc(&bit);
        iter++;
    }    
}