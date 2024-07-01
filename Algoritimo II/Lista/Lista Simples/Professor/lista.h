typedef struct {
    int elemento;
    struct nolista *proximo;
} nolista, lista;

void inicializalista (lista *l) {
    l->proximo = NULL;
}

int listavazia (lista *l) {
    if (l->proximo == NULL)
        return 1;
    return 0;
}

int listacheia (lista *l) {
    return 0;
}

void insereiniciolista (lista *l, int elemento) {
    nolista *no = (nolista *) malloc (sizeof(nolista));
    no->elemento = elemento;
    no->proximo = l->proximo;
    l->proximo = no;
}

void removeiniciolista (lista *l) {
}

int iniciolista (lista *l) {
}

void inserefimlista (lista *l, int elemento) {
    nolista *no = (nolista *) malloc (sizeof(nolista));
    no->elemento = elemento;
    no->proximo= NULL;
    if (listavazia(l))
    {
        l->proximo = no;
    }else
    {
        do {
            l = l->proximo; 
        }while (!listavazia(l));
        l->proximo = no;
    }
    
    
}

void removefimlista (lista *l) {
}

int fimlista (lista *l) {
}

int tamanholista (lista *l) {
}

nolista *alocanolista (int *proximo, int elemento) {
}

void inserelista (lista *l, int elemento, int no) {
}

void liberalista (lista *l) {
}

void removenolista (lista *l, int no) {
}

void removelista (lista *l, int elemento) {
}

int elementolista (lista *l, int no) {
}

int qtdelementolista (lista *l, int elemento) {
}

int noelementolista (lista *l, int elemento) {
}

void exibeestruturalista (lista *l) {
    int nr_no = 1;
        printf ("&lista: %6x     &1oNo': %x\n", l, l->proximo);
        if (!listavazia (l)) {
            printf ("\nNo' &No'       &Proximo    Elemento");
            printf ("\n--- ---------  ----------  --------\n");
            do {
                l = l->proximo;
                printf ("%2d %6x %6x %7d\n", nr_no, &(*l),
                    l->proximo, l->elemento);
                nr_no++;
            } while (!listavazia (l));
        }
}


void exibeelementolista (lista *l, int elemento) {
}

void invertelista (lista *l) {
}

