#include <stdio.h>
#include <stdlib.h>

typedef struct  No {
    int dado;
    struct No *proximo;
}No;


typedef struct Lista {
    No *inicio;
    int tam;
}Lista;

void iniciaLista(Lista *lista) {
    lista->inicio = NULL;
    lista->tam = 0;
}

// Verifica se esta vazia
int listavazia (Lista *lista) {
    return (lista->inicio == NULL);
}


//-------------------------Funções de inserção-----------------------------
    // Inseri elementos no inicio da Lista
    void inserirNoInicio(Lista *lista, int valor) {
        No *novo = malloc(sizeof(No));
        if(novo){
            novo->dado = valor;
            novo->proximo = lista->inicio;
            lista->inicio = novo;
            lista->tam++;
        }
        else
            printf("\nErro ao alocar memoria\n");  
    }

    // Inseri elementos no meio da Lista
    void inserirNoMeio(Lista *lista, int referencia, int valor) {
        No *novo = malloc(sizeof(No));
        if(novo){
            novo->dado = valor;
            if(lista->inicio == NULL) {
                novo->proximo = NULL;
                lista->inicio = novo;
            }
            else {
                No *aux = lista->inicio;
                while (aux->dado != referencia && aux->proximo)
                    aux = aux->proximo;
                novo->proximo = aux->proximo;
                aux->proximo = novo;
            }
            lista->tam++; 
        }
        else
            printf("\nErro ao alocar memoria\n");  
    }

    // Inseri elementos no final da Lista
    void inserirNoFinal(Lista *lista, int valor) {
        No *novo = malloc(sizeof(No));
        if(novo){
            novo->dado = valor;
            novo->proximo = NULL;
            if(lista->inicio == NULL) {
                lista->inicio = novo;
            }
            else {
                No *aux = lista->inicio;
                while (aux->proximo)
                    aux = aux->proximo;
                aux->proximo = novo;
            }
            lista->tam++;
        }
        else
            printf("\nErro ao alocar memoria\n");  
    }

    // Inseri um elemento na lista em ordem numerica
    void inserirOrdenado(Lista *lista, int valor) {
        No *novo = malloc(sizeof(No));
        if(novo){
            novo->dado = valor;
            if(lista->inicio == NULL) {
                novo->proximo = NULL;
                lista->inicio = novo;
            }
            else if(novo->dado < lista->inicio->dado) {
                novo->proximo = lista->inicio;
                lista->inicio = novo;
            }
            else {
                No *aux = lista->inicio;
                while(aux->proximo && novo->dado > aux->proximo->dado)
                    aux = aux->proximo;
                novo->proximo = aux->proximo;        
                aux->proximo = novo;
        }
        ++lista->tam;
        }
        else
            printf("Erro ao alocar memoria");
    }
//-----------------------------FINAL--------------------------------------




//-------------------------Funções de remoção-----------------------------
    // Remove elementos do inicio da Lista
    void removerDoInicio(Lista *lista) {
        if (lista->inicio) {
            No *aux = lista->inicio;
            lista->inicio = aux->proximo;
            free(aux);
            lista->tam--;      
        }
        else 
            printf("\nA lista ja esta vazia\n");
        
    }

    // Remove elementos do meio da Lista
    void removerDoMeio(Lista *lista, int valor) { 
        if (lista->inicio) {
            No *aux = lista->inicio;
            No* anterior = NULL;
            while(aux && aux->dado != valor) {
                    anterior = aux;
                    aux = aux->proximo; 
            }   
            if(aux) {
                if(anterior) 
                    anterior->proximo = aux->proximo;
                else
                    lista->inicio = aux->proximo;
                lista->tam--;
                free(aux);
            }
            else
                printf("\nElemento %d nao encontrado\n", valor);
        }
        else 
            printf("\nA lista ja esta vazia\n");

    }

    // Remove elementos do final da Lista
    void removerDoFinal(Lista *lista) { 
        if (lista->inicio) {
            No *aux = lista->inicio;
            No* anterior = NULL;
            while(aux->proximo) {
                anterior = aux;
                aux = aux->proximo;
            }     
            if (anterior)
                anterior->proximo = NULL;
            else
                lista->inicio = NULL;
            lista->tam--;   
            free(aux);
        }
        else 
            printf("\nA lista ja esta vazia\n");

    }
//-----------------------------FINAL--------------------------------------



//-------------------------Funções especiais------------------------------
// Inverte conteudo da Lista
    void inverteLista (Lista *lista) {
        No *anterior = NULL;
        No *atual = lista->inicio;
        No *proximo = NULL;
        while(atual != NULL) {
            proximo = atual->proximo;
            atual->proximo = anterior;
            anterior = atual;
            atual = proximo;
        }
        lista->inicio = anterior;
    }

    void jutarListas(Lista *listaA, Lista *listaB) {

    }
//-----------------------------FINAL--------------------------------------


// Imprime todos elementos da Lista
void imprimindoLista(Lista lista) {
    No *no = lista.inicio;
printf("\nLista tamanho : %d", lista.tam);
    if(!listavazia(&lista)) {
        printf("\nLista: ");
        while (no) {
            printf("%d  ", no->dado);
            no = no->proximo;
        }
        printf("\n\n");
    }
    else 
        printf("A lista esta vazia\n");
}

// Retorna elemento que foi solicitado
No *buscar(Lista *lista, int valor) {
    No *novo = NULL;
    No *aux = lista->inicio;
    while(aux && aux->dado != valor) 
        aux = aux->proximo;
    if(aux)
        novo = aux;
    return novo;
}




int main() {
    Lista lista;
    int opcao, valor, refAnterior;
    iniciaLista(&lista);
    do
	{
		printf ("========== OPERACOES CONVENCIONAIS SOBRE A LISTA ==============\n");
		printf ("Inserir:   1-Inicio    2-Meio      3-Fim      4-Oredenado\n");
		printf ("Remover:   5-Inicio    6-Meio      7-Fim         --------\n");
        printf ("Especiais: 8-Inverte   9-AlocaNO   10-RemoveNO   --------\n");
		printf ("Exibir:    11-Busca    12-Lista    --------      --------\n");
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
                printf("Digite um valor para der add na Lista ORDENADAMENTE: ");
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
                inverteLista(&lista);
				break;
            
            case  9:
                //alocaNoLista();
				break;
            case  10:
                //removeNoLista();
				break;

             case  11:
             printf("Buscar valor...: "); 
                scanf("%d", &refAnterior);
                buscar(&lista, valor);
				break;

            case  12:
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