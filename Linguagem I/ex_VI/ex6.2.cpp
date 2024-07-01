//Faça um programa que leia um valor do usuário e mostre o seu resultado em hexadecimal//

#include <stdio.h>

int main() {

    int valor;

    printf("Digite: ");
    scanf("%d", &valor);

    printf("%X\n", valor); // OBS:%X mostra valor em hexadecimal



    return 0;
}