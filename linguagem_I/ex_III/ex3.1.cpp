#include <stdio.h>

int main() {
    int vet1[3];
    int soma = 0;

    scanf("%d", &vet1[0]);
    scanf("%d", &vet1[1]);
    scanf("%d", &vet1[2]);

    soma = vet1[0] + vet1[1] + vet1[2];

    printf("%d", soma);
    
    
    return 0;
    }
