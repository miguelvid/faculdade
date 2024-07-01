#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *proximo;
}No;

typedef struct Fila {
    No *incico;
    No *fim;
}Fila;

void enfileiramento(Fila *f, int dado) {
    No *novo = (No*)malloc(sizeof(No*));
    if (novo = NULL) {
        printf("ERRO de alocacao");
        return;
    }
    novo->dado = dado;
    novo->proximo= NULL;
    if (f->incico == NULL) 
        f->incico = novo;
    else
        f->fim->proximo = novo;    
    f->fim = novo;
}

int desinfileiramento(Fila *f) {
    No *novo = f->incico;
    int aux;
    if (novo != NULL) {
        f->incico = novo->proximo;
        novo->proximo = NULL;
        aux = novo->dado;
        free(novo);
        return aux;
        if (f->incico == NULL)
            f->fim = NULL;
        return aux;
    }
    printf("Fila Vazia");
    return -1;
}

void emprimirFila(Fila *f) {
    No *novo = f->incico;
    if (novo != NULL) {
        while (novo != NULL) {
            printf("%d", novo->dado);
            novo = novo->proximo;
        }    
    }
    printf("Fila Vazia");
    return;
}

int main(void) {
    No *novo = (No*)malloc(sizeof(No*));

    for (int i = 0; i < 100; i++) {
        enfileiramento(&f, i);
    }
    
    emprimirFila(&f);

    for (int i = 0; i < 101; i++) {
        desinfileiramento(&f);
    }
    
    return 0;
}