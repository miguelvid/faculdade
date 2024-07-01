#include <stdio.h>

int main()
{
    int contador = 0;
    float salarioAtual = 0.0, reajustes[3] = {0.07, 0.06, 0.05};

    scanf("%f", &salarioAtual);

    while (contador < 3)
    {
        salarioAtual *= ((1 + reajustes[contador]));
        printf("Salario mensal para o ano %d: %.2f\n", (contador+1), salarioAtual);
        contador++;
    }

    return 0;
}