#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int TBC, TA;
} entidade;

int main() {
    int i, qtd = 10;
    entidade entidades[10] = {
        {0, 10},
        {7, 4},
        {3, 1},
        {4, 3},
        {6, 1},
        {8, 2},
        {5, 3},
        {9, 1},
        {7, 5},
        {1, 4}
    };
    float TMA, TMF;
    int TC, TEA, TEF, TS;

    printf("ENT TBC TA\n");

    TC = entidades[0].TBC;
    TEA = TC;
    TEF = TEA - TC;
    TS = TEA + entidades[0].TA;
    TMA = entidades[0].TA;
    TMF = 0;

    for (i = 1; i < qtd; i++) {
        TC = TC + entidades[i].TBC;
        if (TS <= TC) {
            TEA = TC;
        } else {
            TEA = TS;
        }
        TEF = TEA - TC;
        TS = TEA + entidades[i].TA;
        TMA += entidades[i].TA;
        TMF += TEF;
    }

    for (i = 0; i < qtd; i++) {
        printf("%d|   %d| %d\n", i+1, entidades[i].TBC, entidades[i].TA);
    }
    printf("\nTMA: %.2f. TMF: %.2f\n", TMA/qtd, TMF/qtd);

    return 0;
}

/*
Não sabia se tinha que fazer no codigo ou so fazer a tabela entao fiz assim.
Tempo Médio de Atendimento = 3.40
Tempo Médio de Espera na Fila = 1.20
*/