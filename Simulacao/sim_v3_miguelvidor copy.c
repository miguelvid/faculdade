#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int TBC, TC, TA, TEA, TEF, TS;
} entidade;

typedef struct {
    int TEV, ENT;
    char TpEV;
} evento;

int main() {
    int i, j, qtd, is_zero, ini_chegada, fin_chegada, ini_atendimento, fin_atendimento;
    int evento_count = 0;
    entidade *entidades;
    evento *eventos;
    float TMA, TMF;
    
    printf("Informe a quantidade de entidades: ");
    scanf("%d", &qtd);
    
    entidades = (entidade*) calloc(qtd, sizeof(entidade));
    eventos = (evento*) calloc(qtd, sizeof(evento));
    
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
    TMF = entidades[0].TEF;
    
    eventos[evento_count++] = (evento){entidades[0].TC, 1, 'c'};
    eventos[evento_count++] = (evento){entidades[0].TS, 1, 's'};


    for(i = 1; i < qtd; i++) {
        entidades[i].TBC = ini_chegada + (rand() % (fin_chegada - ini_chegada + 1));
        entidades[i].TC = entidades[i-1].TC + entidades[i].TBC;
        entidades[i].TA = ini_atendimento + (rand() % (fin_atendimento - ini_atendimento + 1));
        
        if (entidades[i-1].TS <= entidades[i].TC) {
            entidades[i].TEA = entidades[i].TC;
        } else {
            entidades[i].TEA = entidades[i-1].TS;
        
        }
        eventos[evento_count++] = (evento){entidades[i].TC, i + 1, 'c'};

        entidades[i].TEF = entidades[i].TEA - entidades[i].TC;
        entidades[i].TS = entidades[i].TEA + entidades[i].TA;
        TMA += entidades[i].TA;
        TMF += entidades[i].TEF;
        
    
        eventos[evento_count++] = (evento){entidades[i].TS, i + 1, 's'};
    }

    for(i = 0; i < evento_count - 1; i++) {
        for(j = i + 1; j < evento_count; j++) {
            if(eventos[i].TEV > eventos[j].TEV) {
                evento temp = eventos[i];
                eventos[i] = eventos[j];
                eventos[j] = temp;
            }
        }
    }

    printf("\nVisão do Atendente:\n");
    printf("TEV | ENT | TpEV\n");
    for(i = 0; i < evento_count; i++) {
        printf("%3d | %3d |  %c\n", eventos[i].TEV, eventos[i].ENT, eventos[i].TpEV);
    }

    printf("\nENT|TBC|TC |TEF|TEA|TA |TS \n");
    for(i = 0; i < qtd; i++) {
        printf(" %d | %d | %d | %d | %d | %d | %d\n", i+1, entidades[i].TBC, entidades[i].TC, entidades[i].TEF, entidades[i].TEA, entidades[i].TA, entidades[i].TS);
    }
    printf("TMA: %.2f. TMF: %.2f\n", TMA/qtd, TMF/qtd);

    free(entidades);
    free(eventos);
    return 0;
}
