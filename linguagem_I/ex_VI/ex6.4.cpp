#include <stdio.h>

int main() {
    int valor1, valor2, resultado;

    printf("Digite o primeiro valor: ");
    scanf("%d", &valor1);

    printf("Digite o segundo valor: ");
    scanf("%d", &valor2);
  
    resultado = valor1 + valor2;
 
    printf("Resultado: %10d\n", resultado);

    return 0;
}