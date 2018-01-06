#include <stdio.h>

void main() {
    unsigned int *a, *b, c = 2, d = 6;
    printf("Before - %d\n",*a);
    a = &c;
    printf("After - %d\n",*a);
    printf("Adress c - %d\n",&c);
    printf("Adress a - %d\n",&a);
    printf("Adress pointed by a - %d\n",a);
}