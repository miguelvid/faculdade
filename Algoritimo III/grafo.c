#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct No {
    int vertice;
    struct No* next;
} No;

typedef struct Grafo {
    int numVertices;
    No** adjLists;
    bool* visited;
} Grafo;

typedef struct Fila {
    int items[MAX_VERTICES];
    int primeiro;
    int ultimo;
} Fila;

Grafo* criarGrafo(int vertices);
void adicionaAresta(Grafo* grafo, int src, int dest);
void adicionaVertice(Grafo* grafo);
void removeVertice(Grafo* grafo, int vertice);
void removeAresta(Grafo* grafo, int src, int dest);
void freeGrafo(Grafo* grafo);
void printGrafo(Grafo* grafo);
void printMatrizAdjacencia(Grafo* grafo);
void DFSUtil(Grafo* grafo, int vertice);
void DFS(Grafo* grafo, int startvertice);
void BFS(Grafo* grafo, int startvertice);
Fila* criarFila();
bool isVazio(Fila* q);
void enqueue(Fila* q, int value);
int dequeue(Fila* q);
bool isConexo(Grafo* grafo);

Grafo* criarGrafo(int vertices) {
    Grafo* grafo = malloc(sizeof(Grafo));
    grafo->numVertices = vertices;
    grafo->adjLists = malloc(vertices * sizeof(No*));
    grafo->visited = malloc(vertices * sizeof(bool));
    for (int i = 0; i < vertices; i++) {
        grafo->adjLists[i] = NULL;
        grafo->visited[i] = false;
    }
    return grafo;
}

void adicionaAresta(Grafo* grafo, int src, int dest) {
    No* newNo = malloc(sizeof(No));
    newNo->vertice = dest;
    newNo->next = grafo->adjLists[src];
    grafo->adjLists[src] = newNo;

    newNo = malloc(sizeof(No));
    newNo->vertice = src;
    newNo->next = grafo->adjLists[dest];
    grafo->adjLists[dest] = newNo;
}

