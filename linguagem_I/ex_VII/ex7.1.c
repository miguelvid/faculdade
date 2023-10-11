
/* Faca um programa que leia um valor inteiro fornecido pelo usuario. Mostre o endereco de memoria dessa variavel e o seu conteudo. */

#include <stdio.h>

int main(){
    int x;
    
    printf("Digite um valor:");
    scanf("%d", &x);
    printf("Endereco de memoria de x: %p\n", &x);
    printf("Conteudo de x: %d", &x);

    return 0;
}

