#include <stdio.h>
#include <stdlib.h>

#define TAM_PILHA 5
#define ELEMENTO_VAZIO -1 // Valor especial para indicar posição vazia na pilha

// Definição do tipo de dado pilha
typedef struct {
    int topo; // Variável para acompanhar o topo da pilha
    int memoria[TAM_PILHA]; // Memória da pilha para armazenar elementos
} pilha;

// Função para inicializar a pilha
void inicializapilha(pilha *p) {
    int x;
    // Define todos os elementos da memória da pilha como vazios (-1) e inicializa o topo como 0
    for (x = 0; x < TAM_PILHA; x++) 
        p->memoria[x] = ELEMENTO_VAZIO;
    p->topo = 0;
}

// Função para verificar se a pilha está cheia
int pilhacheia(pilha *p) {
    int x;
    // Verifica se todos os elementos da memória da pilha estão preenchidos
    for (x = 0; x < TAM_PILHA; x++)
        if (p->memoria[x] == ELEMENTO_VAZIO)
            return 0; // A pilha não está cheia
    return 1; // A pilha está cheia
}

// Função para verificar se a pilha está vazia
int pilhavazia(pilha *p) {
    // Verifica se o primeiro elemento da memória da pilha está vazio
    if (p->memoria[0] == ELEMENTO_VAZIO)
        return 1; // A pilha está vazia
    return 0; // A pilha não está vazia
}

// Função para empilhar um elemento na pilha
void empilha(pilha *p, int elemento) {
    int x = 0;
    // Verifica se a pilha não está cheia
    if (!pilhacheia(p)) {
        // Procura a primeira posição vazia na memória da pilha
        do {
            if (p->memoria[x] == ELEMENTO_VAZIO) {
                p->memoria[x] = elemento; // Insere o elemento na posição vazia
                break;
            }
            x++;
        } while (x < TAM_PILHA);
    }
}

// Função para desempilhar um elemento da pilha
void desempilha(pilha *p) {
    int x = TAM_PILHA - 1;
    // Verifica se a pilha não está vazia
    if (!pilhavazia(p)) {
        // Procura o último elemento preenchido na memória da pilha
        do {
            if (p->memoria[x] != ELEMENTO_VAZIO) {
                p->memoria[x] = ELEMENTO_VAZIO; // Remove o elemento marcando a posição como vazia
                break;
            }
            x--;
        } while (x >= 0);
    }
}

// Função para acessar o elemento no topo da pilha
int topopilha(pilha *p) {
    int x, elemento_topo = ELEMENTO_VAZIO;
    // Verifica se a pilha não está vazia
    if (!pilhavazia(p)) {
        // Procura o primeiro elemento preenchido na memória da pilha (do topo para a base)
        for (x = 0; x < TAM_PILHA; x++)
            if (p->memoria[x] != ELEMENTO_VAZIO)
                elemento_topo = p->memoria[x]; // Retorna o elemento do topo
    }
    return elemento_topo; // Retorna o valor especial se a pilha estiver vazia ou o elemento do topo
}

// Função para retornar o tamanho da pilha
int tamanhopilha(pilha *p) {
    int x, y;
    // Conta o número de elementos preenchidos na memória da pilha
    for (x = y = 0; x < TAM_PILHA; x++)
        if (p->memoria[x] != ELEMENTO_VAZIO)
            y++;
    return y; // Retorna o tamanho da pilha
}

// Função para replicar o conteúdo de uma pilha em outra
void replicapilha(pilha *p, pilha *d) {
    int i;
    inicializapilha(d); // Inicializa a pilha de destino

    // Copia os elementos da pilha original para a pilha de destino
    for (i = 0; i < TAM_PILHA; i++) {
        d->memoria[i] = p->memoria[i];
    }
}

// Função para replicar o conteúdo de uma pilha em outra usando uma pilha auxiliar
void replicapilhaauxiliar(pilha *a, pilha *b) {
    inicializapilha(b); // Inicializa a pilha de destino
    int i;
    
    pilha aux;
    inicializapilha(&aux); // Inicializa uma pilha auxiliar

    // Copia os elementos da pilha original para a pilha auxiliar
    for (i = 0; i < TAM_PILHA; i++) {
        empilha(&aux, topopilha(a)); // Empilha o elemento do topo na pilha auxiliar
        desempilha(a); // Desempilha o elemento da pilha original
    }

    // Copia os elementos da pilha auxiliar para a pilha de destino e para a pilha original
    for (i = 0; i < TAM_PILHA; i++) {
        empilha(a, topopilha(&aux)); // Empilha o elemento da pilha auxiliar na pilha original
        empilha(b, topopilha(&aux)); // Empilha o elemento da pilha auxiliar na pilha de destino
        desempilha(&aux); // Desempilha o elemento da pilha auxiliar
    }
}

// Função principal
int main() {
    pilha p, d; // Declaração das pilhas para manipulação
    int opcao, elemento; // Variáveis para armazenar opções e elementos

    // Inicializa as pilhas
    inicializapilha(&p);
    inicializapilha(&d);

    // Loop principal do programa
    while (1) {
        // Menu de opções
        printf("PILHA: 1-Empilhar 2-Desempilhar 3-Topo 4-Tamanho 5-Replicar 6-Replicar Auxiliar 0-Sair\n");
        printf("Informe a opcao: ");
        scanf("%d", &opcao);
        
        // Verifica a opção selecionada pelo usuário
        if (opcao == 0)
            break;
        
        switch (opcao) {
            case 1: // Empilhar um elemento
                if (pilhacheia(&p))
                    printf("A pilha esta cheia para empilhar...\n");
                else {
                    printf("Qual elemento empilhar: ");
                    scanf("%d", &elemento);
                    empilha(&p, elemento); // Chama a função para empilhar o elemento
                }
                break;
            case 2: // Desempilhar um elemento
                if (pilhavazia(&p))
                    printf("A pilha esta vazia para desempilhar...\n");
                else {
                    printf("O elemento %d sera' desempilhado...\n", topopilha(&p));
                    desempilha(&p); // Chama a função para desempilhar um elemento
                }
                break;
            case 3: // Acessar o elemento do topo da pilha
                if (!pilhavazia(&p))
                    printf("Elemento do Topo da Pilha: %d\n", topopilha(&p));
                else
                    printf("Pilha vazia ...\n");
                break;
            case 4: // Verificar o tamanho da pilha
                printf("Tamanho da Pilha: %d\n", tamanhopilha(&p));
                break;
            case 5: // Replicar o conteúdo da pilha
                replicapilha(&p, &d); // Chama a função para replicar a pilha
                break;
            case 6: // Replicar o conteúdo da pilha usando uma pilha auxiliar
                replicapilhaauxiliar(&p, &d); // Chama a função para replicar a pilha usando uma pilha auxiliar
                break;
            default: // Opção inválida
                printf("Opcao invalida!\n");
                break;
        }
        printf("\n");
    }

    printf("Tecle <enter> para continuar...");
    getchar();

    return 0;
}
