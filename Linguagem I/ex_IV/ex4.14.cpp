#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    int main() {
        srand(time(NULL));
        int arvore= rand() % 100 + 1; // só tem eu aqui então coloquei pra dar um numero aleatorio.
        int tiro;

        printf("tente matar o alienigena atras das arvores, voce tem 5 balas CUIDADO!");
        for (int i = 0; i < 6; i++)
        {
           scanf("%d", &tiro);
           if (tiro > arvore)
        {
            printf("VOCE ERROU, atire mais para esquerda\n");
        }
        else if (tiro < arvore)
        {
             printf("VOCE ERROU, atire mais para direita\n");
        }
        else if (tiro == arvore) 
        {
             printf("CONGRATULATIONS, voce matou o alien\n");
              break; 
        }
        }
         printf("Ele estava na arvore: %d\n", arvore);

    return 0;
}