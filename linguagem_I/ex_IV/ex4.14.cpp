#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    int main() {
        srand(time(NULL));
        int arvore= rand() % 100 + 1;
        int tiro;

        for (int i = 0; i < 5; i++)
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
             printf("CONGRATULATIONS, VOCE ACERTOU\n");
        }
        }
         printf("Ele estava na arvore: %d\n", arvore);
        








    return 0;
}