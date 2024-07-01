#include <stdio.h>
#include <stdlib.h>


typedef struct No
{
    int dado;
    struct No *proximo;
}No;


typedef struct Pilha {
    No *topo;
}Pilha;

void iniciaPilha(Pilha *p) {
    p->topo = NULL;
}

void empilha(Pilha *p, int dado) {
    No* novo = (No*)malloc(sizeof(No*));
    if (novo == NULL)
    {
        printf("\nERRO\n");
        return;
    }
    novo->dado = dado;
    novo->proximo = p->topo;
    p->topo = novo;  
}

int desimpilhar(Pilha *p) {
    No *novo = p->topo;
    int dado;
    if (novo == NULL)
    {
        printf("\nPilha vazia\n");
        return -1;
    }
    p->topo = novo->proximo;
    novo->proximo = NULL;
    dado = novo->dado;
    free(novo);
    return dado;
}

void printPilha(Pilha *p) {
    No *novo;
    if (novo == NULL) {
        printf("Pilha vazia\n");
        return;
    } 
    while (novo != NULL) {
        printf("%d  ", novo->dado);
        novo = novo->proximo;
    } 
}

int main() {
    Pilha p1;
    iniciaPilha(&p1);

    empilha(&p1, 1);
    empilha(&p1, 2);
    empilha(&p1, 3);
    empilha(&p1, 4);
    empilha(&p1, 5);
     printPilha(&p1);

    desimpilhar(&p1);
     printPilha(&p1);

    return 0;
}