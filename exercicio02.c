#include <stdio.h>
#include <stdlib.h>

// ordem crescente para o vetor
void bubbleSort(int vetor[], int tamanho) {
    int i, j, temp;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                // Troca os elementos se estiverem fora de ordem
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Declaração das variáveis
    int vetor1[10];
    int vetor2[10];
    int vresultante[20];

    // Processamento - Ler elementos do primeiro vetor
    for (int loop = 0; loop < 10; loop++) {
        printf("Digite a posicao %d do primeiro vetor: ", loop + 1);
        scanf("%d", &vetor1[loop]);
    }

    // Processamento - Ler elementos do segundo vetor
    for (int loop1 = 0; loop1 < 10; loop1++) {
        printf("Digite a posicao %d do segundo vetor: ", loop1 + 1);
        scanf("%d", &vetor2[loop1]);
    }

    // Processamento - Criar vetor resultante (soma dos elementos)
    for (int loop2 = 0; loop2 < 10; loop2++) {
        vresultante[loop2] = vetor1[loop2];
        vresultante[loop2 + 10] = vetor2[loop2];
    }

    // Ordenar o vetor resultante em ordem crescente usando o Bubble Sort
    bubbleSort(vresultante, 20);

    // Exibir o vetor resultante ordenado
    printf("Resultado ordenado em ordem crescente: ");
    for (int loop3 = 0; loop3 < 20; loop3++) {
        printf("%d ", vresultante[loop3]);
    }
    printf("\n");

    return 0;
}