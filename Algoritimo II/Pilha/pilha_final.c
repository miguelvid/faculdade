#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da pilha
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Estrutura da pilha
typedef struct Stack {
    Node* top;
} Stack;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para inicializar a pilha
void initializeStack(Stack* stack) {
    stack->top = NULL;
}

// Função para verificar se a pilha está vazia
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Função para empilhar (push)
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d empilhado na pilha.\n", data);
}

// Função para desempilhar (pop)
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Pilha está vazia. Não é possível desempilhar.\n");
        exit(1);
    }
    Node* temp = stack->top;
    int poppedData = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return poppedData;
}

// Função para ver o elemento do topo da pilha
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Pilha está vazia.\n");
        exit(1);
    }
    return stack->top->data;
}

int main() {
    Stack stack;
    initializeStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Elemento do topo é %d\n", peek(&stack));
    printf("%d desempilhado da pilha.\n", pop(&stack));
    printf("Elemento do topo é %d\n", peek(&stack));

    return 0;
}
