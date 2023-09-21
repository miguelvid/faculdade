
// Escreva um programa completo que leia inicialmente as duas notas de um aluno, fornecidas pelo usuário via o teclado. Se as notas não forem suficiente para o aluno  passar direto, o programa deve capturar a nota da terceira prova, também fornecida  via o teclado. Como saída, o programa deve imprimir a média final do aluno, seguida  da mensagem “Aprovado” ou “Reprovado”, conforme o critério descrito acima.

#include <stdio.h>

int main() {
    float nota1;
    float nota2;
    float nota3;
    float media;

    printf("Digite a nota da primeira prova: ");
    scanf("%f", &nota1);

    printf("Digite a nota da segunda prova: ");
    scanf("%f", &nota2);

    media = (nota1 + nota2) / 2.0;

    if (media >= 5.0) {
        printf("Média final: %.2f\n", media);
        printf("Aprovado\n");
    } else {
        printf("Digite a nota da terceira prova: ");
        scanf("%f", &nota3);

        if (nota1 > nota2) {
            media = (nota1 + nota3) / 2.0;
        } else {
            media = (nota2 + nota3) / 2.0;
        }

        if (media >= 5.0) {
            printf("Média final: %.2f\n", media);
            printf("Aprovado\n");
        } else {
            printf("Média final: %.2f\n", media);
            printf("Reprovado\n");
        }
    }

    return 0;
}