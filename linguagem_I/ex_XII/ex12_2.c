/*
Um comerciante deseja armazenar o nome e o valor de 10 produtos de seu estabelecimento.
Monte um array de structs para armazena-los
*/

#include <stdio.h>
#include <stdlib.h>

// Definição da struct Produto
struct Produto
{
    char nome[50];
    float valor;
};

int main()
{
    // Declaração do array de structs para armazenar os produtos
    struct Produto produtos[10];

    // Loop para ler os dados de cada produto
    for (int i = 0; i < 10; i++)
    {
        printf("Digite o nome do produto %d: ", i + 1);
        scanf("%s", produtos[i].nome);

        printf("Digite o valor do produto %d: ", i + 1);
        scanf("%f", &produtos[i].valor);
    }

    // Imprimir os dados dos produtos
    printf("\nProdutos Armazenados:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Produto %d:\n", i + 1);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Valor: R$%.2f\n", produtos[i].valor);
        printf("\n");
    }

    return 0;
}