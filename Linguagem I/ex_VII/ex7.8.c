/* Faça um programa que calcule a média de idade de 10 pessoas.
ATENCAO:Todas as variaveis usadas no programa devem ser manipuladas através de ponteiros */

#include <stdio.h>

int main() {
    int idades[10];
    int *pIdades = idades;
    float media = 0.0;

    for (int i = 0; i < 10; i++) {
        printf("Digite a idade da pessoa %d: ", i + 1);
        scanf("%d", pIdades);
        media += *pIdades; 
        pIdades++; 
    }

    media /= 10.0;

    printf("Media de idade: %.2f\n", media);

    return 0;
}