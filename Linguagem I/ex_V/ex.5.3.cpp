#include <stdio.h>

int main() {
    int M[15][15];
    
    printf("Digite os elementos da matriz M[15][15]:\n");
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            scanf("%d", &M[i][j]);
        }
    }

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            int repeticoes = 0;
            for (int x = 0; x < 15; x++) {
                for (int y = 0; y < 15; y++) {
                    if (M[i][j] == M[x][y]) {
                        repeticoes++;
                    }
                }
            }
            if (repeticoes > 1) {
                printf("%d aparece %d vezes\n", M[i][j], repeticoes);
            }
        }
    }

    return 0;
}