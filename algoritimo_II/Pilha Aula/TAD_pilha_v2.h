
void inicializapilha (pilha *p) {
int x;
for (x = 0; x < TAM_PILHA; x++) p->memoria[x] = -1;
}
int pilhacheia (pilha *p) {
int x;
for (x = 0; x < TAM_PILHA; x++)
if (p->memoria[x] == -1) return (0);
return (1);
}

int pilhavazia (pilha *p) {
if (p->memoria[0] == -1) return (1);
return (0);
}
void empilha (pilha *p, int elemento) {
int x = 0;
if (!pilhacheia(p)) {
do {
if (p->memoria[x] == -1) {
p->memoria[x] = elemento;
break;
}
x++;
} while (x < TAM_PILHA );
}
}
void desempilha (pilha *p) {
int x = TAM_PILHA - 1;
if (!pilhavazia (p)) {
do {
if (p->memoria[x] != -1) {
p->memoria[x] = -1;
break;
}
x--;
} while (x >= 0);
}
}
int topopilha (pilha *p) {
int x, elemento_topo = -1;
if (!pilhavazia(p)) {
for (x = 0; x < TAM_PILHA; x++)
if (p->memoria[x] != -1)
elemento_topo = p->memoria[x];

}
return (elemento_topo);
}

int tamanhopilha (pilha *p) {
int x, y;
for (x = y = 0; x < TAM_PILHA; x++)
if (p->memoria[x] != -1) y++;
return (y);
}

void replicapilha (pilha *p, pilha *d) {
    int i;
    inicializapilha(d);

    for (i = 0; i < tamanhopilha(p); i++) {
        d->memoria[i] = p->memoria[i];

    }
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