/*
Criar uma função que converta uma temperatura dada em Fahrenheit em Celsius.
A temperatura é passada como parâmetro para uma função que retorna a temperatura
em Celsius, que deve ser mostrada no programa principal. A fórmula para cálculo
é C = ( F - 32 ) * 5 / 9.
*/

#include <stdio.h>

float Converter(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

int main() {
    float fahrenheit, celsius;

    printf("temp em Fahrenheit: ");
    scanf("%f", &fahrenheit);

    celsius = Converter(fahrenheit);

    printf("%.2fF = %.2fC.\n", fahrenheit, celsius);

    return 0;
}
