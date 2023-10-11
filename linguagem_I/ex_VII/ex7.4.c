/* Faca um programa que leia uma variavel e então incremente
o valor dessa variavel 10 vezes utilizando ponteiro */

#include <stdio.h>

int main() {
    int v1;
    int *p1;

    printf("Digite um valor: ");
    scanf("%d", &v1);

    p1 = &v1;

    for (int i = 0; i < 10; i++, (*p1)++) {

    }
    printf("p1-->v1(%d)\n", *p1);

    return 0;
}