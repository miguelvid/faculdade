#include <stdio.h>

int main() {
    int A[5][5];
    int diagonalSum = 0;
    int diagonalVector[5];

    printf("Digite os elementos da matriz A[5][5]:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 0; i < 5; i++) {
        diagonalSum += A[i][i];
        diagonalVector[i] = A[i][i];
    }

    printf("soma da diagonal principal de A: %d\n", diagonalSum);

    printf("diagonal principal em um vetor S:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", diagonalVector[i]);
    }
    printf("\n");

    return 0;
}