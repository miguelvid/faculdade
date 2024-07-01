#include <stdio.h>

int main() {
    int P[3][3];
    int linhaSoma[3] = {0};
    int colunaSoma[3] = {0};

    printf("Digite os elementos da matriz P[3][3]:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &P[i][j]);
            linhaSoma[i] += P[i][j];
            colunaSoma[j] += P[i][j];
        }
    }

    int matrizPermutacao = 1;

    for (int i = 0; i < 3; i++) {
        if (linhaSoma[i] != 1 || colunaSoma[i] != 1) {
            matrizPermutacao = 0;
            break;
        }
    }

    if (matrizPermutacao) {
        printf("A matriz P permutacao.\n");
    } else {
        printf("A matriz P  Nao permutacao.\n");
    }

    return 0;
}