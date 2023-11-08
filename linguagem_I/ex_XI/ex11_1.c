/*
Faça uma função que receba uma variável inteira por valor. Mostre o endereço
dessa variável dentro do main e dentro da função.
*/

#include <stdio.h>
#include <stdlib.h>

int *mostra_endereco(int a)
{
    int *pa = &a;

    return pa;
}

int main()
{
    int a = 10;
    int *ponte = &a;

    printf("Detro da main: %p\n", ponte);
    printf("Endereco dentro da funcao: %p", mostra_endereco(a));

    return 0;
}