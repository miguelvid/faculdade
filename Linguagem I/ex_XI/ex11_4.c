/*
Faça uma função que inverta dois valores passados como parâmetros para a função.
Mostre os valores invertidos antes e após a chamada da função

**Você deve passar os valores por referência
*/

#include <stdio.h>
#include <stdlib.h>

void inverte_valores(int *a, int *b)
{
    int aux;

    aux = *b;
    *b = *a;
    *a = aux;

    printf("Valor a: %d. Valor b: %d.\n", *a, *b);
}

int main()
{
    int a = 10, b = 20;
    printf("Valor a: %d. Valor b: %d.\n", a, b);
    inverte_valores(&a, &b);

    return 0;
}