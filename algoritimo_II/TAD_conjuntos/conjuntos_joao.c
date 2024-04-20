#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 50

typedef struct {
    int elements[MAX_SIZE];
    int size;
} conjunto;


void init_conjunto(conjunto *c) {
    c->size = 0;
}

bool add_elemento(conjunto *c, int elemento) {
    if (c->size >= MAX_SIZE) {
        return false;
    }
    else{
        c->elements[c->size++] = elemento;
    }
    
    return true;
} 

bool contains_elemento(conjunto *c, int elemento) {
    for (int i = 0; i < c->size; i++) {
        if (c->elements[i] == elemento) {
            return true;
        }
    }
    return false;
}

conjunto interseccao(conjunto *c1, conjunto *c2) {
    conjunto c3;
    init_conjunto(&c3);
    
    for (int i = 0; i < c1->size; i++) {
        if (contains_elemento(c2, c1->elements[i])) {
            add_elemento(&c3, c1->elements[i]);
        }
    }
    return c3;
}

void print_elementos(conjunto* conjunto){
    for (int i = 0; i < conjunto->size; i++){
        printf("%d ", conjunto->elements[i]);
    }
}

int main() {
    conjunto c1, c2, c3;
    init_conjunto(&c1);
    init_conjunto(&c2);

    add_elemento(&c1, 1);
    add_elemento(&c1, 2);
    add_elemento(&c2, 2);
    add_elemento(&c2, 3);

    c3 = interseccao(&c1, &c2);

    print_elementos(&c3);

    return 0;
}