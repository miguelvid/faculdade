#include <stdio.h>

int main() {
    int vetor[30];
    int i;

    printf("digite:\n");
    for (i = 0; i < 30; i++) {
        printf("elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\ninversa:\n");
    for (i = 29; i >= 0; i--) {
        printf("%d ", vetor[i]);
    }

    return 0;
}