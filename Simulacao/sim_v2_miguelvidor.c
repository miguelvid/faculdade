#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int TBC, TC, TA, TEA, TEF, TS;
} entidade;

int main() {
    int i, qtd, is_zero, ini_chegada, fin_chegada, ini_atendimento, fin_atendimento;
    entidade *entidades;
    float TMA, TMF;
    
    printf("Informe a quantidade de entidades: ");
    scanf("%d", &qtd);
    
    entidades = (entidade*) calloc(qtd, sizeof(entidade));

    printf("\nTempo Inicial de Chegada em Zero? (1 ou 0): ");
    scanf("%d", &is_zero);
    
    printf("Intervalo de Chegada - Inicial: ");
    scanf("%d", &ini_chegada);
    
    printf("Intervalo de Chegada - Final: ");
    scanf("%d", &fin_chegada);
    
    printf("Intervalo de Atendimento - Inicial: ");
    scanf("%d", &ini_atendimento);
    
    printf("Intervalo de Atendimento - Final: ");
    scanf("%d", &fin_atendimento);
        
    printf("ENT|TBC|TC |TEF|TEA|TA |TS \n");
    
    if(is_zero == 1) {
        entidades[0].TBC = 0;
    } else {
        entidades[0].TBC = ini_chegada + (rand() % (fin_chegada - ini_chegada + 1));
    }
    entidades[0].TA = ini_atendimento + (rand() % (fin_atendimento - ini_atendimento + 1));
    entidades[0].TC = entidades[0].TBC;
    entidades[0].TEA = entidades[0].TC;
    entidades[0].TEF = entidades[0].TEA - entidades[0].TC;
    entidades[0].TS = entidades[0].TEA + entidades[0].TA;
    TMA = entidades[0].TA;
    TMF = 0;

    for(i = 1; i < qtd; i++) {
        entidades[i].TBC = ini_chegada + (rand() % (fin_chegada - ini_chegada + 1));
        entidades[i].TC = entidades[i-1].TC + entidades[i].TBC;
        entidades[i].TA = ini_atendimento + (rand() % (fin_atendimento - ini_atendimento + 1));
        if (entidades[i-1].TS <= entidades[i].TC) {
            entidades[i].TEA = entidades[i].TC;
        } else {
            entidades[i].TEA = entidades[i-1].TS;
        }
        entidades[i].TEF = entidades[i].TEA - entidades[i].TC;
        entidades[i].TS = entidades[i].TEA + entidades[i].TA;
        TMA += entidades[i].TA;
        TMF += entidades[i].TEF;
    }

    for(i = 0; i < qtd; i++) {
        printf(" %d | %d | %d | %d | %d | %d | %d\n", i+1, entidades[i].TBC, entidades[i].TC, entidades[i].TEF, entidades[i].TEA, entidades[i].TA, entidades[i].TS);
    }
    printf("TMA: %.2f. TMF: %.2f\n", TMA/qtd, TMF/qtd);

    free(entidades);
    return 0;
}