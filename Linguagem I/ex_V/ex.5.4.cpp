#include <stdio.h>

int main() {
    int R[4][5];
    int maiorElemento;
    int linhaMaior, colunaMaior;

    printf("Digite os elementos da matriz R[4][5]:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &R[i][j]);
        }
    }


    maiorElemento = R[0][0];
    linhaMaior = 0;
    colunaMaior = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (R[i][j] > maiorElemento) {
                maiorElemento = R[i][j];
                linhaMaior = i;
                colunaMaior = j;
            }
        }
    }

    printf("O maior elemento de R:%d \nE esta na posicao R:[%d][%d].\n", maiorElemento, linhaMaior, colunaMaior);


    return 0;
}