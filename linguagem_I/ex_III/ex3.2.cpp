#include <stdio.h>

int main() {
    int x1, x2;
    int soma;

    scanf("%d", &x1);
    scanf("%d", &x2);

    soma = x1 + x2;

    if (soma % 2 == 0) {
        
        printf("%d", soma);
        printf("numero par\n");

    }
    else {
        
        printf("%d", soma);
        printf("numero impar\n");

    }
    

    
    return 0;
    }
