#include <stdio.h>

int main() {
    int M[5][5];
    int SL[5] = {0};
    int SC[5] = {0};

    printf("Digite os elementos da matriz M[5][5]:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &M[i][j]);
            SL[i] += M[i][j];
            SC[j] += M[i][j];
        }
    }

    printf("Matriz M[5][5]:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    printf("Vetor SL (somas das linhas):\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", SL[i]);
    }
    printf("\n");

    printf("Vetor SC (somas das colunas):\n");
    for (int j = 0; j < 5; j++) {
        printf("%d ", SC[j]);
    }
    printf("\n");

    return 0;
}