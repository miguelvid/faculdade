/*
Faça uma função que receba uma variável inteira por referência.
Mostre o endereço dessa variável dentro do main e dentro da função.
*/

#include <stdio.h>
#include <stdlib.h>

int *mostra_endereco(int *a)
{
    return a;
}

int main()
{
    int var = 10;
    int *p_var = &var;

    printf("Endereço em main: %p\n", p_var);
    printf("Endereço na função: %p", mostra_endereco(p_var));

    return 0;
}