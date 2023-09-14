#include <stdio.h>

int main() 
{
int matriz[15][15];
int contador[15][15] = {0}; 

printf("Digite os elementos da matriz [15][15]:\n");
for (int linha = 0; linha < 15; linha++) 
{
    for (int coluna = 0; coluna < 15; coluna++) 
    {
        scanf("%d", &matriz[linha][coluna]);
    }
}

for (int linha_atual = 0; linha_atual < 15; linha_atual++) 
{
    for (int coluna_atual = 0; coluna_atual < 15; coluna_atual++) 
    {
        int elemento_atual = matriz[linha_atual][coluna_atual];
        contador[linha_atual][coluna_atual] = 1;

        for (int linha_comparar = linha_atual; linha_comparar < 15; linha_comparar++) 
        {
            for (int coluna_comparar = (linha_comparar == linha_atual ? coluna_atual + 1 : 0); coluna_comparar < 15; coluna_comparar++) 
            {
                if (matriz[linha_comparar][coluna_comparar] == elemento_atual) 
                {
                    contador[linha_atual][coluna_atual]++;
                    contador[linha_comparar][coluna_comparar]++;
                }
            }
        }
    }
}

printf("Elementos repetidos e suas contagens:\n");
for (int linha = 0; linha < 15; linha++) 
{
    for (int coluna = 0; coluna < 15; coluna++) 
    {
        if (contador[linha][coluna] > 1)
        {
            printf("%d aparece %d vezes\n", matriz[linha][coluna], contador[linha][coluna]);
        }
    }
}

    return 0;
}
