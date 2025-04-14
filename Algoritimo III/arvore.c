#include <stdio.h>
#include <stdlib.h>

#define ERRO_ARVORE -99999

typedef struct noarvore {
    int chave;
    struct noarvore *esquerdo;
    struct noarvore *direito;
} noarvore, arvore;


void inicializa_arvore (arvore *a) {
    /* Apontará para o nó Raiz quando existir */
    a->esquerdo = NULL;
    /* Poderá ser utilizado para apontar para o último nó inserido na árvore [opcional] */
    a->direito = NULL;
    /* Poderá ser utilizado para conter: quantidade de nós na árvore, altura, total de níveis,
    especificar a ordem da árvore, ou qualquer outro valor necessário ao propósito do algoritmo */
    a->chave = 0;
}

int isvazia_arvore (arvore *a) {
    if (a->esquerdo == NULL) return 1;
    return 0;
}
noarvore* criarNo(int chave) {
    noarvore* novo = (noarvore*)malloc(sizeof(noarvore));
    if (novo != NULL) {
        novo->chave = chave;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        return novo;
    }
    return NULL;  // Changed from ERRO_ARVORE to NULL for consistency
}

noarvore* inserir(noarvore *raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->chave) {
        raiz->esquerdo = inserir(raiz->esquerdo, valor);
    }
    else if (valor > raiz->chave) {  // Changed to else if to avoid duplicate insertions
        raiz->direito = inserir(raiz->direito, valor);
    }
    return raiz;
}

noarvore* remover(noarvore *raiz, int valor) {
    noarvore *atual = raiz;
    noarvore *pai = NULL;


    while (atual != NULL && atual->chave != valor) {
        pai = atual;
        if (valor < atual->chave) {
            atual = atual->esquerdo;
        } else {
            atual = atual->direito;
        }
    }

    if (atual == NULL) {
        printf("Valor %d nao encontrado\n", valor);
        return raiz;
    }

    if (atual->esquerdo != NULL && atual->direito != NULL) {
        printf("Erro remocao: grau = 2\n");
        return raiz;
    }

    noarvore *aux = (atual->esquerdo != NULL) ? atual->esquerdo : atual->direito;

    if (pai == NULL) {
        free(atual);
        return aux;
    }

    if (atual->chave < pai->chave) {
        pai->esquerdo = aux;
    } else {
        pai->direito = aux;
    }

    printf("No com chave: %d removido\n", atual->chave);
    free(atual);
    return raiz;
}

noarvore* elemento(noarvore* raiz, int valor) {
    // Caso base: árvore vazia ou elemento encontrado
    if (raiz == NULL) {
        return NULL;
    }
    
    // Imprime o nó atual em todos os casos
    printf("&No---ESQUERDO---DIREITO---ELEMENTO---GRAU---PROFUNDIDADE\n");
    printf("&%x---&%x     ---&%x    ---%d      ---%d  ---%d\n", 
           raiz, raiz->esquerdo, raiz->direito, raiz->chave, 0, 0);


    if (raiz->chave == valor) {
        return raiz;
    }
    else if (valor < raiz->chave) {
        return elemento(raiz->esquerdo, valor);
    }
    else {
        return elemento(raiz->direito, valor);
    }
}

void menu() {
    int opcao, x;
    noarvore* a;  
    inicializa_arvore(&a);
    
    do {
        printf("\n1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Elemento\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &x);
                a = inserir(a, x);
                break;
            case 2:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &x);
                a = remover(a, x);
                break;
            case 3:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &x);
                elemento(a, x);
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

int main() {
    menu();
    return 0;
}