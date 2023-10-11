/* Elabore um programa que declare 4 variáveis do tipo inteiro(a, b, c, d)
e 4 do tipo ponteiro de inteiro(pa, pb, pc, pd) .  Leia os 4 valores para
as variaveis inteiras e então efetue a soma dos quatro valores utilizando os ponteiros. */

#include <stdio.h>

int main() {
    int a, b, c, d;
    int *pa, *pb, *pc, *pd;

    printf("Digite o valor de a: ");
    scanf("%d", &a);
    printf("Digite o valor de b: ");
    scanf("%d", &b);
    printf("Digite o valor de c: ");
    scanf("%d", &c);
    printf("Digite o valor de d: ");
    scanf("%d", &d);

    pa = &a;
    pb = &b;
    pc = &c;
    pd = &d;

    int soma = *pa + *pb + *pc + *pd;

    printf("Soma: %d\n", soma);

    return 0;
}