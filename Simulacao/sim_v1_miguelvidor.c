#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int TBC, TC, TA;
} entidade;

int main()
{
    int i, qtd, is_zero, ini_chegada, fin_chegada, ini_atendimento, fin_atendimento;
    entidade *entidades;
    
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
		
    printf ("ENT TBC TC TA\n");
    
    if (is_zero == 1){
    	entidades[0].TBC = 0;
	}
	else {
		entidades[0].TBC = ini_chegada +(rand() % (fin_chegada - ini_chegada + 1));
	}
	entidades[0].TA = ini_atendimento +(rand() % (fin_atendimento - ini_atendimento + 1));
	entidades[0].TC = entidades[0].TBC;
    
	for (i=1; i < qtd; i++) {
        entidades[i].TBC = ini_chegada +(rand() % (fin_chegada-ini_chegada+1));
		entidades[i].TC = entidades[i-1].TC + entidades[i].TBC;
		entidades[i].TA = ini_atendimento +(rand() % (fin_atendimento-ini_atendimento+1));
    }
    
    for (i=0; i < qtd; i++) printf (" %d  %d  %d  %d\n", i+1, entidades[i].TBC, entidades[i].TC, entidades[i].TA);
    
    return 0;
}