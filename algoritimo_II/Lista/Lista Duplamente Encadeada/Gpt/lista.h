#include <stdio.h>
#include <stdlib.h>

typedef struct nolista {
    int elemento;
    struct nolista *proximo;
    struct nolista *anterior;
} nolista, lista;

void inicializalista (lista *l) {
    l->proximo = NULL;
    l->anterior = NULL;
}

int listavazia (lista *l) {
    return l->proximo == NULL;
}

int listacheia (lista *l) {
    return 0;
}

void insereiniciolista (lista *l, int elemento) {
    nolista *no = (nolista *) malloc (sizeof(nolista));
    no->elemento = elemento;
    no->proximo = l->proximo;
    no->anterior = l;
    if (l->proximo != NULL) {
        l->proximo->anterior = no;
    }
    l->proximo = no;
}

void removeiniciolista (lista *l) {
    if (!listavazia(l)) {
        nolista *no = l->proximo;
        l->proximo = no->proximo;
        if (no->proximo != NULL) {
            no->proximo->anterior = l;
        }
        free(no);
    }
}

int iniciolista (lista *l) {
    if (!listavazia(l)) {
        return l->proximo->elemento;
    }
    return -1;
}

void inserefimlista (lista *l, int elemento) {
    nolista *no = (nolista *) malloc (sizeof(nolista));
    no->elemento = elemento;
    no->proximo = NULL;
    if (listavazia(l)) {
        no->anterior = l;
        l->proximo = no;
    } else {
        nolista *temp = l;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = no;
        no->anterior = temp;
    }
}

void removefimlista (lista *l) {
    if (!listavazia(l)) {
        nolista *temp = l;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        if (temp->anterior != NULL) {
            temp->anterior->proximo = NULL;
        }
        free(temp);
    }
}

int fimlista (lista *l) {
    if (!listavazia(l)) {
        nolista *temp = l;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        return temp->elemento;
    }
    return -1;
}

int tamanholista (lista *l) {
    int tamanho = 0;
    nolista *temp = l->proximo;
    while (temp != NULL) {
        tamanho++;
        temp = temp->proximo;
    }
    return tamanho;
}

nolista *alocanolista (int *proximo, int elemento) {

}

void inserelista (lista *l, int elemento, int no) {

}

void liberalista (lista *l) {
    while (!listavazia(l)) {
        removeiniciolista(l);
    }
}

void removenolista (lista *l, int no) {
    nolista *temp = l->proximo;
    int contador = 1;

    while (temp != NULL && contador < no) {
        temp = temp->proximo;
        contador++;
    }

    if (temp != NULL && temp->proximo != NULL && temp->anterior != l) {
        temp->anterior->proximo = temp->proximo;
        temp->proximo->anterior = temp->anterior;

        free(temp);
    }

}

void removelista (lista *l, int elemento) {
    nolista *temp = l->proximo;
    while (temp != NULL && temp->elemento != elemento) {
        temp = temp->proximo;
    }
    if (temp != NULL) {
        if (temp->anterior != NULL) {
            temp->anterior->proximo = temp->proximo;
        }
        if (temp->proximo != NULL) {
            temp->proximo->anterior = temp->anterior;
        }
        free(temp);
    }
}

int elementolista (lista *l, int no) {

}

int qtdelementolista (lista *l, int elemento) {

}

int noelementolista (lista *l, int elemento) {

}

void exibeestruturalista (lista *l) {
    int nr_no = 1;
    printf ("&lista: %p     &1oNo': %p\n", (void*)l, (void*)l->proximo);
    if (!listavazia (l)) {
        printf ("\nNo' &No'       &Proximo    &Anterior   Elemento");
        printf ("\n--- ---------  ----------  ----------  --------\n");
        nolista *temp = l->proximo;
        while (temp != NULL) {
            printf ("%2d %10p %10p %10p %7d\n", nr_no, (void*)temp, (void*)temp->proximo, (void*)temp->anterior, temp->elemento);
            nr_no++;
            temp = temp->proximo;
        }
    }
}

void exibeelementolista (lista *l, int elemento) {

}

void invertelista (lista *l) {

}