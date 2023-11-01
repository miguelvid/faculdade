/*
Aloque de forma dinamica um array bidimensional com o numero de posicoes fornecidas pelo usuario.
Preencha esse array com valores randomicos (utilize a função rand() ). A seguir utilizando ponteiros
mostre o conteudo desse array. Nao esqueca de liberar o espaco alocado em memoria.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **alocaArrayBidimensional(int linhas, int colunas)
{
    int **array = (int **)malloc(linhas * sizeof(int *));

    for (int i = 0; i < linhas; i++)
    {
        array[i] = (int *)malloc(colunas * sizeof(int));
    }

    return array;
}

void preencheArrayRandomico(int **array, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            array[i][j] = rand() % 100;
        }
    }
}

void mostraConteudo(int **array, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void liberaMemoria(int **array, int linhas)
{
    for (int i = 0; i < linhas; i++)
    {
        free(array[i]);
    }
    free(array);
}

int main()
{
    int linhas, colunas;

    printf("Digite o número de linhas: ");
    scanf("%d", &linhas);

    printf("Digite o número de colunas: ");
    scanf("%d", &colunas);

    srand(time(NULL));

    int **array = alocaArrayBidimensional(linhas, colunas);
    preencheArrayRandomico(array, linhas, colunas);
    mostraConteudo(array, linhas, colunas);
    liberaMemoria(array, linhas);

    return 0;
}
