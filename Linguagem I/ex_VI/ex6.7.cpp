//Considere uma disciplina que adota o seguinte critério de aprovação: os alunos fazem duas provas (P1 e P2) iniciais; se a média nessas duas provas for maior ou igual a 5.0,  e se nenhuma das duas notas for inferior a 3.0, o aluno passa direto. Caso contrário, o aluno faz uma terceira prova (P3) e a média é calculada considerando-se essa terceira  nota e a maior das notas entre P1 e P2. Neste caso, o aluno é aprovado se a média final for maior ou igual a 5.0.

#include <stdio.h>

int main() {
    float p1, p2, p3, media;

    printf("Digite nota P1: ");
    scanf("%f", &p1);

    printf("Digite nota P2: ");
    scanf("%f", &p2);

    if (p1 >= 3.0 && p2 >= 3.0) {
        media = (p1 + p2) / 2.0;

        if (media >= 5.0) {
            printf("Aprovado com media %.2f\n", media);
        } else {
            printf("Digite nota P3: ");
            scanf("%f", &p3);

            float maior = (p1 > p2) ? p1 : p2;
            media = (p3 + maior) / 2.0;

            if (media >= 5.0) {
                printf("Aprovado com P3 com media %.1f\n", media);
            } else {
                printf("Reprovado com media final %.1f\n", media);
            }
        }
    } else {
        printf("Reprovado.");
    }

    return 0;
}