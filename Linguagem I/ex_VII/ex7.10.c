/*
Um marciano chegou a uma floresta e se escondeu atrás de uma das 100 árvores quando viu um caçador.
O caçador só tinha cinco balas em sua espingarda. Cada vez que ele atirava, e não acertava, é claro,
o marciano dizia: “estou mais à direita ou mais à esquerda. Se o caçador não conseguir acertar o marciano,
ele será levado para marte. Implementar este jogo para dois jogadores, onde um escolhe a árvore em que o
marciano irá se esconder, e o outro tenta acertar. (Sugestão: utilize números para representar as árvores)
*/

#include <stdio.h>
#include <stdlib.h>

int verificarTiro(int alvo, int tiro)
{
    if (tiro == alvo)
    {
        return 0;
    }
    else if (tiro < alvo)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int arvore = 0, tiro = 5, chute;
    int *pArvore, *pTiro, *pChute;

    pArvore = &arvore;
    pTiro = &tiro;
    pChute = &chute;

    printf("Escolha onde o marciano vai se esconder: ");
    scanf("%d", &*pArvore);

    for (int i = 0; i < 50; i++)
    {
        printf("Escondendo...\n");
    }

    while (tiro > 0)
    {
        printf("Onde o marciano está se escondendo? (1-100): ");
        scanf("%d", &*pChute);

        int resultado = verificarTiro(*pArvore, *pChute);

        if (resultado == 0)
        {
            printf("Parabéns! Você acertou o marciano.\n");
            break;
        }
        else if (resultado == -1)
        {
            printf("O marciano está mais à direita.\n");
        }
        else
        {
            printf("O marciano está mais à esquerda.\n");
        }

        tiro--;
        printf("Tentativas restantes: %d\n", tiro);
    }

    if (tiro == 0)
    {
        printf("Você não conseguiu acertar o marciano. Ele será levado para Marte.\n");
    }

    return 0;
}