void freeGrafo(Grafo* grafo) {
    for (int i = 0; i < grafo->numVertices; i++) {
        No* temp = grafo->adjLists[i];
        while (temp) {
            No* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(grafo->adjLists);
    free(grafo->visited);
    free(grafo);
}

void printGrafo(Grafo* grafo) {
    printf("Visualizacao por Lista de Adjacencia:\n");
    for (int v = 0; v < grafo->numVertices; v++) {
        No* temp = grafo->adjLists[v];
        printf("Vertice %d: ", v);
        while (temp) {
            printf("%d -> ", temp->vertice);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void printMatrizAdjacencia(Grafo* grafo) {
    int matrix[MAX_VERTICES][MAX_VERTICES] = {0};
    for (int v = 0; v < grafo->numVertices; v++) {
        No* temp = grafo->adjLists[v];
        while (temp) {
            matrix[v][temp->vertice] = 1;
            temp = temp->next;
        }
    }
    printf("\nVisualizacao por Matriz de Adjacencia:\n");
    for (int i = 0; i < grafo->numVertices; i++) {
        for (int j = 0; j < grafo->numVertices; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void DFSUtil(Grafo* grafo, int vertice) {
    grafo->visited[vertice] = true;
    printf("%d ", vertice);
    No* temp = grafo->adjLists[vertice];
    while (temp) {
        int adjvertice = temp->vertice;
        if (!grafo->visited[adjvertice]) {
            DFSUtil(grafo, adjvertice);
        }
        temp = temp->next;
    }
}

void DFS(Grafo* grafo, int startvertice) {
    for (int i = 0; i < grafo->numVertices; i++) {
        grafo->visited[i] = false;
    }
    printf("Busca em Profundidade (DFS) a partir do vertice %d:\n", startvertice);
    DFSUtil(grafo, startvertice);
    printf("\n");
}

Fila* criarFila() {
    Fila* q = malloc(sizeof(Fila));
    q->primeiro = -1;
    q->ultimo = -1;
    return q;
}

bool isVazio(Fila* q) {
    return q->primeiro == -1;
}

void enqueue(Fila* q, int value) {
    if (q->ultimo == MAX_VERTICES - 1) {
        printf("Fila cheia\n");
        return;
    }
    if (q->primeiro == -1) {
        q->primeiro = 0;
    }
    q->ultimo++;
    q->items[q->ultimo] = value;
}

int dequeue(Fila* q) {
    if (isVazio(q)) {
        printf("Fila vazia\n");
        return -1;
    }
    int item = q->items[q->primeiro];
    q->primeiro++;
    if (q->primeiro > q->ultimo) {
        q->primeiro = q->ultimo = -1;
    }
    return item;
}

void BFS(Grafo* grafo, int startvertice) {
    for (int i = 0; i < grafo->numVertices; i++) {
        grafo->visited[i] = false;
    }
    Fila* q = criarFila();
    grafo->visited[startvertice] = true;
    enqueue(q, startvertice);
    printf("Busca em Largura (BFS) a partir do vertice %d:\n", startvertice);
    while (!isVazio(q)) {
        int currentvertice = dequeue(q);
        printf("%d ", currentvertice);
        No* temp = grafo->adjLists[currentvertice];
        while (temp) {
            int adjvertice = temp->vertice;
            if (!grafo->visited[adjvertice]) {
                grafo->visited[adjvertice] = true;
                enqueue(q, adjvertice);
            }
            temp = temp->next;
        }
    }
    printf("\n");
    free(q);
}

bool isConexo(Grafo* grafo) {
    if (grafo->numVertices == 0) return true;
    for (int i = 0; i < grafo->numVertices; i++) {
        grafo->visited[i] = false;
    }
    DFSUtil(grafo, 0);
    for (int i = 0; i < grafo->numVertices; i++) {
        if (!grafo->visited[i]) {
            return false;
        }
    }
    return true;
}

void adicionaVertice(Grafo* grafo) {
    grafo->numVertices++;
    grafo->adjLists = realloc(grafo->adjLists, grafo->numVertices * sizeof(No*));
    grafo->visited = realloc(grafo->visited, grafo->numVertices * sizeof(bool));
    grafo->adjLists[grafo->numVertices - 1] = NULL;
    grafo->visited[grafo->numVertices - 1] = false;
}

void removeAresta(Grafo* grafo, int src, int dest) {
    if (src < 0 || src >= grafo->numVertices || dest < 0 || dest >= grafo->numVertices) {
        printf("Vertice invalido!\n");
        return;
    }

    No* temp = grafo->adjLists[src];
    No* prev = NULL;
    while (temp) {
        if (temp->vertice == dest) {
            if (prev) {
                prev->next = temp->next;
            } else {
                grafo->adjLists[src] = temp->next;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    temp = grafo->adjLists[dest];
    prev = NULL;
    while (temp) {
        if (temp->vertice == src) {
            if (prev) {
                prev->next = temp->next;
            } else {
                grafo->adjLists[dest] = temp->next;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}

void removeVertice(Grafo* grafo, int vertice) {
    if (vertice < 0 || vertice >= grafo->numVertices) {
        printf("Vertice invalido!\n");
        return;
    }

    for (int i = 0; i < grafo->numVertices; i++) {
        if (i != vertice) {
            removeAresta(grafo, i, vertice);
        }
    }

    No* temp = grafo->adjLists[vertice];
    while (temp) {
        No* toFree = temp;
        temp = temp->next;
        free(toFree);
    }

    for (int i = vertice; i < grafo->numVertices - 1; i++) {
        grafo->adjLists[i] = grafo->adjLists[i + 1];
        grafo->visited[i] = grafo->visited[i + 1];
    }

    grafo->numVertices--;
    grafo->adjLists = realloc(grafo->adjLists, grafo->numVertices * sizeof(No*));
    grafo->visited = realloc(grafo->visited, grafo->numVertices * sizeof(bool));
}

int main() {
    int opcao, src, dest, startvertice;
    Grafo* grafo = criarGrafo(0); 

    do {
        
        printf("\nMenu:\n");
        printf("1. Adicionar Vertice\n");
        printf("2. Adicionar Aresta\n");
        printf("3. Remover Vertice\n");
        printf("4. Remover Aresta\n");
        printf("5. Visualizar Grafo (Lista de Adjacencia)\n");
        printf("6. Visualizar Grafo (Matriz de Adjacencia)\n");
        printf("7. Busca em Profundidade (DFS)\n");
        printf("8. Busca em Largura (BFS)\n");
        printf("9. Verificar se o Grafo e Conexo\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionaVertice(grafo);
                printf("Vertice %d adicionado.\n", grafo->numVertices - 1);
                break;
            case 2:
                printf("Digite os vertices da aresta (src dest): ");
                scanf("%d %d", &src, &dest);
                if (src >= 0 && src < grafo->numVertices && dest >= 0 && dest < grafo->numVertices) {
                    adicionaAresta(grafo, src, dest);
                    printf("Aresta adicionada entre %d e %d.\n", src, dest);
                } else {
                    printf("Vertices invalidos!\n");
                }
                break;
            case 3:
                printf("Digite o vertice a ser removido: ");
                scanf("%d", &src);
                if (src >= 0 && src < grafo->numVertices) {
                    removeVertice(grafo, src);
                    printf("Vertice %d removido.\n", src);
                } else {
                    printf("Vertice invalido!\n");
                }
                break;
            case 4:
                printf("Digite os vertices da aresta a ser removida (src dest): ");
                scanf("%d %d", &src, &dest);
                if (src >= 0 && src < grafo->numVertices && dest >= 0 && dest < grafo->numVertices) {
                    removeAresta(grafo, src, dest);
                    printf("Aresta removida entre %d e %d.\n", src, dest);
                } else {
                    printf("Vertices invalidos!\n");
                }
                break;
            case 5:
                printGrafo(grafo);
                break;
            case 6:
                printMatrizAdjacencia(grafo);
                break;
            case 7:
                printf("Digite o vertice inicial para DFS: ");
                scanf("%d", &startvertice);
                if (startvertice >= 0 && startvertice < grafo->numVertices) {
                    DFS(grafo, startvertice);
                } else {
                    printf("Vertice invalido!\n");
                }
                break;
            case 8:
                printf("Digite o vertice inicial para BFS: ");
                scanf("%d", &startvertice);
                if (startvertice >= 0 && startvertice < grafo->numVertices) {
                    BFS(grafo, startvertice);
                } else {
                    printf("Vertice invalido!\n");
                }
                break;
            case 9:
                printf("O grafo e conexo? %s\n", isConexo(grafo) ? "Sim" : "Nao");
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    freeGrafo(grafo);
    return 0;
}