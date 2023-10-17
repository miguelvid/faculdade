/* Escreva um programa que inverta as posições de um array de tamanho 10 usando ponteiros */

#include <stdio.h>

int main() {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("original: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }

    int *start = a;            // início do array
    int *end = a + 9;          // final do array

    while (start < end) {
        // Troca os elementos apontados por start e end
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }

    printf("\ninvertido: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}