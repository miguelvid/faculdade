/*
Elabore um programa que armazene valores aleatórios (veja explicação mais abaixo)
em um vetor de inteiros de 10 posições. A seguir aloque dinamicamente um segundo
vetor de inteiros como o tamanho de acordo com o total de numeros pares do  primeiro
vetor. Preencha-o com os numeros pares existentes no primeiro vetor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tamanho = 10;
    int *vetor1 = (int *)malloc(sizeof(int) * tamanho);
    int *vetor2;
    int total_pares = 0;

    srand(time(NULL));

    for (int i = 0; i < tamanho; i++) {
        vetor1[i] = rand() % 100;
    }

    for (int i = 0; i < tamanho; i++) {
        if (vetor1[i] % 2 == 0) {
            total_pares++;
        }
    }

    if (total_pares > 0) {
        vetor2 = (int *)malloc(sizeof(int) * total_pares);
        int index = 0;

        for (int i = 0; i < tamanho; i++) {
            if (vetor1[i] % 2 == 0) {
                vetor2[index] = vetor1[i];
                index++;
            }
        }

        printf("Vetor 1: ");
        for (int i = 0; i < tamanho; i++) {
            printf("%d ", vetor1[i]);
        }

        printf("\nPares(Vetor 1): ");
        for (int i = 0; i < total_pares; i++) {
            printf("%d ", vetor2[i]);
        }

        printf("\n");

        free(vetor2);
    } else {
        printf("Nenhum  par.\n");
    }

    free(vetor1);

    return 0;
}
