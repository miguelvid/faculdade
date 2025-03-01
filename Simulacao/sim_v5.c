#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int TBC, TC, TA, TEA, TEF, TS, P;
} entidade;

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

int cmp_sjf(const void *a, const void *b) {
	entidade *entA = (entidade *)a;
	entidade *entB = (entidade *)b;
	return (entA->TA - entB->TA);
}

int main()
{
	int i, j, qtd, is_zero, ini_chegada, fin_chegada, ini_atendimento, fin_atendimento;
	entidade *entidades;
	float TMA = 0, TMF = 0;
	int algoritmo;

	printf("Informe a quantidade de entidades: ");
	scanf("%d", &qtd);

	entidades = (entidade*) calloc(qtd, sizeof(entidade));

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

	printf("Selecione o algoritmo (1: FCFS, 2: LCFS, 3: PRTY, 4: SJF): ");
	scanf("%d", &algoritmo);

	for (i = 0; i < qtd; i++) {
		entidades[i].P = 1 + rand() % 3;
		entidades[i].TA = ini_atendimento + (rand() % (fin_atendimento - ini_atendimento + 1));
		entidades[i].TBC = ini_chegada + (rand() % (fin_chegada - ini_chegada + 1));

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
		default:
			printf("Algoritmo inválido.\n");
			free(entidades);
			return 1;
	}

	for (i = 0; i < qtd; i++) {
		if (i == 0 || entidades[i-1].TS <= entidades[i].TC) {
			entidades[i].TEA = entidades[i].TC;
		} else {
			entidades[i].TEA = entidades[i-1].TS;
		}
		entidades[i].TEF = entidades[i].TEA - entidades[i].TC;
		entidades[i].TS = entidades[i].TEA + entidades[i].TA;

		TMA += entidades[i].TA;
		TMF += entidades[i].TEF;
	}

	printf("\nTabela Base:\n");
	printf(" E | TBC | TC | TA | P ");
	for (i = 0; i < qtd; i++) {
		printf("\n %.2d |  %.2d  | %.2d  | %.2d  | %.2d", i+1, entidades[i].TBC, entidades[i].TC, entidades[i].TA, entidades[i].P);
	}

	printf("\n\nTabela Fila:\n");
	printf(" E  | TCF | TEF | TSF");
	for (i = 0; i < qtd; i++) printf("\n %.2d | %.2d  | %.2d  | %.2d", i+1, entidades[i].TC, entidades[i].TEF, entidades[i].TS);

	printf("\n\nTabela Atendente:\n");
	printf(" E  | TI  | TT ");
	for (i = 0; i < qtd; i++) {
		printf("\n %.2d | %.2d  | %.2d ", i+1, entidades[i].TEA, entidades[i].TS);
	}

	free(entidades);
	return 0;
}
