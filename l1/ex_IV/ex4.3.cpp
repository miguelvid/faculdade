#include <stdio.h>

int main() {
    int numero;

    scanf("%d", &numero);

    if (numero < 0) {
        printf("ERRO\n");
    } else {
        int fatorial = 1;

        for (int i = 2; i <= numero; i++) {
            fatorial *= i;
        }

        printf("%d! = %d\n", numero, fatorial);
    }

    return 0;
}