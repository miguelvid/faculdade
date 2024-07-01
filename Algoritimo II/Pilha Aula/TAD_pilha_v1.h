
void inicializapilha (pilha *p) {
    p->topo = 0;
}

int pilhacheia (pilha *p) {
    if (p->topo != TAM_PILHA) return (0);
    return (1);
}

int pilhavazia (pilha *p) {
    if (p->topo != 0) return (0);
    return (1);
}

void empilha (pilha *p, int elemento) {
    if (!pilhacheia(p)) {
        p->memoria[p->topo] = elemento;
        p->topo++;
    }
}

void desempilha (pilha *p) {
    if (!pilhavazia(p)) p->topo--;
}

int topopilha (pilha *p) {
    if (!pilhavazia(p)) return (p->memoria[p->topo-1]);
    return (-1);
}

int tamanhopilha (pilha *p) {
    return (p->topo);
}

void replicapilha (pilha *p, pilha *d) {
    int i;
    inicializapilha(d);

    for (i = 0; i < p->topo; i++) {
        d->memoria[i] = p->memoria[i];
    }
    d->topo = p->topo;
}

void replicapilhaauxiliar (pilha *a, pilha *b) {
    inicializapilha(b);
    int i;
    
    pilha aux;
    inicializapilha(&aux);

    for (i = 0; i <= tamanhopilha(a); i++){
        empilha(&aux, topopilha(a));
        desempilha(a);
    }
    for(i = 0; i <= tamanhopilha(&aux); i++){
        empilha(a, topopilha(&aux));
        empilha(b, topopilha(&aux));
        desempilha(&aux);
    }

}