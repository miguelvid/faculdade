#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef struct Fila {
    int dado[N];
    int fim;
}Fila;

void iniciaFila(Fila *f) {
    for (int i = 0; i < N; i++)
        f->dado[N] = 0;
    f->fim = 0;
}

void efilera(Fila *f, int dado) {
    if (f->fim == N) {
        printf("\nFila cheia\n");
        return;
    }
    f->dado[f->fim] = dado;
    f->fim++; 
}

int desinfilera(Fila *f) {
    int dado;
    if(f->fim == 0) {
        printf("\nFila vazia\n");
        return -1;
    }
    //dado = f->dado[0];
    for (int i = 0; i < f->fim; i++) {
        f->dado[0] = f->dado[0+1];
        
    }
    f->fim--;
    //return dado;
}

void imprimeFila(Fila *f) {
    for (int i = 0; i < f->fim; i++) {
        printf("--%d", f->dado[i]);
    }
}

int main(void) {
    Fila f;
    iniciaFila(&f);

    efilera(&f, 1);
    efilera(&f, 2);
    efilera(&f, 3);
    efilera(&f, 4);

    imprimeFila(&f);

    desinfilera(&f);
    desinfilera(&f);
    desinfilera(&f);
    desinfilera(&f);
    desinfilera(&f);

}