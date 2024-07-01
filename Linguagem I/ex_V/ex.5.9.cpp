#include <stdio.h>

int main() {
    int B[5][5];
    
    printf("Digite os elementos da matriz B[5][5]:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    
    int maiorSoma = 0;
    int linhaMaiorSoma = 0;
    
    for (int i = 0; i < 5; i++) {
        int somaLinha = 0;
        for (int j = 0; j < 5; j++) {
            somaLinha += B[i][j];
        }
        if (somaLinha > maiorSoma) {
            maiorSoma = somaLinha;
            linhaMaiorSoma = i;
        }
    }
    
    printf("maior soma linha:%d, com soma de:%d.\n", linhaMaiorSoma + 1, maiorSoma);
    
    return 0;
}