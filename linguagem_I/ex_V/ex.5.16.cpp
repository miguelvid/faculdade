#include <stdio.h>

int main() {
    int vetor1[10];
    int vetor2[10];
    int resultado[10];

    printf("primeiro vetor:\n");
    for (int i = 0; i < 10; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor1[i]);
    }

    printf("segundo vetor:\n");
    for (int i = 0; i < 10; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor2[i]);
    }

    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) { 
            resultado[i] = vetor1[i] * vetor2[i + 1]; 
        } else {
            resultado[i] = 0; 
        }
    }

    printf("\n resultante da multiplicacao das posicoes:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", resultado[i]);
    }

    return 0;
}