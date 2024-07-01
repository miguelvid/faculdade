/*
Faça uma função que aloque dinamicamente uma área de memória para armazenamento de uma variável inteira.

Dentro do main(), utilize essa função para alocar DOIS inteiros (chame a função duas vezes).
Solicite ao usuário que informe os valores de cada uma das variáveis e a seguir efetue a soma
desses dois valores. Mostre o resultado da soma.
*/

#include <stdio.h>
#include <stdlib.h>

int *aloca_memoria()
{
    // Alocando memória para um inteiro
    int *ponteiro = (int *)malloc(sizeof(int));

    return ponteiro;
}

int main()
{
    int *var_1 = aloca_memoria();
    int *var_2 = aloca_memoria();

    printf("Insira o valor para var 1:");
    scanf("%d", var_1);

    printf("Insira o valor para var 2:");
    scanf("%d", var_2);

    printf("Soma: %d", *var_1 + *var_2);

    return 0;
}