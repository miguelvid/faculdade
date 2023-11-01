/*
Elaborar uma função para ler a base e a altura de um retângulo, calcular
e retornar a sua área. Na função principal é apresentado o valor dessa área.
Fórmula: Area = base * altura
*/

#include <stdio.h>

float calculaArea(float base, float altura) {
    return base * altura;
}

int main() {
    float base, altura, area;

    printf("Digite a base do retangulo: ");
    scanf("%f", &base);

    printf("Digite a altura do retangulo: ");
    scanf("%f", &altura);

    area = calculaArea(base, altura);

    printf("A area: %.2f\n", area);

    return 0;
}