#include <stdio.h>

int main() {
    int num1, num2, num3;
    
    scanf("%d", &num1);
    
    scanf("%d", &num2);
    
    scanf("%d", &num3);
    
    int maior = num1;
    if (num2 > maior) {
        maior = num2;
    }
    if (num3 > maior) {
        maior = num3;
    }
    int menor = num1;
    if (num2 < menor) {
        menor = num2;
    }
    if (num3 < menor) {
        menor = num3;
    }
    
    double media = (num1 + num2 + num3) / 3.0;
    
    printf("O maior: %d\n", maior);
    printf("O menor: %d\n", menor);
    
    if (num2 > media) {
        printf("O do meio e maior que a media.\n");
    } else if (num2 < media) {
        printf("O do meio e menor que a media.\n");
    } else {
        printf("O  meio e igual a media.\n");
    }
    
    return 0;
}