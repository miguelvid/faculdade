#include <stdio.h>

int main() {
    int valores[20];
    int produtoImpares = 1;
    int somaPares = 0;

    for (int i = 0; i < 20; i++) {
        printf("valor %d: ", i + 1);
        scanf("%d", &valores[i]);
    }

    for (int i = 0; i < 20; i++) {
        if (valores[i] % 2 == 0) {
            somaPares += valores[i];
        } else {
            produtoImpares *= valores[i];
        }
    }

    printf("produto impar: %d\n", produtoImpares);
    printf("soma par: %d\n", somaPares);

    return 0;
}