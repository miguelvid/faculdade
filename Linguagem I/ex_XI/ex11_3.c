/*
Faça uma função que incremente um valor passado como parâmetro.
Mostre o valor antes da chamada da função e ele incrementado após a chamada.

**Você deve passar o valor por referência
*/

#include <stdio.h>
#include <stdlib.h>

int aumenta_valor(int *a)
{
    int valor = *a;
    valor++;

    return valor;
}

int main()
{
    int valor = 1;

    printf("Valor antes: %d\n", valor);
    printf("Valor depois: %d\n", aumenta_valor(&valor));

    return 0;
}