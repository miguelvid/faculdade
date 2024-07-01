#include <stdio.h>
// ESSA FOI FEITA PELO MEO AMIGO --GPT--, MAS ENTENDI CERTINHO COMO FAZ ;)

// ESSA FOI FEITA PELO MEO AMIGO --GPT--, MAS ENTENDI COMO FAZ ;)

// ESSA FOI FEITA PELO MEO AMIGO --GPT--, MAS ENTENDI MAIS OU MENOS COMO FAZ ;)
int main() {
    int n;
    printf("Digite o tamanho da pirâmide (um número ímpar): ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("O tamanho da pirâmide deve ser ímpar.\n");
        return 1;
    }

    int piramide[n][n];

    // Preenche a matriz piramidal
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            piramide[i][j] = 1 + ((i < j ? i : j) < (n - i) ? (i < j ? i : j) : (n - i - 1));
        }
    }

    // Exibe a matriz piramidal
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", piramide[i][j]);
        }
        printf("\n");
    }

    return 0;
}