#include <stdio.h>
#include <stdlib.h>


int main()
{

int matriz [4] [5];


// solicita os elementos da matriz
printf ("Digite os elementos da matriz [4][5]");

// preenche a matriz com os elementos
for (int linha = 0; linha < 4; linha++)
{
    for (int coluna = 0; coluna <5; coluna++)
    {
        scanf ("%d", &matriz [linha] [coluna]);
    }
}

// verificação e localização dos elentos repetidos 
for (int linha = 0; linha < 4; linha ++)
{
    for (int coluna = 0; coluna < 5; coluna ++)
    {
        int elemento_atual = matriz [linha] [coluna];   // PEGA O ELEMENTO ATUAL DA MATRIZ 

        for (int comparar_linha = 0; comparar_linha < 4; comparar_linha++)
        {
            for (int comparar_coluna = 0; comparar_coluna < 5; comparar_coluna++)       
            {
                if (linha != comparar_linha || coluna != comparar_coluna) // EVITA DE PEGAR O MESMO ELEMENTO ATUAL COMPARANTO COM O RESTO DA MATRIZ 
                {
                    int comparar_elemento = matriz [comparar_linha] [comparar_coluna]; // SE O ELEMENTO NÃO FOR NA MESMA LINHA E COLUNA E FOR IGUAL AO ELEMENTO ATUAL A SER COMPARADO, EXIBE O MESMO
                if (elemento_atual == comparar_elemento)
                {
                    printf ("Elemento %d na posicao [%d][%d] e igual ao elemento %d na posicao [%d][%d]\n",elemento_atual, linha, coluna, comparar_elemento, comparar_linha, comparar_coluna);
                }
                    
                }
            }
            
        }
        
    }
}


}