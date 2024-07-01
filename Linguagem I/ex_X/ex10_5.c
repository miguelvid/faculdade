/*
Escreva um programa que faça o jogador "adivinhar um número" da forma como segue: Seu programa escolhe um número para ser adivinhado selecionando um inteiro entre 0 e 50. O programa então escreve:

Tenho um número de 0 a 50
Voce pode adivinhar meu número ?
Por favor digite seu palpite

O jogador digita então o primeiro palpite. O programa fornece uma das seguintes respostas:

1 - Excelente! Voce adivinhou o número
2 - Muito baixo. Tente novamente
3- Muito alto. Tente novamente

Se o palpite do jogar estive errado o programa deve fazer um loop até que o jogador acerte o número. Seu programa deve continuar dizendo muito alto ou muito baixo para ajudar o jogador a chegar a uma resposta. Obrigatoriamente voce deve utilizar funções.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int NumbAleatorio() {
    return rand() % 51;
}

void Verificador(int numero, int palpite) {
    if (palpite == numero) {
        printf("Excelente! Voce adivinhou o numero.\n");
    } else if (palpite < numero) {
        printf("Muito baixo. Tente novamente.\n");
    } else {
        printf("Muito alto. Tente novamente.\n");
    }
}

int main() {
    srand(time(NULL)); 
    int numeroAleatorio = NumbAleatorio();
    int palpite;

    printf("Tenho um numero de 0 a 50\n");
    printf("Voce pode adivinhar meu numero?\n");
    printf("Por favor, digite seu palpite: ");
    do {
        scanf("%d", &palpite);
        Verificador(numeroAleatorio, palpite);
    } while (palpite != numeroAleatorio);

    return 0;
}
