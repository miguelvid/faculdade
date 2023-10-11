
/* Faça um algoritmo que leia um nº inteiro. Crie um ponteiro
apontando para essa variavel e utilizando ele mostre uma mensagem
indicando se o conteudo apontado pelo ponteiro (valor lido) é par ou ímpar 
e se é positivo ou negativo. */

#include <stdio.h>

int main() {
    int v1;
    int *p1;
    
    printf("Digite um valor:");
    scanf("%d", &v1);
    p1 = &v1;

    if (*p1 % 2 == 0) {
        printf("p1--> v1(%d): par.\n", *p1);
    
    } else {
        printf("p1--> v1(%d): impar.\n", *p1);
    
    }

    if (*p1 > 0) {
        printf("p1--> v1(%d): positivo.\n", *p1);
    
    } else if (*p1 < 0) {
        printf("p1--> v1(%d): negativo.\n", *p1);
    
    } else {
        printf("p1--> v1(%d): zero(neutro).\n", *p1);
        
    }

    return 0;
}
