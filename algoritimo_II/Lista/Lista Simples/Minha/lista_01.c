#include <stdio.h>
#include <stdlib.h>

typedef struct  No {
    int dado;
    struct No *proximo;
}No;

// Verifica se esta vazia
int listavazia (No **lista) {
    return (lista == NULL);
}

// Inseri elementos no inicio da Lista
void inserirNoInicio(No **lista, int valor) {
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->dado = valor;
        novo->proximo = *lista;
        *lista = novo;
    }
    else
        printf("Erro ao alocar memoria\n");  
}

// Inseri elementos no meio da Lista
void inserirNoMeio(No **lista, int referencia, int valor) {
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->dado = valor;
        if(*lista == NULL) {
            novo->proximo = NULL;
            *lista = novo;
        }
        else {
            No *aux = *lista;
            while (aux->dado != referencia && aux->proximo)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("Erro ao alocar memoria");  
}

// Inseri elementos no final da Lista
void inserirNoFinal(No **lista, int valor) {
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->dado = valor;
        novo->proximo = NULL;
        if(*lista == NULL) {
            *lista = novo;
        }
        else {
            No *aux = *lista;
            while (aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("Erro ao alocar memoria");  
}

// Iseri um elemento na lista em ordem numerica
void inserirOrdenado(No **lista, int valor) {
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->dado = valor;
        if(*lista == NULL) {
            novo->proximo = NULL;
            *lista = novo;
        }
        else if(novo->dado < (*lista)->dado) {
            novo->proximo = *lista;
            *lista = novo;
        }
        else {
            No *aux = *lista;
            while(aux->proximo && novo->dado > aux->proximo->dado)
                aux = aux->proximo;
            novo->proximo = aux->proximo;        
            aux->proximo = novo;
      }
    }
    else
        printf("Erro ao alocar memoria");
}

// Remove elementos do inicio da Lista
void removerDoInicio(No **lista) {
    if (*lista) {
        No *aux = *lista;
        *lista = aux->proximo;
        free(aux);        
    }
    else 
        printf("A lista ja esta vazia\n");
    
}

// Remove elementos do meio da Lista
void removerDoMeio(No **lista, int valor) { 
    if (*lista) {
        No *aux = *lista;
        No* anterior = NULL;
        while(aux->dado != valor && aux) {
                anterior = aux;
                aux = aux->proximo; 
        }   
        if(aux) {
            if(anterior) 
                anterior->proximo = aux->proximo;
            else
                *lista = aux->proximo;
        }
        else
            printf("Elemento %d nao encontrado", valor);
    }
    else 
        printf("A lista ja esta vazia\n");

}

// Remove elementos do final da Lista
void removerDoFinal(No **lista) { 
    if (*lista) {
        No *aux = *lista;
        No* anterior = NULL;
        while(aux->proximo) {
            anterior = aux;
            aux = aux->proximo;
        }     
        if (anterior)
            anterior->proximo = NULL;
        else
            *lista = NULL;
            
        free(aux);
    }
    else 
        printf("A lista ja esta vazia\n");

}


// Imprime todos elementos da Lista
void imprimindoLista(No *lista) {
    if(!listavazia(&lista)) {
        printf("Lista: \n");
        while (lista) {
            printf("%d  ", lista->dado);
            lista = lista->proximo;
        }
        printf("\n\n");
    }
    else 
        printf("A lista esta vazia\n");
}




int main() {
    No *lista = NULL;
    int opcao, valor, refAnterior;
    do
	{
		printf ("========== OPERACOES CONVENCIONAIS SOBRE A LISTA ==============\n");
		printf ("Inserir: 1-Inicio  2-Meio  3-Fim  4-Ordenado\n");
		printf ("Remover: 5-Inicio  6-Meio  7-Fim\n");
		printf ("Exibir.: 8-Lista\n");
		printf ("\nInforme a sua opcao (0-Sair): ");
        scanf  ("%d", &opcao);
        
        switch (opcao) {
        	case  1:
                printf("Digite um valor para der add no INICIO da Lista: ");
                scanf("%d", &valor);
                inserirNoInicio(&lista, valor);
                break;
        	
            case  2:
                printf("Digite um valor para der add no MEIO da Lista: ");
                scanf("%d", &valor);
                printf("Digite um valor de referencia(depois de): "); 
                scanf("%d", &refAnterior);
                inserirNoMeio(&lista, refAnterior, valor);
                break;
        	
            case  3:
                printf("Digite um valor para der add no FINAL da Lista: ");
                scanf("%d", &valor);
                inserirNoFinal(&lista, valor);
				break;
			
            case  4:
                printf("Digite um valor para der add na Lista ordenadamente: ");
                scanf("%d", &valor);                
                inserirOrdenado(&lista, valor);
				break;
			
            case  5:
                removerDoInicio(&lista);
				break;
			
            case  6:
                printf("Digite um valor a ser removido: "); 
                scanf("%d", &refAnterior);
                removerDoMeio(&lista, refAnterior);
				break;
			
            case  7:
                removerDoFinal(&lista);
				break;
			
            case  8:
                imprimindoLista(lista);
				break;
            
            default:
                if(opcao != 0)
                    printf("Opcao Invalida");
		}
		printf ("\n");
	} while ( opcao != 0 );
    
    return 0;
}