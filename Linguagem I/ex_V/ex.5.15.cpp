#include <stdio.h>

int main() {
    int matriz[5][5];
    int vetor[5];
    int i, j;

    printf("elementos da matriz 5x5:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("elementos do vetor:\n");
    for (i = 0; i < 5; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\n existem tanto no vetor quanto na matriz:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (vetor[i] == matriz[i][j]) {
                printf("%d ", vetor[i]);               
            }
        }
    }

    return 0;
}