/*
Escreva uma funcao que receba dois inteiros e armazene-os em uma estrutura (campos x e y).
A seguir copie essa estrutura para uma segunda estutura. Mostre essa segunda estrutura
*/

#include <stdio.h>

// Definição da struct Ponto
struct Ponto
{
    int x;
    int y;
};

// Função para armazenar dois inteiros em uma estrutura
void armazenarValores(struct Ponto *p, int valor1, int valor2)
{
    p->x = valor1;
    p->y = valor2;
}

// Função para copiar uma estrutura para outra
void copiarEstrutura(struct Ponto *destino, struct Ponto origem)
{
    destino->x = origem.x;
    destino->y = origem.y;
}

// Função para imprimir os valores de uma estrutura
void imprimirEstrutura(struct Ponto p)
{
    printf("Valores da Estrutura:\n");
    printf("x: %d\n", p.x);
    printf("y: %d\n", p.y);
}

int main()
{
    // Declaração de duas estruturas
    struct Ponto ponto1, ponto2;

    // Chamando a função para armazenar valores na primeira estrutura
    armazenarValores(&ponto1, 10, 20);

    // Chamando a função para copiar a primeira estrutura para a segunda
    copiarEstrutura(&ponto2, ponto1);

    // Imprimindo os valores da segunda estrutura
    imprimirEstrutura(ponto2);

    return 0;
}