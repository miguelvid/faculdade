#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Define o tamanho máximo da pilha

// Definição da estrutura Stack para representar a pilha
typedef struct {
    int data[MAX_SIZE]; // Array para armazenar os elementos da pilha
    int top;            // Índice que aponta para o topo da pilha
} Stack;

// Função para inicializar a pilha
void initialize(Stack *stack) {
    stack->top = -1; // Define o topo como -1 para indicar que a pilha está vazia
}

// Função para verificar se a pilha está vazia
int is_empty(Stack *stack) {
    return (stack->top == -1); // Retorna verdadeiro se o topo for -1
}

// Função para verificar se a pilha está cheia
int is_full(Stack *stack) {
    return (stack->top == MAX_SIZE - 1); // Retorna verdadeiro se o topo for MAX_SIZE - 1
}

// Função para empilhar um elemento na pilha
void push(Stack *stack, int value) {
    if (is_full(stack)) { // Verifica se a pilha está cheia
        printf("Stack overflow!\n"); // Se estiver cheia, exibe uma mensagem de erro
        return; // Retorna sem fazer nada
    }
    stack->data[++stack->top] = value; // Incrementa o topo e adiciona o valor na posição correspondente
}

// Função para desempilhar um elemento da pilha
int pop(Stack *stack) {
    if (is_empty(stack)) { // Verifica se a pilha está vazia
        printf("Stack underflow!\n"); // Se estiver vazia, exibe uma mensagem de erro
        return -1; // Retorna um valor especial para indicar um erro
    }
    return stack->data[stack->top--]; // Retorna o valor do topo e decrementa o topo
}

// Função para obter o elemento no topo da pilha sem removê-lo
int peek(Stack *stack) {
    if (is_empty(stack)) { // Verifica se a pilha está vazia
        printf("Stack is empty!\n"); // Se estiver vazia, exibe uma mensagem de erro
        return -1; // Retorna um valor especial para indicar um erro
    }
    return stack->data[stack->top]; // Retorna o valor do topo sem modificar a pilha
}

// Função principal
int main() {
    Stack stack; // Declara uma variável do tipo Stack para representar a pilha
    initialize(&stack); // Inicializa a pilha

    // Empilha alguns elementos
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Exibe o elemento no topo da pilha
    printf("Top element: %d\n", peek(&stack));

    // Desempilha e exibe os elementos
    printf("Popping elements: ");
    while (!is_empty(&stack)) {
        printf("%d ", pop(&stack));
    }
    printf("\n");

    return 0;
}
