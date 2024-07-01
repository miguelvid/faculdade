/* Escreva um programa que leia a altura e o raio de um cilindro circular.
A seguir crie ponteiros e aponte eles para cada uma dessas variaveis.
Utilizando esses ponteiros imprima o volume do cilindro,
segundo a fórmula: volume = pi * (raio * raio) * altura, onde pi = 3.14 */

#include <stdio.h>
#include <math.h>

int main() {
    double altura, raio;
    double *pA, *pR;
    double pi = 3.14159265359;  // só pra fazer charme

    pA = &altura;
    pR = &raio;

    printf("Digite a altura do cilindro: ");
    scanf("%lf", &altura);
    printf("Digite o raio do cilindro: ");
    scanf("%lf", &raio);

    double volume = pi * (*pR * *pR) * *pA;

    printf("Volume do cilindro: %lf\n", volume);

    return 0;
}