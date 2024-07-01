#include <stdio.h>

int main() {
    int M1[5][5];
    int M2[5][5];
    int V[25];
    int count = 0;

    printf("Digite os elementos da matriz M1[5][5]:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &M1[i][j]);
        }
    }

    printf("Digite os elementos da matriz M2[5][5]:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &M2[i][j]);
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int x = 0; x < 5; x++) {
                for (int y = 0; y < 5; y++) {
                    if (M1[i][j] == M2[x][y]) {
                        int repetido = 0;
                        for (int k = 0; k < count; k++) {
                            if (M1[i][j] == V[k]) {
                                repetido = 1;
                                break;
                            }
                        }
                        if (!repetido) {
                            V[count++] = M1[i][j];
                        }
                        break;
                    }
                }
            }
        }
    }

    printf("Valores que existem tanto em M1 quanto em M2 (Vetor V):\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");

    return 0;
}