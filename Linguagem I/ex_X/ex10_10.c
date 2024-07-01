/*
Fazer um programa que leia um valor e chame uma função para dizer se o número
é primo ou não. O programa deverá ser finalizado quando o valor 0 (zero) for digitado.
Garanta que o número lido é positivo ou zero.
*/

#include <stdio.h>
#include <math.h>

int verPrimo(int num) {
    if (num <= 1) {
        return 0;
    }

    if (num <= 3) {
        return 1; 
    }

    if (num % 2 == 0 || num % 3 == 0) {
        return 0;
    }

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return 0;
        }
    }

    return 1; 
}

int main() {
    int num;

    while (1) {
        printf("Digite: ");
        scanf("%d", &num);

        if (num == 0) {
            break;
        }

        if (num < 0) {
            printf("digite um numeropositivo ou zero.\n");
        } else {
            if (verPrimo(num)) {
                printf("%d Primo.\n", num);
            } else {
                printf("%d NAO primo.\n", num);
            }
        }
    }

    return 0;
}
