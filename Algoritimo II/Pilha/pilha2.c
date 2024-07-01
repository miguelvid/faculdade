#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct no *proximo;
}No;

typedef struct Pilha {
    No *topo;
}Pilha;

void inicializaPilha(Pilha *p) {
    p->topo = NULL;
}

void empilha(Pilha *p, int dado) {
    No *novo = (Pilha*)malloc(sizeof(Pilha*));
    if (novo == NULL) {
        printf("ERRO");
        return;
    }
    novo->dado = dado;
    novo->proximo = p->topo;
    p->topo = novo;
}

int desempilha(Pilha *p) {
    No *novo = p->topo;
    int dado;
    if (novo == NULL) {
        printf("Pilha Vaizia");
        return;
    }
    p->topo = novo->proximo;
    novo->proximo = NULL;
    dado = novo->dado;
    return dado;
}