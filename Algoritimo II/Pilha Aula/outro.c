#include <stdio.h>
#include <stdlib.h>

#define TAM_PILHA 5

// Definição do tipo de dado pilha
typedef struct {
    int topo;
    int memoria[TAM_PILHA];
} pilha;

// Função para inicializar a pilha
void inicializapilha(pilha *p) {
    p->topo = 0; // Inicializa o topo da pilha como 0
}

// Função para verificar se a pilha está cheia
int pilhacheia(pilha *p) {
    if (p->topo != TAM_PILHA) // Se o topo não atingiu o tamanho máximo da pilha
        return 0; // A pilha não está cheia
    return 1; // Caso contrário, a pilha está cheia
}

// Função para verificar se a pilha está vazia
int pilhavazia(pilha *p) {
    if (p->topo != 0) // Se o topo não está na posição 0
        return 0; // A pilha não está vazia
    return 1; // Caso contrário, a pilha está vazia
}

// Função para empilhar um elemento na pilha
void empilha(pilha *p, int elemento) {
    if (!pilhacheia(p)) { // Se a pilha não estiver cheia
        p->memoria[p->topo] = elemento; // Insere o elemento na posição do topo
        p->topo++; // Incrementa o topo
    }
}

// Função para desempilhar um elemento da pilha
void desempilha(pilha *p) {
    if (!pilhavazia(p)) // Se a pilha não estiver vazia
        p->topo--; // Decrementa o topo para remover o elemento
}

// Função para acessar o elemento no topo da pilha
int topopilha(pilha *p) {
    if (!pilhavazia(p)) // Se a pilha não estiver vazia
        return p->memoria[p->topo - 1]; // Retorna o elemento no topo
    return -1; // Se a pilha estiver vazia, retorna -1
}

// Função para retornar o tamanho da pilha
int tamanhopilha(pilha *p) {
    return p->topo; // Retorna o valor do topo, que indica o tamanho da pilha
}

// Função para replicar o conteúdo de uma pilha em outra
void replicapilha(pilha *p, pilha *d) {
    int i;
    inicializapilha(d); // Inicializa a pilha de destino

    // Copia os elementos da pilha original para a pilha de destino
    for (i = 0; i < p->topo; i++) {
        d->memoria[i] = p->memoria[i];
    }
    d->topo = p->topo; // Atualiza o topo da pilha de destino
}

// Função para replicar o conteúdo de uma pilha em outra usando uma pilha auxiliar
void replicapilhaauxiliar(pilha *a, pilha *b) {
    inicializapilha(b); // Inicializa a pilha de destino
    int i;
    
    pilha aux;
    inicializapilha(&aux); // Inicializa uma pilha auxiliar

    // Copia os elementos da pilha original para a pilha auxiliar
    for (i = 0; i < tamanhopilha(a); i++) {
        empilha(&aux, topopilha(a));
        desempilha(a);
    }

    // Copia os elementos da pilha auxiliar para a pilha de destino
    for (i = 0; i < tamanhopilha(&aux); i++) {
        empilha(a, topopilha(&aux));
        empilha(b, topopilha(&aux));
        desempilha(&aux);
    }
}

int main() {
    pilha p, d;
    int opcao, elemento;

    inicializapilha(&p);
    inicializapilha(&d);

    while (1) {
        printf("PILHA: 1-Empilhar 2-Desempilhar 3-Topo 4-Tamanho 5-Replicar 6-Replicar Auxiliar 0-Sair\n");
        printf("Informe a opcao: ");
        scanf("%d", &opcao);
        
        if (opcao == 0)
            break;
        
        switch (opcao) {
            case 1:
                if (pilhacheia(&p))
                    printf("A pilha esta cheia para empilhar...\n");
                else {
                    printf("Qual elemento empilhar: ");
                    scanf("%d", &elemento);
                    empilha(&p, elemento);
                }
                break;
            case 2:
                if (pilhavazia(&p))
                    printf("A pilha esta vazia para desempilhar...\n");
                else {
                    printf("O elemento %d sera' desempilhado...\n", topopilha(&p));
                    desempilha(&p);
                }
                break;
            case 3:
                if (!pilhavazia(&p))
                    printf("Elemento do Topo da Pilha: %d\n", topopilha(&p));
                else
                    printf("Pilha vazia ...\n");
                break;
            case 4:
                printf("Tamanho da Pilha: %d\n", tamanhopilha(&p));
                break;
            case 5:
                replicapilha(&p, &d);
                break;
            case 6:
                replicapilhaauxiliar(&p, &d);
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
        printf("\n");
    }

    printf("Tecle <enter> para continuar...");
    getchar();

    return 0;
}
