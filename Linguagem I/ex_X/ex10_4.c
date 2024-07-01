/*
Escreva um programa que simule o lançamento de uma moeda. Para cada
lançamento de moeda o programa deve imprimir CARA ou COROA. Deixe o
programa lançar 100 moedas e conte o número de vezes que cada lado aparece.
Imprima os resultados. O programa deve chamar uma função separada chamada jogada
que não tiliza argumentos e retorna 0 para cara e 1 para coroa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Moeda() {
    return rand() % 2;
}

int main() {
    int cara = 0;
    int coroa = 0;
    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        int resultado = Moeda();
        if (resultado == 0) {
            printf("CARA\n");
            cara++;
        } else {
            printf("COROA\n");
            coroa++;
        }
    }

    printf("\nResultado:\n");
    printf("CARA apareceu %d vezes.\n", cara);
    printf("COROA apareceu %d vezes.\n", coroa);

    return 0;
}