/*
Faca um programa que aloque dinamicamente um array de inteiros com
tamanho fornecido pelo usuario. A seguir leia valores para esse array.
A seguir percorra o array contando quantos elementos positivos e negativos
foram informados.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho;
    
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0) {
        printf("Tamanho invalido\n");
        return 1;
    }

    int *array = (int *)malloc(sizeof(int) * tamanho);
    
    if (array == NULL) {
        printf("Erro.\n");
        return 1;
    }

    int positivos = 0;
    int negativos = 0;

    printf("Digite os valores:\n");

    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array[i]);

        if (array[i] > 0) {
            positivos++;
        } else if (array[i] < 0) {
            negativos++;
        }
    }

    printf("positivos: %d\n", positivos);
    printf("negativos: %d\n", negativos);

    free(array);

    return 0;
}