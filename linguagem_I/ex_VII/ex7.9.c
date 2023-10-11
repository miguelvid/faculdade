/* Infelizmente o algoritmo que calcula o valor do táxi tem as variáveis tempo e distância,
ou seja, mesmo que o carro esteja parado em um sinal, a conta do taxi vai aumentando.
Faça um programa que dado o tempo e a distância, calcule o valor a ser pago. O custo
é 0,02centavos por segundo e R$ 1,00 por quilômetro. Atenção: você já implementou esse programa antes,
porém agora TODAS AS VARIÁVEIS devem ser manipuladas usando ponteiros */

#include <stdio.h>
#include <stdlib.h>

int main()
{


    float tempo = 0;
    float distancia = 0;
    float valor = 0;

    float *ponteirotempo = &tempo;
    float *ponteirodistancia = &distancia;
    float *ponteirovalor = &valor;

    printf("Digite o tempo da viagem em segundos: \n");
    scanf("%f", &tempo);
    printf("Digite a distancia da viagem em km: \n");
    scanf("%f", &distancia);

    if (distancia < 1)
    {
        printf("Distancia menor que um kilometro nao sera calculada");
        distancia = 0;
    }

    *ponteirotempo = (*ponteirotempo) * (0.02);
    *ponteirodistancia = (*ponteirodistancia) * (1.00);
    *ponteirovalor = *ponteirotempo + *ponteirodistancia;

    printf("O valor que sera pago na viagem e de: %.2f\n", *ponteirovalor);

    return 0;
}