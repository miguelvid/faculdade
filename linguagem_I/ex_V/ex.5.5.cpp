#include <stdio.h>

int main() {
    int M[10][5];
    int soma = 0;
    
    printf("Digite os elementos da matriz[10][5]:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &M[i][j]);
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            soma += M[i][j];
        }
    }

    printf("soma de todos os elementos :%d\n", soma);

    return 0;
}