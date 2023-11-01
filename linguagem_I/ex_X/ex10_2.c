/*
Escreva uma função que retorne o menor número entre dois
números ponto flutuante fornecidos pelo usuário. 
*/

#include <stdio.h>

float Retorno(float num1, float num2) {
    if (num1 < num2) {
        return num1;
    } else {
        return num2;
    }
}

int main() {
    float numero1, numero2;

    printf("Digite: ");
    scanf("%f", &numero1);

    printf("Digite: ");
    scanf("%f", &numero2);

    float menor = Retorno(numero1, numero2);

    printf("Menor n: %.2f\n", menor);

    return 0;
}
