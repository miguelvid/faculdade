/*
Escreva uma função que dados dois arrays A e B mostre quais os elementos
de A existem em B. 

**Atenção: os arrays A e B devem ser passados como parâmetros para a função.**

*/

#include <stdio.h>

void Relacionados(int A[], int B[]) {
    printf("Elementos em comum: ");
    
    for (int i = 0; A[i] != 0; i++) {
        for (int j = 0; B[j] != 0; j++) {
            if (A[i] == B[j]) {
                printf("%d ", A[i]);
                break;
            }
        }
    }
    
    printf("\n");
}

int main() {
    int A[100];
    int B[100];
    int valor;
    int indice_A = 0;
    int indice_B = 0;

    printf("Digite o array A (insira 0 para finalizar):\n");
    do {
        scanf("%d", &valor);
        A[indice_A] = valor;
        indice_A++;
    } while (valor != 0);

    printf("Digite o array B (insira 0 para finalizar):\n");
    do {
        scanf("%d", &valor);
        B[indice_B] = valor;
        indice_B++;
    } while (valor != 0);

    Relacionados(A, B);

    return 0;
}
