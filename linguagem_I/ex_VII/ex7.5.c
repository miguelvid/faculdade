/* Faca um programa que leia dois valores x e y e entao
inverta os valores dessas variaveis ( x recebe y e y recebe x)
usando ponteiros */

#include <stdio.h>

int main() {
    int x, y, troc;
    int *px, *py;

    printf("Digite o valor de x: ");
    scanf("%d", &x);
    printf("Digite o valor de y: ");
    scanf("%d", &y);

    px = &x;
    py = &y;
    troc = *px;
    *px = *py;
    *py = troc;

    


    printf("px = %d e py = %d\n", *px, *py);
    printf("x = %d e y = %d\n", x, y);

    return 0;
}