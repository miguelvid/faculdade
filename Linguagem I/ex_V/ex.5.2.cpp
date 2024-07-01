#include <stdio.h>

int main() {
    int v1[10], v2[10], result[20];
    int i, j, k;

    printf("elementos do v1 (ordenado):\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &v1[i]);
    }

    printf("elementos do v2 (ordenado):\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &v2[i]);
    }


    i = 0;
    j = 0;
    k = 0;

    while (i < 10 && j < 10) {
        if (v1[i] < v2[j]) {
            result[k++] = v1[i++];
        } else {
            result[k++] = v2[j++];
        }
    }

    while (i < 10) {
        result[k++] = v1[i++];
    }

    while (j < 10) {
        result[k++] = v2[j++];
    }

    printf("Vetor resultante:\n");
    for (i = 0; i < 20; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}