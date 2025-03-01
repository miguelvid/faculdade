#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int TBC, TC, TA, TEA, TEF, TS, P, tempo_restante;
} entidade;

typedef struct {
    int tempo;
    int entidade_id;
    char tipo;
} evento;

int cmp_fcfs(void *a, void *b) {
    entidade *entA = (entidade *)a;
    entidade *entB = (entidade *)b;
    return (entA->TC - entB->TC);
}

int cmp_prioridade(void *a, void *b) {
    entidade *entA = (entidade *)a;
    entidade *entB = (entidade *)b;
    return (entA->P - entB->P);
}

int cmp_sjf(void *a, void *b) {
    entidade *entA = (entidade *)a;
    entidade *entB = (entidade *)b;
    return (entA->TA - entB->TA);
}

void round_robin(entidade *entidades, int qtd, int quantum, evento *eventos, int *event_count) {
    int tempo = 0, completou = 0, i;
    while (completou < qtd) {
        for (i = 0; i < qtd; i++) {
            if (entidades[i].tempo_restante > 0) {
                entidades[i].TEA = tempo;

                eventos[*event_count].tempo = tempo;
                eventos[*event_count].entidade_id = i + 1;
                eventos[*event_count].tipo = 'E';
                (*event_count)++;

                if (entidades[i].tempo_restante <= quantum) {
                    tempo += entidades[i].tempo_restante;
                    entidades[i].tempo_restante = 0;
                    completou++;
                    entidades[i].TS = tempo;
                    entidades[i].TEF = entidades[i].TS - entidades[i].TA - entidades[i].TC;

                    eventos[*event_count].tempo = tempo;
                    eventos[*event_count].entidade_id = i + 1;
                    eventos[*event_count].tipo = 'S';
                    (*event_count)++;
                } else {
                    tempo += quantum;
                    entidades[i].tempo_restante -= quantum;

                    eventos[*event_count].tempo = tempo;
                    eventos[*event_count].entidade_id = i + 1;
                    eventos[*event_count].tipo = 'S';
                    (*event_count)++;
                }
            }
        }
    }
}

int cmp_evento(void *a, void *b) {
    evento *eventoA = (evento *)a;
    evento *eventoB = (evento *)b;
    return (eventoA->tempo - eventoB->tempo);
}

int main() {
    int i, qtd, is_zero, ini_chegada, fin_chegada, ini_atendimento, fin_atendimento, quantum, algoritmo;
    entidade *entidades;
    evento *eventos;
    int event_count = 0;
    float TMA = 0, TMF = 0;

    printf("Informe a quantidade de entidades: ");
    scanf("%d", &qtd);

    entidades = (entidade*) calloc(qtd, sizeof(entidade));
    eventos = (evento*) malloc(qtd * 20 * sizeof(evento));

    printf("Tempo Inicial de Chegada em Zero? (1 ou 0): ");
    scanf("%d", &is_zero);

    printf("Intervalo de Chegada - Inicial: ");
    scanf("%d", &ini_chegada);

    printf("Intervalo de Chegada - Final: ");
    scanf("%d", &fin_chegada);

    printf("Intervalo de Atendimento - Inicial: ");
    scanf("%d", &ini_atendimento);

    printf("Intervalo de Atendimento - Final: ");
    scanf("%d", &fin_atendimento);

    printf("Selecione o algoritmo (1: FCFS, 2: LCFS, 3: PRTY, 4: SJF, 5: RR): ");
    scanf("%d", &algoritmo);

    if (algoritmo == 5) {
        printf("Informe o valor do quantum: ");
        scanf("%d", &quantum);
    }

    for (i = 0; i < qtd; i++) {
        entidades[i].P = 1 + rand() % 3;
        entidades[i].TA = ini_atendimento + (rand() % (fin_atendimento - ini_atendimento + 1));
        entidades[i].TBC = ini_chegada + (rand() % (fin_chegada - ini_chegada + 1));
        entidades[i].tempo_restante = entidades[i].TA;

        if (i == 0) {
            entidades[i].TC = is_zero ? 0 : entidades[i].TBC;
        } else {
            entidades[i].TC = entidades[i-1].TC + entidades[i].TBC;
        }
    }

    switch (algoritmo) {
        case 1:
            qsort(entidades, qtd, sizeof(entidade), cmp_fcfs);
            break;
        case 2:
            for (i = 0; i < qtd / 2; i++) {
                entidade temp = entidades[i];
                entidades[i] = entidades[qtd - i - 1];
                entidades[qtd - i - 1] = temp;
            }
            break;
        case 3:
            qsort(entidades, qtd, sizeof(entidade), cmp_prioridade);
            break;
        case 4:
            qsort(entidades, qtd, sizeof(entidade), cmp_sjf);
            break;
        case 5:
            round_robin(entidades, qtd, quantum, eventos, &event_count);
            break;
        default:
            printf("Algoritmo inválido.\n");
            free(entidades);
            free(eventos);
            return 1;
    }

    for (i = 0; i < qtd; i++) {
        if (algoritmo != 5) {
            if (i == 0 || entidades[i-1].TS <= entidades[i].TC) {
                entidades[i].TEA = entidades[i].TC;
            } else {
                entidades[i].TEA = entidades[i-1].TS;
            }
            entidades[i].TEF = entidades[i].TEA - entidades[i].TC;
            entidades[i].TS = entidades[i].TEA + entidades[i].TA;
        }

        TMA += entidades[i].TA;
        TMF += entidades[i].TEF;
    }

    printf("\nTabela Base:\n");
    printf(" E | TBC | TC | TA | P ");
    for (i = 0; i < qtd; i++) {
        printf("\n %.2d |  %.2d  | %.2d  | %.2d  | %.2d", i+1, entidades[i].TBC, entidades[i].TC, entidades[i].TA, entidades[i].P);
    }

    if (algoritmo == 5) {
        qsort(eventos, event_count, sizeof(evento), cmp_evento);

        printf("\n\nTabela Fila Round Robin:\n");
        printf(" Tempo | Entidade | Tipo ");
        for (i = 0; i < event_count; i++) {
            printf("\n %.2d    |    %.2d    |  %c ", eventos[i].tempo, eventos[i].entidade_id, eventos[i].tipo);
        }

        printf("\n\nTabela Atendente Round Robin:\n");
        printf(" Tempo | Entidade | Tipo ");
        for (i = 0; i < event_count; i++) {
            if (eventos[i].tipo == 'E') {
                printf("\n %.2d    |    %.2d    |  I ", eventos[i].tempo, eventos[i].entidade_id);
            } else {
                printf("\n %.2d    |    %.2d    |  T ", eventos[i].tempo, eventos[i].entidade_id);
            }
        }
    } else {
        printf("\n\nTabela Fila:\n");
        printf(" E  | TCF | TEF | TSF");
        for (i = 0; i < qtd; i++) {
            printf("\n %.2d | %.2d  | %.2d  | %.2d", i+1, entidades[i].TC, entidades[i].TEF, entidades[i].TS);
        }

        printf("\n\nTabela Atendente:\n");
        printf(" E  | TI  | TT ");
        for (i = 0; i < qtd; i++) {
            printf("\n %.2d | %.2d  | %.2d ", i+1, entidades[i].TEA, entidades[i].TS);
        }
    }

    free(entidades);
    free(eventos);
    return 0;
}