// Escreva   um programa que leia dois números em ponto flutuante e forneça o resultado da soma formatado com duas casas decimais //

#include <stdio.h>

int main() {
    float n1, n2;
    
    printf("Digite: ");
    scanf("%f", &n1);
    printf("Digite: ");
    scanf("  %f", &n2);

    float soma = n1 + n2;

    printf("%.2f", soma);

    return 0;
}