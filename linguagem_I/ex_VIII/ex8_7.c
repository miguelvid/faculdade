
/*
Inicialize um vetor de 10 posicoes de inteiros aleatoriamente. (use a funcao rand() ).
Mostre  todo o vetor usando dois ponteiros : um começando do início do vetor e outro do final.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tamanho = 10;
    int vetor[tamanho];

    srand(time(NULL));

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100;
    }

    int *inicio = &vetor[0];
    int *fim = &vetor[tamanho - 1];

    printf("do inicio:\n");
    
    while (inicio <= fim) {
        printf("%d ", *inicio);
        inicio++;
    }
    printf("\n");

    printf("do fim:\n");

    while (fim >= &vetor[0]) {
        printf("%d ", *fim);
        fim--;
    }
    printf("\n");

    return 0;
}

/* pedi ajuda pro gpt essa pq n saibia como usar a funçao direito.*/