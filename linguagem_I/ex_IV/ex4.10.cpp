#include <stdio.h>

int main() {
    int num[20];
    int somaPos  = 0;
    int totalNeg = 0;

    

    for (int i = 0; i < 20; i++) {
        printf("numero %d: ", i + 1);
        scanf("%d", &num[i]);
    }

    for (int i = 0; i < 20; i++) {
        if (num[i] > 0) {
            somaPos += num[i];
        } else if (num[i] < 0) {
            totalNeg++;
        }
    }

    printf("soma positivos: %d\n", somaPos);
    printf("total negativos: %d\n", totalNeg);

    return 0;
}