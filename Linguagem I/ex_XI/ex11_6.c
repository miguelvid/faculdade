/*
Faça uma função que aloque dinamicamente uma área de memória para armazenamento de um array de
inteiros com tamanho recebido com parâmetro.

Dentro do main(), solicite ao usuário que informe um tamanho para o array a ser alocado.
Invoque a função passando como parâmetro esse tamanho. A seguir, peça para o usuário
fornecer cada um dos valores do array. Mostre os valores armazenados.

** Não esqueça de liberar a memória alocada.
*/

#include <stdio.h>
#include <stdlib.h>

int *aloca_array(int tamanho)
{
    int *ptr = (int *)malloc(tamanho * sizeof(int));

    return ptr;
}

int main()
{
    int tamanho_dado;
    int *array;

    printf("Insira o tamanho do array: ");
    scanf("%d", &tamanho_dado);

    array = aloca_array(tamanho_dado);

    for (int i = 0; i < tamanho_dado; i++)
    {
        printf("Insira valor para adicionar a array: ");
        scanf("%d", &array[i]);
    }

    printf("Array:\n");
    for (int i = 0; i < tamanho_dado; i++)
    {
        printf("%d ", array[i]);
    }

    free(array);

    return 0;
}