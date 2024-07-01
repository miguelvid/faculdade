#include <stdio.h>

#define MAX_SIZE 50

// Definindo uma estrutura para um conjunto
typedef struct {
    int elementos[MAX_SIZE]; // Array para armazenar os elementos do conjunto
    int tamanho; // Tamanho do conjunto
} Conjunto;

// Função para inicializar um conjunto
void inicializarConjunto(Conjunto *conjunto) {
    conjunto->tamanho = 0; // Inicialmente, o tamanho do conjunto é zero
}

// Função para verificar se um elemento existe no conjunto
int contemElemento(const Conjunto *conjunto, int elemento) {
    for (int i = 0; i < conjunto->tamanho; i++) {
        if (conjunto->elementos[i] == elemento) {
            return 1; // Elemento encontrado
        }
    }
    return 0; // Elemento não encontrado
}

// Função para adicionar um elemento ao conjunto
void adicionarElemento(Conjunto *conjunto, int elemento) {
    // Verifica se o conjunto não está cheio e se o elemento ainda não existe no conjunto
    if (conjunto->tamanho < MAX_SIZE && !contemElemento(conjunto, elemento)) {
        conjunto->elementos[conjunto->tamanho++] = elemento; // Adiciona o elemento ao conjunto e incrementa o tamanho
    }
}

// Função para imprimir os elementos do conjunto
void imprimirConjunto(const Conjunto *conjunto) {
    printf("{ ");
    for (int i = 0; i < conjunto->tamanho; i++) {
        printf("%d ", conjunto->elementos[i]); // Imprime cada elemento do conjunto
    }
    printf("}\n");
}

// Função para encontrar a interseção de dois conjuntos
Conjunto intersecao(const Conjunto *conjunto1, const Conjunto *conjunto2) {
    Conjunto resultado; // Conjunto resultante
    inicializarConjunto(&resultado); // Inicializa o conjunto resultante

    // Itera sobre os elementos do conjunto1
    for (int i = 0; i < conjunto1->tamanho; i++) {
        // Se um elemento do conjunto1 também estiver presente no conjunto2, adiciona-o ao conjunto resultante
        if (contemElemento(conjunto2, conjunto1->elementos[i])) {
            adicionarElemento(&resultado, conjunto1->elementos[i]);
        }
    }

    return resultado; // Retorna o conjunto resultante
}

int main() {
    Conjunto c1, c2, c3; // Declara três conjuntos
    int elemento;

    // Inicializa todos os conjuntos
    inicializarConjunto(&c1);
    inicializarConjunto(&c2);
    inicializarConjunto(&c3);

    // Insere elementos para c1 até que -1 seja digitado
    printf("conjunto c1 (-1):\n");
    while (1) {
        scanf("%d", &elemento);
        if (elemento == -1) break; // Sai do loop se -1 for digitado
        adicionarElemento(&c1, elemento); // Adiciona o elemento a c1
    }

    // Insere elementos para c2 até que -1 seja digitado
    printf("conjunto c2 (-1):\n");
    while (1) {
        scanf("%d", &elemento);
        if (elemento == -1) break; // Sai do loop se -1 for digitado
        adicionarElemento(&c2, elemento); // Adiciona o elemento a c2
    }

    // Encontra a interseção de c1 e c2 e armazena em c3
    c3 = intersecao(&c1, &c2);

    // Imprime os conjuntos c1, c2 e a interseção c3
    printf("c1: ");
    imprimirConjunto(&c1);

    printf("c2: ");
    imprimirConjunto(&c2);

    printf("(c1 e c2): ");
    imprimirConjunto(&c3);

    return 0;
}
