#include <stdio.h>
#include "ponto.h"

int main() {
    ponto p1, p2;
    float x, y;

    printf("Coordenadas Ponto 1 (x y): ");
    scanf("%f %f", &x, &y);

    setx(&p1, x);
    sety(&p1, y);

    printf("Coordenadas Ponto 2 (x y): ");
    scanf("%f %f", &x, &y);

    setponto(&p2, x, y);

    printf("\nPonto 1: (%.2f, %.2f)\n", getx(&p1), gety(&p1));
    printf("Ponto 2: (%.2f, %.2f)\n", getx(&p2), gety(&p2));

    // Mostrar a distância do Ponto 1 da Origem
    printf("\nDistancia do Ponto 1 da Origem: %.2f\n", ponto_origem(&p1));

    // Mostrar a distância entre os dois pontos
    printf("Distancia entre os dois pontos: %.2f\n", ponto_distancia(&p1, &p2));

    return 0;
}