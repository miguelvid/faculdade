#include <stdio.h>
#include "lista_dinamica_encadeada.h"

int main ( void ) {
	int opcao, operacao, elemento, no;
	lista l;
	inicializa_lista (&l);
    
    do {
		printf ("============ OPERACOES CONVENCIONAIS SOBRE A LISTA =============\n");
		printf ("Inserir:  1-Inicio  2-Fim   3-No'   4-Ordenado  10-Inverter[11]\n");
		printf ("Remover:  6-Inicio  7-Fim   8-No'   9-Elemento  12-Inicializar\n");
		printf ("Exibir.: 13-Inicio 14-Fim  15-No'  16-Tamanho   17-ElementoNo's\n");
		printf ("RemoveREPETIDOS(18-Elementos[19] 20-TodosOrdenando) 5-ESTRUTURA\n");
		printf ("21-RemoveRecursivamente    Informe a opcao (0-Sair): "); scanf  ("%d", &opcao);
        
		if (opcao == 5) exibeestrutura_lista (&l);
		
        if ((opcao > 0 && opcao < 6) && ischeia_lista (&l)) {
        	printf ("\nLista Cheia...\n\n");
        	continue;
        }
        
        if (opcao > 5 && isvazia_lista (&l)) {
        	printf ("\nLista Vazia...\n\n");
        	continue;
        }
		
		if ((opcao > 0 && opcao < 5) || opcao == 9 || (opcao > 16 && opcao < 20)) {
        	 printf ("Informe o Elemento: "); scanf ("%d", &elemento);
		}
		
		if (opcao == 3 || opcao == 8 || opcao == 15) {
			printf ("Informe o No': "); scanf  ("%d", &no);
		}
		
		if (opcao == 1) insereinicio_lista (&l, elemento);
		else if (opcao == 2) inserefim_lista (&l, elemento);
		else if (opcao == 3) insereno_lista (&l, elemento, no);
		else if (opcao == 4) insereordenado_lista (&l, elemento);
		else if (opcao == 6) removeinicio_lista (&l);
		else if (opcao == 7) removefim_lista (&l);
		else if (opcao == 8) removeno_lista (&l, no);
		else if (opcao == 9) removechave_lista (&l, elemento);
		else if (opcao == 10) inverte_lista (&l);
		else if (opcao == 11) inversao_lista (&l);
		else if (opcao == 12) libera_lista (&l);
		else if (opcao == 13) printf ("=> Primeiro Elemento: %d\n", getinicio_lista (&l));
		else if (opcao == 14) printf ("=> Ultimo Elemento: %d\n", getfim_lista (&l));

		else if (opcao == 15) {
				elemento = getchaveno_lista (&l, no);
				printf ("=> Elemento do %do.No' da lista: %d\n", no, elemento);
		}
		else if (opcao == 16) printf ("=> Tamanho (em Nos): %d\n", gettamanho_lista (&l));
		else if (opcao == 17) {
			no = getnochave_lista (&l, elemento);
			if (isoperacao_lista (&l)) printf ("=> 1o.No'encontrado: %d Presente em %d No'(s)\n", no, getquantidade_lista (&l, elemento));
		}
		else if (opcao == 18) remove_lista (&l, elemento);
		else if (opcao == 19) remocao_lista (&l, elemento);
		else if (opcao == 20) removeajusta_lista (&l);
		else if (opcao == 21) removerecursivo_lista (&l);
		
		if (opcao == 5) printf ("\n");
		else if (isoperacao_lista (&l)) printf ("Operacao Realizada...\n\n");
		else printf ("\nNo'/Elemento Inexistente OU Operacao NAO Realizada...\n");
		
	} while ( opcao != 0 );
    return ( 0 );
}

