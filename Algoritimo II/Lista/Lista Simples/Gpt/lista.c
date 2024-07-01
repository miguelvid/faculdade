#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *proximo;
} No;

No* iniciaNo(int dado) {
    No *novo = malloc(sizeof(No));
    if (novo) {
        novo->dado = dado;
        novo->proximo = NULL;
    }
    return novo;
}

int listavazia(No *lista) {
    return lista == NULL;
}

int listacheia(No *lista) {
    return 0;
}

void inserirNoInicio(No **lista, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo) {
        novo->dado = valor;
        novo->proximo = *lista;
        *lista = novo;
    } else {
        printf("Erro ao alocar memoria\n");
    }
}

void inserirNoFinal(No **lista, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo) {
        novo->dado = valor;
        novo->proximo = NULL;
        if (*lista == NULL) {
            *lista = novo;
        } else {
            No *aux = *lista;
            while (aux->proximo) {
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
    } else {
        printf("Erro ao alocar memoria\n");
    }
}

void inserirNoMeio(No **lista, int anterior, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo) {
        novo->dado = valor;
        if (*lista == NULL) {
            novo->proximo = NULL;
            *lista = novo;
        } else {
            No *aux = *lista;
            while (aux->dado != anterior && aux->proximo) {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    } else {
        printf("Erro ao alocar memoria\n");
    }
}

void imprimindoLista(No *lista) {
    printf("Lista: ");
    while (lista) {
        printf("%d ", lista->dado);
        lista = lista->proximo;
    }
    printf("\n");
}

int main() {
    No *lista = NULL;
    int opcao, valor, refAnterior;
    do {
        printf("========== OPERACOES CONVENCIONAIS SOBRE A LISTA ==============\n");
        printf("Inserir: 1-Inicio  2-Meio  3-Fim\n");
        printf("Remover:\n");
        printf("Exibir.: 7-Lista\n");
        printf("\nInforme a sua opcao (0-Sair): ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um valor para adicionar no INICIO da Lista: ");
                scanf("%d", &valor);
                inserirNoInicio(&lista, valor);
                break;

            case 2:
                printf("Digite um valor para adicionar no MEIO da Lista: ");
                scanf("%d", &valor);
                printf("Digite um valor de referencia: ");
                scanf("%d", &refAnterior);
                inserirNoMeio(&lista, refAnterior, valor);
                break;

            case 3:
                printf("Digite um valor para adicionar no FINAL da Lista: ");
                scanf("%d", &valor);
                inserirNoFinal(&lista, valor);
                break;

            case 4:
                break;

            case 5:
                break;

            case 6:
                break;

            case 7:
                imprimindoLista(lista);
                break;

            default:
                if (opcao != 0)
                    printf("Opcao Invalida");
        }
        printf("\n");
    } while (opcao != 0);

    return 0;
}

