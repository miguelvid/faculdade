#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int TBC, TC, TA, TEA, TEF, TS;
} entidade;

typedef struct {
    int TEV, ENT;
    char TpEV;
} evento;

int main()
{
    int i, j, qtd, is_zero, ini_chegada, fin_chegada, ini_atendimento, fin_atendimento, cont = 0, NrEntF = 0, NrEntS = 0, TOA = 0, auxTOA = 0;
    entidade *entidades;
    evento *eventos, eventoaux;
    float TMA, TMF;
    char EstAT = 'L';
    
    printf ("Informe a quantidade de entidades: ");
	scanf ("%d", &qtd);
    
    entidades = (entidade*) calloc (qtd, sizeof(entidade));

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
    
    if (is_zero == 1){
    	entidades[0].TBC = 0;
		eventos = (evento*) calloc (qtd * 2, sizeof(evento));
	}
	else {
		entidades[0].TBC = ini_chegada +(rand() % (fin_chegada - ini_chegada + 1));
		eventos = (evento*) calloc (qtd * 2 + 1, sizeof(evento));
    	eventos[0] = (evento) {0, 0, 'i'};
    	cont++;
	}
	
	entidades[0].TA = ini_atendimento +(rand() % (fin_atendimento - ini_atendimento + 1));
	entidades[0].TC = entidades[0].TBC;
	entidades[0].TEA = entidades[0].TC;
    entidades[0].TEF = entidades[0].TEA - entidades[0].TC;
    entidades[0].TS =  entidades[0].TEA +  entidades[0].TA;
    TMA = entidades[0].TA;
    TMF = 0;
    
	for (i=1; i < qtd; i++) {
        entidades[i].TBC = ini_chegada +(rand() % (fin_chegada-ini_chegada+1));
		entidades[i].TC = entidades[i-1].TC + entidades[i].TBC;
		entidades[i].TA = ini_atendimento +(rand() % (fin_atendimento-ini_atendimento+1));
		if (entidades[i-1].TS <= entidades[i].TC){
		    entidades[i].TEA = entidades[i].TC;
		} else {
		    entidades[i].TEA = entidades[i-1].TS;
		}
        entidades[i].TEF = entidades[i].TEA - entidades[i].TC;
        entidades[i].TS =  entidades[i].TEA +  entidades[i].TA;
        TMA += entidades[i].TA;
        TMF += entidades[i].TEF;
	}
    
    for (i = 0, j = cont; i < qtd; i++, j++, cont++) {
        eventos[j].TEV = entidades[i].TC;
        eventos[j].ENT = i + 1;
        eventos[j].TpEV = 'c';
        j++; cont++;
        eventos[j].TEV = entidades[i].TS;
        eventos[j].ENT = i + 1;
        eventos[j].TpEV = 's';
    }
 
    for (i = 0; i < cont; i++){
        for (j = i+1; j < cont; j++) {
            if (eventos[i].TEV > eventos[j].TEV){
                eventoaux = eventos[i];
                eventos[i] = eventos[j];
                eventos[j] = eventoaux;
            }   
        }
    }
 
    printf("\n%d", cont);
    printf ("\nVisao do Atendente:\n");
    printf ("TEV  ENT TpEV NrEntF NrEntS EstAT TOA\n");
    
    for (i = 0; i < cont; i++) {
        
        if (eventos[i].TpEV == 'c') {
            NrEntS++;
            if (EstAT == 'L') {
                EstAT = 'O';
                auxTOA = 0;
                TOA = entidades[eventos[i].ENT-1].TA;
            } else {
                NrEntF++;
                TOA += entidades[eventos[i].ENT-1].TA;
            }
        } else if (eventos[i].TpEV == 's') {
            NrEntS--;
            if (NrEntS == 0) {
                EstAT = 'L';
                auxTOA = TOA;
            } else {
                NrEntF--;
            }
        }
        printf (" %d|    %d|    %c|  %d| %d| %c| %d\n", eventos[i].TEV, eventos[i].ENT, eventos[i].TpEV, NrEntF, NrEntS, EstAT, auxTOA);
    }

    printf ("\nENT TBC TC TEF TEA TA TS\n");
 
    for (i=0; i < qtd; i++) printf(" %d|    %d|    %d|  %d| %d| %d| %d\n", i+1, entidades[i].TBC, entidades[i].TC, entidades[i].TEF, entidades[i].TEA, entidades[i].TA, entidades[i].TS);
    printf("TMA: %.2f. TMF: %.2f", TMA/qtd, TMF/qtd);
    return 0;
}