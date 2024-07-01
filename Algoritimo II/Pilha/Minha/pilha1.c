#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int dado;
    struct No *proximo;
}No;

typedef struct Pilha {
    No *topo;
}Pilha;

void iniciaPilha(Pilha *p) {
    p->topo = NULL;
}

void empilhar(Pilha *p, int dado) {
    No *ptr = (No*)malloc(sizeof(No));
    if (ptr == NULL) {
        printf("Erro de alocacao");
        return;
    }
    ptr->dado = dado;
    ptr->proximo = p->topo;
    p->topo = ptr;  
}

int desempilha(Pilha *p) {
    No *ptr = p->topo;
    int dado;
    if (ptr == NULL) {
        printf("Pilha vazia\n");
        return -1;
    }
    p->topo = ptr->proximo;
    ptr->proximo = NULL;
    dado = ptr->dado;
    free(ptr);
    return dado;
}

void imprimePilha(Pilha *p) {
    No *ptr = p->topo;
    if (ptr == NULL) {
        printf("Pilha vazia\n");
        return;
    } else {
        while (ptr != NULL) {
            printf("%d  ", ptr->dado);
            ptr = ptr->proximo;
        }
    } 
}

void liberaPilha(Pilha *p) {
    while (p->topo == NULL) {
        desempilha(p);
    }
}

int main() {
    Pilha p1;
    iniciaPilha(&p1);

    empilhar(&p1, 1);
    empilhar(&p1, 2);
    empilhar(&p1, 3);
    empilhar(&p1, 4);
    empilhar(&p1, 5);

     imprimePilha(&p1);

    desempilha(&p1);
     imprimePilha(&p1);
    desempilha(&p1);
    desempilha(&p1);
    desempilha(&p1);
    desempilha(&p1);


     imprimePilha(&p1);
    
    return 0;
}